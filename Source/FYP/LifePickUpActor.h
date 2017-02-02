// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PickUpActor.h"
#include "LifePickUpActor.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API ALifePickUpActor : public APickUpActor
{
	GENERATED_BODY()
protected:
	// Amount of life to give to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Life", Meta = (BlueprintProtected))
	float LifePower;

public:
	// Set default values
	ALifePickUpActor();
	
	// Override was collected function - using implementation because it is Blueprint native
	void WasCollected_Implementation() override;

	// Accessor for LifePower
	float GetLife() const;
};
