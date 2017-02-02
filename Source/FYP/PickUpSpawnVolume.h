// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickUpSpawnVolume.generated.h"

UCLASS()
class FYP_API APickUpSpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpSpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Return the WhereToSpawn subobject
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	UFUNCTION(BlueprintPure, Category = "PickUpSpawnVolume")
		FVector GetRandomPointInVolume() const;

protected:
	// What to spawn
	UPROPERTY(EditAnywhere, Category = "PickUpSpawnVolume")
	TSubclassOf<class APickUpActor> WhatToSpawn;

	// Timers can't be UPROPERTYS
	FTimerHandle SpawnTimer;

	// Minimum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickUpSpawnVolume")
	float SpawnDelayRangeLow;

	// Max spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickUpSpawnVolume")
	float SpawnDelayRangeHigh;

private:
	//Where pickups should be spawned
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PickUpSpawnVolume", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WhereToSpawn;
	
	// Spawns new pickup
	void SpawnPickup();

	UFUNCTION()
	void SpawnPickupTimer();

	// Current spawn delay
	float SpawnDelay;
};
