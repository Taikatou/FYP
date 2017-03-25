// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "PatrolRoute.h"

TArray<AActor*> UPatrolRoute::GetPatrolPoints() const
{
	return PatrolPointsCPP;
}

void UPatrolRoute::AddActorToPatrolRoute(AActor* AddActor)
{
	PatrolPointsCPP.Add(AddActor);
}
