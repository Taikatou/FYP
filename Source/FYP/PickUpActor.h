// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickUpActor.generated.h"

UCLASS()
class FYP_API APickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Return pickup mesh
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickUpMesh; }

	//Pure functions do not make changes
	//Return bIsActive
	UFUNCTION(BlueprintPure, Category="PickUp")
	bool IsActive() const;

	//Set bIsActive
	UFUNCTION(BlueprintCallable, Category = "PickUp")
	void SetActive(bool PickupState);

	// Behaviour split between C++ and blueprints
	// After collected
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

	DECLARE_DELEGATE(FMyDelegate)
	FMyDelegate CompleteDelegate;

protected:
	// true when pickup can be used
	bool bIsActive;

private:
	//forward declaration
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PickUp", meta = (AllowPrivateAccess="true"))
	class UStaticMeshComponent* PickUpMesh;
	
};
