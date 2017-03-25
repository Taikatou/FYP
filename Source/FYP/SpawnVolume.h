// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class FYP_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PickUpSpawnVolume", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WhereToSpawn;

	UFUNCTION(BlueprintPure, Category = "PickUpSpawnVolume")
		FVector GetRandomPointInVolume() const;
	
};
