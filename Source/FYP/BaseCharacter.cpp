// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "BaseCharacter.h"
#include "Animation/AnimInstance.h"
#include "PickUpActor.h"
#include "LifePickUpActor.h"


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
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GunBlueprint == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint missing."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint loaded."));
		Weapon = GetWorld()->SpawnActor<AWeaponActor>(GunBlueprint);
		bool gripPoint = FPSMesh->DoesSocketExist("GripPoint");
		if(!gripPoint)
		{
			UE_LOG(LogTemp, Warning, TEXT("GripPoint missing"));
		}
		Weapon->AttachToComponent(FPSMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
		
		//Weapon->AnimInstance = FPSMesh->GetAnimInstance();
	}
}

// Called every frame
void ABaseCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	CollectPickups();
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
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ABaseCharacter::StopJump);

	// Set up "reload" bindings
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ABaseCharacter::OnReload);

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

float ABaseCharacter::GetInitialLife() const
{
	return InitialLife;
}

float ABaseCharacter::GetCurrentLife() const
{
	return CurrentLife;
}

void ABaseCharacter::UpdateLife(float LifeDelta)
{
	float TempLife = CurrentLife + LifeDelta;
	float NewValue;
	if(LifeDelta > 0)
	{
		NewValue = TempLife > InitialLife? InitialLife : TempLife;
	}
	else
	{
		NewValue = TempLife < 0 ? 0 : TempLife;
	}
	CurrentLife = NewValue;
}

void ABaseCharacter::OnReload()
{
	UE_LOG(LogTemp, Warning, TEXT("Reloading"));
	if(Weapon->GetCanReload())
	{
		UAnimMontage* reloadAnimation = Weapon->Reload();
		if(reloadAnimation != nullptr)
		{
			UAnimInstance* AnimInstance = FPSMesh->GetAnimInstance();
			if (AnimInstance != nullptr)
			{
				AnimInstance->Montage_Play(reloadAnimation, 1.f);
			}
		}
	}
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
	UpdateLife(CollectedLife);
}
