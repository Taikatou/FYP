// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "GamePlayPlayerController.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

void AGamePlayPlayerController::ShowMenu(UUserWidget* MyMainMenu)
{
	bShowMouseCursor = true;
	FInputModeUIOnly input = FInputModeUIOnly();
	SetInputMode(input);
	MyMainMenu->AddToViewport();
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
	if(KillStreak > BestKillStreak)
	{
		KillStreak = BestKillStreak;
	}
}

int32 AGamePlayPlayerController::GetTotalKills() const
{
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
	Name = NewName;
}

FText AGamePlayPlayerController::GetName() const
{
	return Name;
}
