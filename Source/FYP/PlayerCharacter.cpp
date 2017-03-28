// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "PlayerCharacter.h"
#include "LifePickUpActor.h"
#include "UserWidget.h"
#include "GamePlayPlayerController.h"
#include "UsableActor.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"


APlayerCharacter::APlayerCharacter()
{

	// Create a first person mesh component for the owning player.
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	// Only the owning player sees this mesh.
	FPSMesh->SetOnlyOwnerSee(true);
	// Attach the FPS mesh to the FPS camera.
	FPSMesh->AttachTo(FPSCameraComponent);
	// Disable some environmental shadowing to preserve the illusion of having a single mesh.
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	// Create collection sphere
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->AttachTo(RootComponent);
	CollectionSphere->SetSphereRadius(200);
}

void APlayerCharacter::CollectPickups()
{
	// Get all overlapping actors store them in array
	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);
	// keep track of collected life
	float CollectedLife = 0.0f;
	// For each actor we collect
	for (int32 iCollected = 0; iCollected < CollectedActors.Num(); iCollected++)
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
			if (TestLife)
			{
				// Increase collected power
				CollectedLife += TestLife->GetLife();
			}
			// Deactivate the pickup 
			TestPickup->SetActive(false);
		}
	}
	if (CollectedLife > 0.0f)
	{
		ABaseCharacter* BCOwner = Cast<ABaseCharacter>(GetOwner());
		DamagePlayer(-CollectedLife, BCOwner);
	}
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	// The owning player doesn't see the regular (third-person) body mesh.
	GetMesh()->SetOwnerNoSee(true);
	if (WeaponBlueprint != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint loaded."));
		Weapon = GetWorld()->SpawnActor<AWeaponActor>(WeaponBlueprint);
		Weapon->SetOwner(this);
		bool gripPoint = FPSMesh->DoesSocketExist("GripPoint");
		if (!gripPoint)
		{
			UE_LOG(LogTemp, Warning, TEXT("GripPoint missing"));
		}
		Weapon->AttachToComponent(FPSMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
		Weapon->AnimInstance = FPSMesh->GetAnimInstance();
		Weapon->SetOwnerOnlySee(true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint missing!!!!! FPS"));
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	// Set up "look" bindings.
	PlayerInputComponent->BindAxis("LookRight", this, &APlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);

	// Set up "action" bindings.
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump);

	// Set up "fire" bindings
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::Fire);

	// Set up "reload" bindings
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &APlayerCharacter::OnReload);

	// Set up "use" bindings
	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &APlayerCharacter::Use);

	PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &APlayerCharacter::Pause);

}

void APlayerCharacter::MoveForward(float Value)
{
	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void APlayerCharacter::MoveRight(float Value)
{
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void APlayerCharacter::StartJump()
{
	bPressedJump = true;
}

void APlayerCharacter::StopJump()
{
	bPressedJump = false;
}

void APlayerCharacter::DestroyWeapon()
{
	Super::DestroyWeapon();
	if (Weapon)
	{
		Weapon->Destroy();
	}
}

AWeaponActor* APlayerCharacter::GetWeapon()
{
	return Weapon;
}

UAnimInstance* APlayerCharacter::GetArmsAnimInstance()
{
	return FPSMesh->GetAnimInstance();
}

/*
Runs on Server. Perform "OnUsed" on currently viewed UsableActor if implemented.
*/
void APlayerCharacter::Use_Implementation()
{
	AUsableActor* usable = GetUsableInView();
	if (usable)
	{
		usable->OnUsed(this);
	}
}

bool APlayerCharacter::Use_Validate()
{
	// No special server-side validation performed.
	return true;
}


AUsableActor* APlayerCharacter::GetUsableInView() const
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


UCameraComponent* APlayerCharacter::GetCamera() const
{
	return FPSCameraComponent;
}