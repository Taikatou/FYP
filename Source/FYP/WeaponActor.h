// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Projectile.h"
#include "GameFramework/Actor.h"
#include "WeaponActor.generated.h"

USTRUCT()
struct FShootInformationStruct
{
	GENERATED_BODY()

		FTransform ProjectileTransform;
	FHitResult HitResult;
	FVector EndLocation;
};

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

	// Called when the game starts or when spawned
	void BeginPlay() override;
	
	// Called every frame
	void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimInstance* AnimInstance;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;

	virtual UAnimMontage* FireWeapon(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera);

	UFUNCTION(Server, reliable, WithValidation, Category = "Fire")
		virtual void OnFire(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera);

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float MaxFireDistance;

	UPROPERTY(EditAnywhere, Category = "Animation")
		UAnimMontage* FireAnimation;

	virtual UAnimMontage* Reload() { return nullptr; }

	UFUNCTION(BlueprintPure, Category = "Calculate shot information")
		FShootInformationStruct CalculateShootInformationStruct(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera) const;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PickUp", meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* WeaponMesh;

};
