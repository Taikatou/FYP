// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "WeaponActor.generated.h"

UCLASS(Abstract, Blueprintable)
class FYP_API AWeaponActor : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int32 MaxCapacity;

	virtual int32 GetCurrentCapacity();

	// Sets default values for this actor's properties
	AWeaponActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimInstance* AnimInstance;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;

	virtual UAnimMontage* FireWeapon(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector SpawnLocation);

	UFUNCTION(Server, reliable, WithValidation, Category = "Fire")
		virtual void OnFire(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector SpawnLocation);

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float MaxFireDistance;

	UPROPERTY(EditAnywhere, Category = "Animation")
		UAnimMontage* FireAnimation;

	UFUNCTION(BlueprintNativeEvent, Category="Fire Animation")
		UAnimMontage* GetFireAnimation();

	virtual UAnimMontage* Reload() { return nullptr; }

	void SetVisibility(bool Visible) const;

	virtual FVector GetSpawnLocation(FRotator SpawnRotation);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PickUp", meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* WeaponMesh;

};
