// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ReloadWeaponActor.h"
#include "EmitterReloadWeaponActor.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API AEmitterReloadWeaponActor : public AReloadWeaponActor
{
	GENERATED_BODY()
	
	
public:
	void OnFire_Implementation(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector SpawnLocation) override;
	

	UFUNCTION(BlueprintImplementableEvent)
		void SpawnEmitter();
};
