// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "ReloadWeaponActor.h"
#include "GoogleAnalyticsBlueprintLibrary.h"
#include "Runtime/Analytics/Analytics/Public/Analytics.h"
#include "Runtime/Analytics/Analytics/Public/Interfaces/IAnalyticsProvider.h"

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

void AReloadWeaponActor::BeginPlay()
{
	FAnalytics::Get().GetDefaultConfiguredProvider()->StartSession();
}

UAnimMontage* AReloadWeaponActor::FireWeapon(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector SpawnLocation)
{
	UAnimMontage* Animation;
	if(CanFire())
	{
		UGoogleAnalyticsBlueprintLibrary::RecordGoogleEvent(TEXT("Fire"), TEXT("Fire Success"), TEXT("Fire"), 1);
		OnFire(SpawnRotation, Controller, Camera, SpawnLocation);
		CurrentCapacity--;
		Animation = GetFireAnimation();
	}
	else
	{
		UGoogleAnalyticsBlueprintLibrary::RecordGoogleEvent(TEXT("Fire"), TEXT("Need Reload"), TEXT("Fire"), 1);
		Animation = Reload();
	}
	return Animation;
}

bool AReloadWeaponActor::CanFire() const
{
	return CurrentCapacity > 0;
}
