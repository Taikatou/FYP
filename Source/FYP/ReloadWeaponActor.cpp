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
	return ReloadAnimation;
}

int32 AReloadWeaponActor::GetCurrentCapacity()
{
	return CurrentCapacity;
}

UAnimMontage* AReloadWeaponActor::FireWeapon(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector ForwardVector)
{
	UAnimMontage* Animation;
	if(CanFire())
	{
		OnFire(SpawnRotation, Controller, Camera, ForwardVector);
		CurrentCapacity--;
		Animation = FireAnimation;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't fire"));
		Animation = Reload();
	}
	return Animation;
}

bool AReloadWeaponActor::CanFire() const
{
	return CurrentCapacity > 0;
}
