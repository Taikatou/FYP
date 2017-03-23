// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// TODO protect against no patrol route component
	// Get the patrol points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if(!ensure(PatrolRoute))
	{
		return EBTNodeResult::Failed;
	}
	else
	{
		auto PatrolPoints = PatrolRoute->GetPatrolPoints();
		// Warn about empty patrol routes
		if(PatrolPoints.Num() == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("no patrol routes"));
			return EBTNodeResult::Failed;
		}
		else
		{
			// Set next waypoint
			auto BlackboardComp = OwnerComp.GetBlackboardComponent();
			auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
			BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);;

			// TODO protect against empty patrol routes

			//Cycle the index
			auto NextIndex = (Index + 1) % PatrolPoints.Num();
			BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
			return EBTNodeResult::Succeeded;
		}
	}
}

