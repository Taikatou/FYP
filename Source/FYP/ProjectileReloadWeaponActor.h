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
	
	
public:
	UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireProjectile(TSubclassOf<class AActor> projectile, FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera) const;

	void OnFire_Implementation(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class AActor> Projectile;
	
};
