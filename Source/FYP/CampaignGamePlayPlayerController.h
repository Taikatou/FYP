// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GamePlayPlayerController.h"
#include "CampaignGamePlayPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API ACampaignGamePlayPlayerController : public AGamePlayPlayerController
{
	GENERATED_BODY()
	
	
public:
	void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wBloodHud;

	// Variable to hold the widget After Creating it.
	UUserWidget* MyBloodHud;
	
};
