// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "Target.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API ATarget : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	float Health;

	ATarget();

	UStaticMeshComponent* TargetMesh;

	void DestroyTarget();

	void DamageTarget(float Damage);
	
};
