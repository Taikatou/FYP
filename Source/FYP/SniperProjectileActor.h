// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Projectile.h"
#include "SniperProjectileActor.generated.h"

UCLASS()
class FYP_API ASniperProjectileActor : public AProjectile
{
	GENERATED_BODY()
	
public:
	ASniperProjectileActor();

	void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		float Distance = 500;

	void Tick(float DeltaSeconds) override;

	FVector PreviousLocation;

	void CompleteHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
};
