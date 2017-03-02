// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class FYP_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

	// Called when the game starts or when spawned
	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
		UBoxComponent* ProjectileCollision;

	UPROPERTY(EditDefaultsOnly)
		class UProjectileMovementComponent* ProjectileMovement;
	
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditDefaultsOnly)
		UParticleSystemComponent* ProjectileParticles;

	// The velocity of the bullet
	UPROPERTY(EditDefaultsOnly)
		float ProjectileSpeed;

	// Seconds before bullet begins dropping
	UPROPERTY(EditDefaultsOnly)
		float GravityDelay;

	// Rate at which bullet falls
	UPROPERTY(EditDefaultsOnly)
		float GravityScale;

	UFUNCTION()
		void OnProjectileHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// Once called gravity will start affecting bullet making it drop
	void ApplyGravity() const;

	UPROPERTY(EditAnywhere)
		FVector Velocity = FVector(100.0f);

	USceneComponent* RootComp;

	float BulletExpiry = 0;
};
