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

	virtual void Aim();

	virtual void StopAim();

	UFUNCTION(BlueprintImplementableEvent)
		void ShowSniperOverlay();
	
	UFUNCTION(BlueprintImplementableEvent)
		void HideSniperOverlay();

	UFUNCTION(BlueprintCallable, Category="EndGame")
		void EndGame();
	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* CameraLocation;

	FVector GetSpawnLocation() override;

	void EndPlay(EEndPlayReason::Type EndPlayReason) override;
};
