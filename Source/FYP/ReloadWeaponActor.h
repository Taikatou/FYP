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

	UAnimMontage* Reload() override;
	
	UPROPERTY(EditAnywhere, Category = "Animation")
		UAnimMontage* ReloadAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Capacity")
		int32 MaxCapacity = 5;

	FORCEINLINE
		UFUNCTION(BlueprintPure, Category = "Capacity")
		bool HasAmmo() const { return CurrentCapacity > 0; }

	bool GetCanReload() override;

	void OnFire_Implementation(FRotator SpawnRotation) override;

	bool CanFire() override;
};
