// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Projectile.h"
#include "SniperProjectileActor.generated.h"

USTRUCT()
struct FExitLocationStruct
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
		FVector ExitLocation;

	UPROPERTY(VisibleAnywhere)
		bool LocationFound;
};
/**
 * 
 */
UCLASS()
class FYP_API ASniperProjectileActor : public AProjectile
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
	void OnBounce(const FHitResult& ImpactResult, const FVector& ImpactVelocity);
	FExitLocationStruct ComputeExitLocation(const FHitResult& ImpactResult, const FVector& ImpactVelocity);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		float Distance = 500;
};
