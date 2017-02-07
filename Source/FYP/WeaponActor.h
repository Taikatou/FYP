// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Projectile.h"
#include "GameFramework/Actor.h"
#include "WeaponActor.generated.h"

UCLASS(Abstract, Blueprintable)
class FYP_API AWeaponActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponActor();

	// Called when the game starts or when spawned
	void BeginPlay() override;
	
	// Called every frame
	void Tick( float DeltaSeconds ) override;
	
	virtual bool CanFire();

	virtual UAnimMontage* Reload();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimInstance* AnimInstance;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;

	virtual bool GetCanReload();

	virtual void FireWeapon(FRotator SpawnRotation);

	UFUNCTION(BlueprintNativeEvent)
		void OnFire(FRotator SpawnRotation);
	virtual void OnFire_Implementation(FRotator SpawnRotation);

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class AProjectile> ProjectileClass;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PickUp", meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* WeaponMesh;

};
