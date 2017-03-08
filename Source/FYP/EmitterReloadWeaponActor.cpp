// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "EmitterReloadWeaponActor.h"


void AEmitterReloadWeaponActor::OnFire_Implementation(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector SpawnLocation)
{
	SpawnEmitter();
}
