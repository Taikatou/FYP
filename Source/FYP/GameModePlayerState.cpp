// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "GameModePlayerState.h"


void AGameModePlayerState::SetKillStreak(int32 value)
{
	KillStreak = value;
}

int32 AGameModePlayerState::GetKillStreak() const
{
	return KillStreak;
}

void AGameModePlayerState::SetTotalKills(int32 value)
{
	TotalKills = value;
}

void AGameModePlayerState::ResetKillStreak()
{
	if (KillStreak > BestKillStreak)
	{
		KillStreak = BestKillStreak;
	}
}

int32 AGameModePlayerState::GetTotalKills() const
{
	return TotalKills;
}

void AGameModePlayerState::OnDeath()
{
	SetKillStreak(0);
}

void AGameModePlayerState::IncrementKills(int32 Killed)
{
	KillStreak++;
	TotalKills++;
	UE_LOG(LogTemp, Warning, TEXT("player died, %d"), TotalKills);
}

void AGameModePlayerState::SetName(FText NewName)
{
	Name = FText(NewName);
}

FText AGameModePlayerState::GetName() const
{
	return Name;
}
