// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class FYP_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when we press a key to collect any pickups inside the CollectionSphere
	UFUNCTION(BlueprintCallable, Category = "PickUps")
	void CollectPickups();

	// Starting life
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Life")
	float InitialLife = 2000;

private:
	// Current life
	UPROPERTY(VisibleAnywhere, Category = "Life")
	float CurrentLife;

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

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
		void StartJump();

	// Clears jump flag when key is released.
	UFUNCTION()
		void StopJump();

	// FPS camera.
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* FPSCameraComponent;

	// First-person mesh (arms), visible only to the owning player.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FPSMesh;

	FORCEINLINE class USphereComponent* GetSphereComponent() const { return CollectionSphere; }

	// Collection sphere for items
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class USphereComponent* CollectionSphere;

	// Accessor function for initial power
	UFUNCTION(BlueprintPure, Category = "Life")
		float GetInitialLife() const;

	// Accessor function for current power
	UFUNCTION(BlueprintPure, Category = "Life")
		float GetCurrentLife() const;

	/* Update current power
	* @param LifeDelta: amount to change life by, positive or negative
	*/
	UFUNCTION(BlueprintCallable, Category="Life")
		void UpdateLife(float LifeDelta);
};
