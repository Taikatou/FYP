// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Projectile.h"
#include "ExplosiveProjectileActor.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API AExplosiveProjectileActor : public AProjectile
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "FX")
		UParticleSystem* ExplosionParticles;

	UPROPERTY(EditAnywhere, Category = "FX")
		USoundCue* ExplosionSound;

	UPROPERTY(EditAnywhere, Category = Projectile)
		float Radius = 500.0f;

public:
	void BeginPlay() override;

	UFUNCTION(Server, reliable, WithValidation)
		void OnDetonate();

	UFUNCTION(NetMulticast, reliable, WithValidation)
		void Explosion();

	UFUNCTION(Server, reliable, WithValidation)
		void CompleteHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage = 100.0f;
};
