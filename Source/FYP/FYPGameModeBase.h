// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "FYPGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API AFYPGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	AFYPGameModeBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Life")
		float Time;

	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/* Handle to manage the timer */
	FTimerHandle ClockTimer;

	void BeginPlay() override;
	
	void DecrementTimer();
};
