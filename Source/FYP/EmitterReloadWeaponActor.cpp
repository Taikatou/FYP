// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "EmitterReloadWeaponActor.h"
#include "Kismet/KismetMathLibrary.h"


FShootInformationStruct AEmitterReloadWeaponActor::CalculateShootInformationStruct(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera) const
{
	FVector camLoc;
	FRotator camRot;
	const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
	Controller->GetPlayerViewPoint(camLoc, camRot);
	const FVector start_trace = camLoc;
	const FVector direction = camRot.Vector();
	const FVector end_trace = start_trace + (direction * MaxFireDistance);

	FCollisionQueryParams TraceParams(FName(TEXT("")), true, this);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.bTraceComplex = true;

	FHitResult Hit(ForceInit);
	FTransform LocalTransform;
	FVector LocalEndLocation;


	FVector Scale = FVector(1.0, 1.0, 1.0);
	bool DidHit = GetWorld()->LineTraceSingleByChannel(Hit, start_trace, end_trace, COLLISION_PROJECTILE, TraceParams);
	if (DidHit)
	{
		FRotator LocalRotation = UKismetMathLibrary::FindLookAtRotation(SpawnLocation, Hit.ImpactPoint);
		LocalTransform = UKismetMathLibrary::MakeTransform(SpawnLocation, LocalRotation, Scale);
		LocalEndLocation = Hit.ImpactPoint;
	}
	else
	{
		APawn* owner = Cast<APawn>(Camera->GetOwner());
		FRotator LocalRotation = owner->GetControlRotation();
		LocalTransform = UKismetMathLibrary::MakeTransform(SpawnLocation, LocalRotation, Scale);

		FTransform WorldTransform = Camera->GetComponentTransform();
		FVector EndPoint = WorldTransform.GetRotation().GetForwardVector() * 10000;
		LocalEndLocation = WorldTransform.GetLocation() + EndPoint;
	}
	FShootInformationStruct ShotInformation = FShootInformationStruct();
	ShotInformation.ProjectileTransform = LocalTransform;
	ShotInformation.EndLocation = LocalEndLocation;
	ShotInformation.HitResult = Hit;
	return ShotInformation;
}
