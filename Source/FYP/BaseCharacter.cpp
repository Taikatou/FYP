// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "BaseCharacter.h"
#include "Animation/AnimInstance.h"
#include "PickUpActor.h"
#include "LifePickUpActor.h"
#include "UsableActor.h"
#include "Animation/AnimMontage.h"
#include "Target.h"
#include "Kismet/KismetMathLibrary.h"
#include "UnrealNetwork.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "GamePlayPlayerController.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create a first person camera component.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	// Attach the camera component to our capsule component.
	FPSCameraComponent->AttachTo(GetCapsuleComponent());
	// Position the camera slightly above the eyes.
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// Allow the pawn to control camera rotation.
	FPSCameraComponent->bUsePawnControlRotation = true;

	// Create a first person mesh component for the owning player.
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	// Only the owning player sees this mesh.
	FPSMesh->SetOnlyOwnerSee(true);
	// Attach the FPS mesh to the FPS camera.
	FPSMesh->AttachTo(FPSCameraComponent);
	// Disable some environmental shadowing to preserve the illusion of having a single mesh.
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	// The owning player doesn't see the regular (third-person) body mesh.
	GetMesh()->SetOwnerNoSee(true);

	// Create collection sphere
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->AttachTo(RootComponent);
	CollectionSphere->SetSphereRadius(200);

	// Set current life level for the character
	CurrentLife = InitialLife;

	CurrentlyReloading = false;

	bReplicates = true;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (WeaponBlueprint == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint missing."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint loaded."));
		Weapon = GetWorld()->SpawnActor<AWeaponActor>(WeaponBlueprint);
		Weapon->SetOwner(this);
		bool gripPoint = FPSMesh->DoesSocketExist("GripPoint");
		if(!gripPoint)
		{
			UE_LOG(LogTemp, Warning, TEXT("GripPoint missing"));
		}
		Weapon->AttachToComponent(FPSMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
		Weapon->AnimInstance = FPSMesh->GetAnimInstance();
	}
	if (wMainMenu) // Check if the Asset is assigned in the blueprint.
	{
		AGamePlayPlayerController* controller = Cast<AGamePlayPlayerController>(GetController());
		if(controller)
		{
			// Create the widget and store it.
			MyMainMenu = CreateWidget<UUserWidget>(controller, wMainMenu);
		}
	}
}

// Called every frame
void ABaseCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	CollectPickups();
	if (Controller && Controller->IsLocalController())
	{
		AUsableActor* usable = GetUsableInView();

		// End Focus
		if (FocusedUsableActor != usable)
		{
			if (FocusedUsableActor)
			{
				FocusedUsableActor->EndFocusItem();
			}

			bHasNewFocus = true;
		}

		// Assign new Focus
		FocusedUsableActor = usable;

		// Start Focus.
		if (usable)
		{
			if (bHasNewFocus)
			{
				usable->StartFocusItem();
				bHasNewFocus = false;
			}
		}
	}
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

	// Set up "look" bindings.
	PlayerInputComponent->BindAxis("LookRight", this, &ABaseCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ABaseCharacter::AddControllerPitchInput);

	// Set up "action" bindings.
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ABaseCharacter::StopJump);

	// Set up "fire" bindings
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ABaseCharacter::Fire);

	// Set up "reload" bindings
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ABaseCharacter::OnReload);

	// Set up "use" bindings
	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &ABaseCharacter::Use);

	PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &ABaseCharacter::Pause);

}

void ABaseCharacter::MoveForward(float Value)
{
	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void ABaseCharacter::MoveRight(float Value)
{
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ABaseCharacter::StartJump()
{
	bPressedJump = true;
}

void ABaseCharacter::StopJump()
{
	bPressedJump = false;
}

/*
Runs on Server. Perform "OnUsed" on currently viewed UsableActor if implemented.
*/
void ABaseCharacter::Use_Implementation()
{
	AUsableActor* usable = GetUsableInView();
	if (usable)
	{
		usable->OnUsed(this);
	}
}

bool ABaseCharacter::Use_Validate()
{
	// No special server-side validation performed.
	return true;
}


float ABaseCharacter::GetInitialLife() const
{
	return InitialLife;
}

float ABaseCharacter::GetCurrentLife() const
{
	return CurrentLife;
}

UCameraComponent* ABaseCharacter::GetCamera() const
{
	return FPSCameraComponent;
}

bool ABaseCharacter::DamagePlayer_Validate(float LifeDelta)
{
	return true;
}

void ABaseCharacter::DamagePlayer_Implementation(float LifeDelta)
{
	if(PlayerAlive)
	{
		float TempLife = CurrentLife - LifeDelta;
		if (TempLife < 0)
		{
			TempLife = 0;
		}
		else if (TempLife > InitialLife)
		{
			TempLife = InitialLife;
		}
		CurrentLife = TempLife;
		if (CurrentLife == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("player died, %f"), CurrentLife);
			PlayerAlive = false;
			OnDeath();
		}
	}
}

void ABaseCharacter::OnReload()
{
	UE_LOG(LogTemp, Warning, TEXT("Reloading"));
	CurrentlyReloading = true;
	UAnimMontage* reloadAnimation = Weapon->Reload();
	if (reloadAnimation != nullptr)
	{
		UAnimInstance* AnimInstance = FPSMesh->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(reloadAnimation, 1.f);

			GetWorld()->GetTimerManager().SetTimer(AnimationTimerHandle, this, &ABaseCharacter::Reloaded, 2.0f, false);
		}
	}
}

