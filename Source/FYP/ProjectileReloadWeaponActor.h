// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ReloadWeaponActor.h"
#include "ProjectileReloadWeaponActor.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API AProjectileReloadWeaponActor : public AReloadWeaponActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class AProjectile> ProjectileClass;

	void OnFire_Implementation(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera) override;
	
};
