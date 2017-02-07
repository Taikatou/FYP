// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "SniperProjectileActor.h"

static FORCEINLINE bool VTraceSphere(
	AActor* ActorToIgnore,
	const FVector& Start,
	const FVector& End,
	const float Radius,
	FHitResult& HitOut,
	ECollisionChannel TraceChannel = ECC_Pawn
) {
	FCollisionQueryParams TraceParams(FName(TEXT("VictoreCore Trace")), true, ActorToIgnore);
	TraceParams.bTraceComplex = true;
	//TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;

	//Ignore Actors
	TraceParams.AddIgnoredActor(ActorToIgnore);

	//Re-initialize hit info
	HitOut = FHitResult(ForceInit);

	//Get World Source
	TObjectIterator< APlayerController > ThePC;
	if (!ThePC) return false;

	return ThePC->GetWorld()->SweepSingleByObjectType(
		HitOut,
		Start,
		End,
		FQuat(),
		TraceChannel,
		FCollisionShape::MakeSphere(Radius),
		TraceParams
	);
}

void ASniperProjectileActor::BeginPlay()
{
	UProjectileMovementComponent* projectile_movement_component = GetProjectileMovement();
	projectile_movement_component->OnProjectileBounce.AddDynamic(this, &ASniperProjectileActor::OnBounce);
}

void ASniperProjectileActor::OnBounce(const FHitResult& ImpactResult, const FVector& ImpactVelocity)
{

}

// If output = nullptr result not found
FExitLocationStruct ASniperProjectileActor::ComputeExitLocation(const FHitResult& ImpactResult, const FVector& ImpactVelocity)
{
	FExitLocationStruct exit_location;
	FVector normalised_impact_velocity = ImpactVelocity.GetSafeNormal(SMALL_NUMBER);
	FVector start_location = (normalised_impact_velocity * Distance) + ImpactResult.Location;
	float radius = GetCollisionComp()->GetScaledSphereRadius();
	//VTraceSphere(this, start_location, ImpactResult.Location, radius, )
	return exit_location;
}


