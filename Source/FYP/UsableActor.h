// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "UsableActor.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API AUsableActor : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
		bool OnUsed(ACharacter* character);

	UFUNCTION(BlueprintImplementableEvent)
		bool StartFocusItem();

	UFUNCTION(BlueprintImplementableEvent)
		bool EndFocusItem();
	
};
