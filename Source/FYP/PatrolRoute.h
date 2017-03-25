// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FYP_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

private:	
	UPROPERTY(Category = "Patrol Route", EditInstanceOnly)
		TArray<AActor*> PatrolPointsCPP;

public:
	UFUNCTION(BlueprintPure, Category = "Patrol Route")
		TArray<AActor*> GetPatrolPoints() const;

	UFUNCTION(BlueprintCallable, Category = "Patrol Route")
		void AddActorToPatrolRoute(AActor* AddActor);
	
};
