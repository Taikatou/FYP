// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "GamePlayPlayerController.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "GameModePlayerState.h"
#include "UnrealNetwork.h"

void AGamePlayPlayerController::ShowMenu(UUserWidget* MyMainMenu, bool ShowMouse)
{
	MyMainMenu->AddToViewport();
	SetInputMouse();
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

void AGamePlayPlayerController::SetInputMouse()
{
	bShowMouseCursor = true;
	FInputModeUIOnly input = FInputModeUIOnly();
	SetInputMode(input);
}

void AGamePlayPlayerController::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	DOREPLIFETIME(AGamePlayPlayerController, Name);
	DOREPLIFETIME(AGamePlayPlayerController, TotalKills);
	DOREPLIFETIME(AGamePlayPlayerController, KillStreak);
	DOREPLIFETIME(AGamePlayPlayerController, BestKillStreak);
}

