// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Projectile.h"
#include "PointDamageProjectile.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API APointDamageProjectile : public AProjectile
{
	GENERATED_BODY()

public:
	void CompleteHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BaseDamage = 50.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ProjectileName;
};
