// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "BaseCharacter.h"
#include "Animation/AnimInstance.h"
#include "PickUpActor.h"
#include "Animation/AnimMontage.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "GamePlayPlayerController.h"
#include "GameModePlayerState.h"
#include "WeaponActor.h"
#include "GoogleAnalyticsBlueprintLibrary.h"
#include "Runtime/Analytics/Analytics/Public/Analytics.h"
#include "Runtime/Analytics/Analytics/Public/Interfaces/IAnalyticsProvider.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	CurrentlyReloading = false;
	bReplicates = true;

	// Create a first person camera component.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	// Attach the camera component to our capsule component.
	FPSCameraComponent->AttachTo(GetCapsuleComponent());
	// Position the camera slightly above the eyes.
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// Allow the pawn to control camera rotation.
	FPSCameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	FAnalytics::Get().GetDefaultConfiguredProvider()->StartSession();
	if (ThirdPersonWeaponBlueprint != nullptr && SpawnThirdPersonWeapon)
	{
		VisibleWeapon = GetWorld()->SpawnActor<AWeaponActor>(ThirdPersonWeaponBlueprint);
		VisibleWeapon->SetOwner(this);
		bool gripPoint = GetMesh()->DoesSocketExist("GripPoint");
		if (!gripPoint)
		{
			UE_LOG(LogTemp, Warning, TEXT("GripPoint missing"));
		}
		UE_LOG(LogTemp, Warning, TEXT("Spawn third person weapon"));
		VisibleWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
		VisibleWeapon->SetOwnerNoSee(true);
		VisibleWeapon->Tags.Add(FName("Enemy"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No third person gun"));
	}

	// Set current life level for the character
	CurrentLife = InitialLife;
}

void ABaseCharacter::SetName(FText NewName)
{
	AGamePlayPlayerController* controller = Cast<AGamePlayPlayerController>(GetController());
	if (controller)
	{
		controller->SetName(NewName);
	}
}

FText ABaseCharacter::GetName()
{
	AGamePlayPlayerController* controller = Cast<AGamePlayPlayerController>(GetController());
	if (controller)
	{
		return controller->GetName();
	}
	return FText();
}

bool ABaseCharacter::GetDead() const
{
	return CurrentLife <= 0;
}

float ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	DamagePlayer(DamageAmount, DamageCauser);
	UpdateHealth();
	if(CurrentLife == 0)
	{
		auto Controller = GetGamePlayController();
		if (Controller)
		{
			Controller->BroadcastResetHealth();
		}
	}
	return DamageAmount;
}

void ABaseCharacter::UpdateHealth() const
{
	auto Controller = GetGamePlayController();
	if (Controller)
	{
		Controller->BroadcastUpdateHealth();
	}
}

AWeaponActor* ABaseCharacter::GetWeapon()
{
	return VisibleWeapon;
}

void ABaseCharacter::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	DestroyWeapon();
}

UAnimInstance* ABaseCharacter::GetArmsAnimInstance()
{
	return nullptr;
}


float ABaseCharacter::GetInitialLife() const
{
	return InitialLife;
}

float ABaseCharacter::GetCurrentLife() const
{
	return CurrentLife;
}

bool ABaseCharacter::DamagePlayer_Validate(float LifeDelta, AActor* Killer)
{
	return true;
}

void ABaseCharacter::DamagePlayer_Implementation(float LifeDelta, AActor* Killer)
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
			if(Killer && Killer != this)
			{
				AGamePlayPlayerController* controller = Cast<AGamePlayPlayerController>(GetController());
				if(controller)
				{
					controller->IncrementKills();
				}
			}
			PlayDeathAnimation();
			OnDeath(GetGamePlayController());
			DeathEvent();
		}
	}
}

void ABaseCharacter::OnReload()
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

			GetWorld()->GetTimerManager().SetTimer(AnimationTimerHandle, this, &ABaseCharacter::Reloaded, 2.0f, false);
		}
	}
}

void ABaseCharacter::FireBlueprint()
{
	Fire();
}

bool ABaseCharacter::Fire_Validate()
{
	return true;
}

void ABaseCharacter::Fire_Implementation()
{
	UGoogleAnalyticsBlueprintLibrary::RecordGoogleEvent(TEXT("Fire"), TEXT("Attempt Fire"), TEXT("Fire"), 1);
	if(!CurrentlyReloading && Controller != nullptr)
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

int32 ABaseCharacter::GetMaxAmmo()
{
	AWeaponActor* Weapon = GetWeapon();
	return Weapon->MaxCapacity;
}

int32 ABaseCharacter::GetCurrentAmmo()
{
	AWeaponActor* Weapon = GetWeapon();
	return Weapon->GetCurrentCapacity();
}

FVector ABaseCharacter::GetSpawnLocation()
{
	FRotator SpawnRotation = GetControlRotation();
	return GetWeapon()->GetSpawnLocation(SpawnRotation);
}


AGamePlayPlayerController* ABaseCharacter::GetGamePlayController() const
{
	AGamePlayPlayerController* Controller =  Cast<AGamePlayPlayerController>(GetController());
	return Controller;
}

void ABaseCharacter::PlayDeathAnimation() const
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance != nullptr)
	{
		AnimInstance->Montage_Play(DeathAnimation, 1.f);
	}
}

void ABaseCharacter::DestroyWeapon()
{
	if(VisibleWeapon)
	{
		VisibleWeapon->Destroy();
	}
}
