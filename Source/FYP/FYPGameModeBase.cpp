// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPGameModeBase.h"


AFYPGameModeBase::AFYPGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFYPGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Ensure the fuze timer is cleared
	GetWorld()->GetTimerManager().ClearTimer(ClockTimer);
}

void AFYPGameModeBase::BeginPlay()
{
	GetWorld()->GetTimerManager().SetTimer(ClockTimer, this, &AFYPGameModeBase::DecrementTimer, 1.0f, true);
}

void AFYPGameModeBase::DecrementTimer()
{
	if(Time > 0)
	{
		Time--;
	}
}
