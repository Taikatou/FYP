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

	ASniperCharacter();

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool Aiming;

	void Aim();

	void StopAim();

	UFUNCTION(BlueprintImplementableEvent)
		void ShowSniperOverlay();
	
	UFUNCTION(BlueprintImplementableEvent)
		void HideSniperOverlay();

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* CameraLocation;
};
