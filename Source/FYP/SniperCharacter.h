// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCharacter.h"
#include "SniperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API ASniperCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
		void ShowSniperOverlay();
	
	UFUNCTION(BlueprintImplementableEvent)
		void HideSniperOverlay();
};
