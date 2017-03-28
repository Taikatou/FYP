    // Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FPSCharacter.h"
#include "GoogleAnalyticsBlueprintLibrary.h"
#include "Animation/AnimMontage.h"
#include "Animation/AnimInstance.h"
#include "Analytics.h"

AFPSCharacter::AFPSCharacter()
{
	CurrentlyReloading = false;

	// Create a first person camera component.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	// Attach the camera component to our capsule component.
	FPSCameraComponent->AttachTo(GetCapsuleComponent());
	// Position the camera slightly above the eyes.
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// Allow the pawn to control camera rotation.
	FPSCameraComponent->bUsePawnControlRotation = true;
}

void AFPSCharacter::OnReload()
{
	UE_LOG(LogTemp, Warning, TEXT("Reloading"));
	CurrentlyReloading = true;
	UAnimMontage* reloadAnimation = GetWeapon()->Reload();
	if (reloadAnimation != nullptr)
	{
		UAnimInstance* AnimInstance = GetArmsAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(reloadAnimation, 1.f);

			GetWorld()->GetTimerManager().SetTimer(AnimationTimerHandle, this, &AFPSCharacter::Reloaded, 2.0f, false);
		}
	}
}

void AFPSCharacter::FireBlueprint()
{
	Fire();
}

bool AFPSCharacter::Fire_Validate()
{
	return true;
}

void AFPSCharacter::Fire_Implementation()
{
	UGoogleAnalyticsBlueprintLibrary::RecordGoogleEvent(TEXT("Fire"), TEXT("Attempt Fire"), TEXT("Fire"), 1);
	if (!CurrentlyReloading && Controller != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fire"));
		FRotator SpawnRotation = GetControlRotation();

		// Fire Weapon
		UAnimMontage* fireAnimation = GetWeapon()->FireWeapon(SpawnRotation, Controller, FPSCameraComponent, GetSpawnLocation());
		if (fireAnimation != nullptr)
		{
			UAnimInstance* AnimInstance = GetArmsAnimInstance();
			if (AnimInstance != nullptr)
			{
				AnimInstance->Montage_Play(fireAnimation, 1.f);

				GetWorld()->GetTimerManager().SetTimer(AnimationTimerHandle, this, &AFPSCharacter::Reloaded, 2.0f, false);
			}
		}
	}
}

void AFPSCharacter::Reloaded()
{
	CurrentlyReloading = false;
	UE_LOG(LogTemp, Warning, TEXT("Reloading complete"));
}

int32 AFPSCharacter::GetMaxAmmo()
{
	AWeaponActor* Weapon = GetWeapon();
	return Weapon->MaxCapacity;
}

int32 AFPSCharacter::GetCurrentAmmo()
{
	AWeaponActor* Weapon = GetWeapon();
	return Weapon->GetCurrentCapacity();
}

FVector AFPSCharacter::GetSpawnLocation()
{
	FRotator SpawnRotation = GetControlRotation();
	return GetWeapon()->GetSpawnLocation(SpawnRotation);
}

AWeaponActor* AFPSCharacter::GetWeapon()
{
	return Weapon;
}

void AFPSCharacter::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	DestroyWeapon();
}

void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (WeaponBlueprint != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint loaded."));
		Weapon = GetWorld()->SpawnActor<AWeaponActor>(WeaponBlueprint);
		Weapon->SetOwner(this);
		bool gripPoint = GetAttachMesh()->DoesSocketExist("GripPoint");
		if (!gripPoint)
		{
			UE_LOG(LogTemp, Warning, TEXT("GripPoint missing"));
		}
		Weapon->AttachToComponent(GetAttachMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
		Weapon->AnimInstance = GetAttachMesh()->GetAnimInstance();
		Weapon->Tags.Add(FName("Enemy"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint missing!!!!! FPS"));
	}
}

USkeletalMeshComponent* AFPSCharacter::GetAttachMesh()
{
	return GetMesh();
}

UAnimInstance* AFPSCharacter::GetArmsAnimInstance()
{
	return nullptr;
}

void AFPSCharacter::DestroyWeapon()
{
	if (Weapon)
	{
		Weapon->Destroy();
	}
}



