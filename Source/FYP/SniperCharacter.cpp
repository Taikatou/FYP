// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "SniperCharacter.h"


void ASniperCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &ASniperCharacter::ShowSniperOverlay);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &ASniperCharacter::HideSniperOverlay);
}
