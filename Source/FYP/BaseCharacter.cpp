// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "BaseCharacter.h"
#include "Animation/AnimInstance.h"
#include "PickUpActor.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "GamePlayPlayerController.h"
#include "WeaponActor.h"
#include "Runtime/Analytics/Analytics/Public/Analytics.h"
#include "Runtime/Analytics/Analytics/Public/Interfaces/IAnalyticsProvider.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	FAnalytics::Get().GetDefaultConfiguredProvider()->StartSession();

	// Set current life level for the character
	CurrentLife = InitialLife;
}

void ABaseCharacter::DamagePlayer_Implementation(float LifeDelta, AActor* Killer)
{
	if (PlayerAlive)
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
			if (Killer && Killer != this)
			{
				AGamePlayPlayerController* controller = Cast<AGamePlayPlayerController>(GetController());
				if (controller)
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

void ABaseCharacter::Pause()
{
	AGamePlayPlayerController* controller = GetGamePlayController();
	if (controller)
	{
		controller->TogglePauseMenu();
	}
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

void ABaseCharacter::UpdateHealth()
{
	UpdateHealthEvent.Broadcast();
	auto Controller = GetGamePlayController();
	if(Controller)
	{
		Controller->BroadcastUpdateHealth();
	}
}

TSubclassOf<UUserWidget> ABaseCharacter::GetUI() const
{
	return UI;
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