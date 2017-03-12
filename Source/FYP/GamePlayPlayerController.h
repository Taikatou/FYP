// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "GamePlayPlayerController.generated.h"

class UUserWidget;
/**
 * 
 */
UCLASS()
class FYP_API AGamePlayPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void ShowMenu(UUserWidget* MyMainMenu);

	UFUNCTION(BlueprintPure, Category = "State")
		class AGameModePlayerState* GetGamePlayState();
};
