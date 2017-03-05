// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "SniperProjectileActor.h"

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

void ASniperProjectileActor::CompleteHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}
