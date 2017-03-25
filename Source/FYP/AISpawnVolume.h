// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AISpawnVolume.generated.h"

UCLASS()
class FYP_API AAISpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAISpawnVolume();

	UFUNCTION(BlueprintCallable, Category ="Spawn")
		void SpawnActor();

	UFUNCTION(BlueprintPure, Category = "PickUpSpawnVolume")
		FVector GetRandomPointInVolume() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PickUpSpawnVolume", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WhereToSpawn;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 SpawnCount;

	// What to spawn
	UPROPERTY(EditAnywhere, Category = "PickUpSpawnVolume")
		TSubclassOf<class AActor> WhatToSpawn;

	UFUNCTION(BlueprintImplementableEvent, Category = "Spawn")
		void PrintSpawn(FVector SpawnLocation);
};
