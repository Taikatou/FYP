// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "EmitterReloadWeaponActor.h"


void AEmitterReloadWeaponActor::OnFire_Implementation(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector SpawnLocation)
{
	FHitResult HitResult = FHitResult();
	FVector StartTrace = Camera->GetComponentLocation();
	FVector ForwardVector = Camera->GetForwardVector();
	FVector EndTrace = ((ForwardVector * 2000.0f) + StartTrace);
	FCollisionQueryParams* TraceParams = new FCollisionQueryParams();

	if(GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams))
	{
	}
	UE_LOG(LogTemp, Warning, TEXT("DrawLine"));
	DrawDebugLine(GetWorld(), SpawnLocation, EndTrace, FColor::Green, false, 5.0f);
}
