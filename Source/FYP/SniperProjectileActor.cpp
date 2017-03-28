// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "SniperProjectileActor.h"
#include "BaseCharacter.h"
#include "GoogleAnalyticsBlueprintLibrary.h"
#include "Runtime/Analytics/Analytics/Public/Interfaces/IAnalyticsProvider.h"

ASniperProjectileActor::ASniperProjectileActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASniperProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	PreviousLocation = FVector(GetActorLocation());
}

void ASniperProjectileActor::Tick(float DeltaSeconds)
{
	FVector Location = FVector(GetActorLocation());
	DrawDebugLine(GetWorld(), PreviousLocation, Location, FColor::Green, false, 5.0f);
	PreviousLocation = Location;
}
