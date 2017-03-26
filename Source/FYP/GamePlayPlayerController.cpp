// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "GamePlayPlayerController.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "GameModePlayerState.h"
#include "UnrealNetwork.h"

bool AGamePlayPlayerController::GetPaused()
{
	return MyMainMenu->GetRootWidget()->Visibility == ESlateVisibility::Visible;
}

void AGamePlayPlayerController::ShowMainMenu()
{
	bShowMouseCursor = true;
	FInputModeUIOnly input = FInputModeUIOnly();
	SetInputMode(input);
	MyMainMenu->GetRootWidget()->SetVisibility(ESlateVisibility::Visible);
}

void AGamePlayPlayerController::HideMainMenu()
{
	bShowMouseCursor = false;
	FInputModeGameOnly input = FInputModeGameOnly();
	SetInputMode(input);
	MyMainMenu->GetRootWidget()->SetVisibility(ESlateVisibility::Hidden);
}

void AGamePlayPlayerController::TogglePauseMenu()
{
	if(GetPaused())
	{
		HideMainMenu();
	}
	else
	{
		ShowMainMenu();
	}
}

AGameModePlayerState* AGamePlayPlayerController::GetGamePlayState()
{
	return Cast<AGameModePlayerState>(PlayerState);
}

void AGamePlayPlayerController::SetKillStreak(int32 value)
{
	KillStreak = value;
}

int32 AGamePlayPlayerController::GetKillStreak() const
{
	return KillStreak;
}

void AGamePlayPlayerController::SetTotalKills(int32 value)
{
	TotalKills = value;
}

void AGamePlayPlayerController::ResetKillStreak()
{
	if (KillStreak > BestKillStreak)
	{
		KillStreak = BestKillStreak;
	}
}

int32 AGamePlayPlayerController::GetTotalKills() const
{
	UE_LOG(LogTemp, Warning, TEXT("Get Total Kills"));
	return TotalKills;
}

void AGamePlayPlayerController::OnDeath()
{
	SetKillStreak(0);
}

void AGamePlayPlayerController::IncrementKills(int32 Killed)
{
	KillStreak++;
	TotalKills++;
	UE_LOG(LogTemp, Warning, TEXT("player died, %d"), TotalKills);
}

void AGamePlayPlayerController::SetName(FText NewName)
{
	Name = FText(NewName);
}

FText AGamePlayPlayerController::GetName() const
{
	UE_LOG(LogTemp, Warning, TEXT("Get name"));
	return Name;
}

void AGamePlayPlayerController::InitMenuSystem()
{
	if (wMainMenu) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		MyMainMenu = CreateWidget<UUserWidget>(this, wMainMenu);

		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (MyMainMenu)
		{
			//let add it to the view port
			MyMainMenu->AddToViewport();
			MyMainMenu->GetRootWidget()->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void AGamePlayPlayerController::BroadcastResetHealth() const
{
	ResetHealth.Broadcast();
}

void AGamePlayPlayerController::BroadcastUpdateHealth() const
{
	UpdateHealthEvent.Broadcast();
}

void AGamePlayPlayerController::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	DOREPLIFETIME(AGamePlayPlayerController, Name);
	DOREPLIFETIME(AGamePlayPlayerController, TotalKills);
	DOREPLIFETIME(AGamePlayPlayerController, KillStreak);
	DOREPLIFETIME(AGamePlayPlayerController, BestKillStreak);
}