void ABaseCharacter::Fire()
{
	if(!CurrentlyReloading && Controller != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fire"));
		FRotator SpawnRotation = GetControlRotation();

		// Fire Weapon
		UAnimMontage* fireAnimation = Weapon->FireWeapon(SpawnRotation, Controller, FPSCameraComponent, GetSpawnLocation());
		if (fireAnimation != nullptr)
		{
			UAnimInstance* AnimInstance = FPSMesh->GetAnimInstance();
			if (AnimInstance != nullptr)
			{
				AnimInstance->Montage_Play(fireAnimation, 1.f);

				GetWorld()->GetTimerManager().SetTimer(AnimationTimerHandle, this, &ABaseCharacter::Reloaded, 2.0f, false);
			}
		}
	}
}

void ABaseCharacter::Reloaded()
{
	CurrentlyReloading = false;
	UE_LOG(LogTemp, Warning, TEXT("Reloading complete"));
}

void ABaseCharacter::CollectPickups()
{
	// Get all overlapping actors store them in array
	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);
	// keep track of collected life
	float CollectedLife = 0.0f;
	// For each actor we collect
	for(int32 iCollected = 0; iCollected < CollectedActors.Num(); iCollected++)
	{
		// Cast as PickUpActor
		APickUpActor* const TestPickup = Cast<APickUpActor>(CollectedActors[iCollected]);
		// If cast successful and the pickup is valid and active
		if (TestPickup && !TestPickup->IsPendingKill() && TestPickup->IsActive())
		{
			// Call pickup was collected function
			TestPickup->WasCollected();
			// Check if pickup is life
			ALifePickUpActor* const TestLife = Cast<ALifePickUpActor>(TestPickup);
			if(TestLife)
			{
				// Increase collected power
				CollectedLife += TestLife->GetLife();
			}
			// Deactivate the pickup 
			TestPickup->SetActive(false);
		}
	}
	if(CollectedLife > 0.0f)
	{
		DamagePlayer(CollectedLife);
	}
}

int32 ABaseCharacter::GetMaxAmmo() const
{
	return Weapon->MaxCapacity;
}

int32 ABaseCharacter::GetCurrentAmmo() const
{
	return Weapon->GetCurrentCapacity();
}

FVector ABaseCharacter::GetSpawnLocation()
{
	FRotator SpawnRotation = GetControlRotation();
	return Weapon->GetSpawnLocation(SpawnRotation);
}

void ABaseCharacter::SetKillStreak(int32 value)
{
	KillStreak = value;
}

int32 ABaseCharacter::GetKillStreak() const
{
	return KillStreak;
}

void ABaseCharacter::SetTotalKills(int32 value)
{
	TotalKills = value;
}

int32 ABaseCharacter::GetTotalKills() const
{
	return TotalKills;
}

void ABaseCharacter::Pause()
{
	if (MyMainMenu)
	{
		//let add it to the view port
		MyMainMenu->AddToViewport();
	}
}

AUsableActor* ABaseCharacter::GetUsableInView() const
{
	FVector camLoc;
	FRotator camRot;

	if (Controller == nullptr)
	{
		return nullptr;
	}

	Controller->GetPlayerViewPoint(camLoc, camRot);
	const FVector start_trace = camLoc;
	const FVector direction = camRot.Vector();
	const FVector end_trace = start_trace + (direction * MaxUseDistance);

	FCollisionQueryParams TraceParams(FName(TEXT("")), true, this);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.bTraceComplex = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, start_trace, end_trace, COLLISION_PROJECTILE, TraceParams);
	return Cast<AUsableActor>(Hit.GetActor());
}
