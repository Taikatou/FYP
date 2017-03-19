// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "SniperCharacter.h"

ASniperCharacter::ASniperCharacter()
{
	Aiming = false;
	CameraLocation = CreateDefaultSubobject<USceneComponent>(TEXT("CameraLocation"));
	CameraLocation->SetupAttachment(FPSCameraComponent);
}

void ASniperCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &ASniperCharacter::Aim);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &ASniperCharacter::StopAim);
}

void ASniperCharacter::Aim()
{
	Aiming = true;
	GetWeapon()->SetVisibility(false);
	ShowSniperOverlay();
}

void ASniperCharacter::StopAim()
{
	Aiming = false;
	GetWeapon()->SetVisibility(true);
	HideSniperOverlay();
}

FVector ASniperCharacter::GetSpawnLocation()
{
	if(Aiming)
	{
		return CameraLocation->GetComponentLocation();
	}
	else
	{
		return Super::GetSpawnLocation();
	}
}

void ASniperCharacter::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	if(Aiming)
	{
		HideSniperOverlay();
	}
}
