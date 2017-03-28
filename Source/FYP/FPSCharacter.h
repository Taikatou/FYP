// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCharacter.h"
#include "FPSCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API AFPSCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	AFPSCharacter();
	
	// FPS camera.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
		UCameraComponent* FPSCameraComponent;


	/** player pressed reload action */
	virtual void OnReload();

	UFUNCTION(Server, WithValidation, reliable)
		virtual void Fire();

	UFUNCTION(BlueprintCallable, Category = "Fire")
		virtual void FireBlueprint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool CurrentlyReloading;

	void Reloaded();

	UFUNCTION(BlueprintPure, Category = "Ammo")
		int32 GetMaxAmmo();

	UFUNCTION(BlueprintPure, Category = "Ammo")
		int32 GetCurrentAmmo();

	virtual FVector GetSpawnLocation();
	
	virtual UAnimInstance* GetArmsAnimInstance();

	virtual AWeaponActor* GetWeapon();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void DestroyWeapon();

	void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	void BeginPlay() override;

	// First-person mesh (arms), visible only to the owning player.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FPSMesh;

	// First-person mesh (arms), visible only to the owning player.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* VisibleWeapon;

	AWeaponActor* Weapon;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class AWeaponActor> WeaponBlueprint;
};
