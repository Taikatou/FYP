// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponActor.h"
#include "ReloadWeaponActor.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API AReloadWeaponActor : public AWeaponActor
{
	GENERATED_BODY()
private:
	int32 CurrentCapacity = 0;
	
public:
	AReloadWeaponActor();
	
	UPROPERTY(EditAnywhere, Category = "Animation")
		UAnimMontage* ReloadAnimation;

	FORCEINLINE
		UFUNCTION(BlueprintPure, Category = "Capacity")
		bool HasAmmo() const { return CurrentCapacity > 0; }

	UAnimMontage* FireWeapon(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera) override;

	bool CanFire() const;

	UAnimMontage* Reload() override;

	int32 GetCurrentCapacity() override;
};
