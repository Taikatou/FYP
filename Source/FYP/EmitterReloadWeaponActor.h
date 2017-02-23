// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ReloadWeaponActor.h"
#include "EmitterReloadWeaponActor.generated.h"

/**
 * 
 */
USTRUCT()
struct FShootInformationStruct
{
	GENERATED_BODY()
	
	FTransform ProjectileTransform;
	FHitResult HitResult;
	FVector EndLocation;
};

UCLASS()
class FYP_API AEmitterReloadWeaponActor : public AReloadWeaponActor
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintPure, Category = "Calculate shot information")
	FShootInformationStruct CalculateShootInformationStruct(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera) const;
	
};
