// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "WeaponActor.generated.h"

UCLASS()
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

	virtual void Fire();
	
	virtual bool CanFire();

	virtual UAnimMontage* Reload();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimInstance* AnimInstance;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;

	virtual bool GetCanReload();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PickUp", meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* WeaponMesh;

};
