// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "ReloadWeaponActor.h"

AReloadWeaponActor::AReloadWeaponActor()
{
	CurrentCapacity = MaxCapacity;
}

UAnimMontage* AReloadWeaponActor::Reload()
{
	CurrentCapacity = MaxCapacity;
	UE_LOG(LogTemp, Warning, TEXT("Reloaded"));
	return ReloadAnimation;
}

bool AReloadWeaponActor::GetCanReload()
{
	return true;
}

void AReloadWeaponActor::OnFire_Implementation(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera)
{
	if(CanFire())
	{
		Super::OnFire_Implementation(SpawnRotation, Controller, Camera);
		CurrentCapacity--;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't fire"));
	}
}

bool AReloadWeaponActor::CanFire()
{
	return CurrentCapacity > 0;
}
