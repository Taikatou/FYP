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

private:
	//Where pickups should be spawned
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category "PickUpSpawnVolume", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WhereToSpawn;
	
};
