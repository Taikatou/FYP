// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FPSCharacter.h"
#include "WeaponActor.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API APlayerCharacter : public AFPSCharacter
{
	GENERATED_BODY()
	
public:

	APlayerCharacter();
	
	// Called when we press a key to collect any pickups inside the CollectionSphere
	UFUNCTION(BlueprintCallable, Category = "PickUps")
		void CollectPickups();

	// Get actor currently in players view
	class AUsableActor* GetUsableInView() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float MaxUseDistance;

	bool bHasNewFocus;

	AUsableActor* FocusedUsableActor;

	// Called when the game starts or when spawned
	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handles input for moving forward and backward.
	UFUNCTION()
		void MoveForward(float Value);

	// Handles input for moving right and left.
	UFUNCTION()
		void MoveRight(float Value);

	// Sets jump flag when key is pressed.
	UFUNCTION()
		virtual void StartJump();

	// Clears jump flag when key is released.
	UFUNCTION()
		void StopJump();

	FORCEINLINE class USphereComponent* GetSphereComponent() const { return CollectionSphere; }

	// Collection sphere for items
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class USphereComponent* CollectionSphere;

	UFUNCTION(BlueprintPure, Category = "Camera")
		UCameraComponent* GetCamera() const;

	/** Use the actor currently in view (if derived from UsableActor) */
	UFUNCTION(BlueprintCallable, WithValidation, Server, Reliable, Category = PlayerAbility)
		virtual void Use();

	AWeaponActor* GetWeapon() override;

	UAnimInstance* GetArmsAnimInstance() override;
};
