// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "LifePickUpActor.h"

// Set default values
ALifePickUpActor::ALifePickUpActor()
{
	GetMesh()->SetSimulatePhysics(true);
	LifePower = 150.0f;
}

void ALifePickUpActor::WasCollected_Implementation()
{
	// Use the base pickup behavior
	Super::WasCollected_Implementation();
	//Destroy the life
	Destroy();
}

float ALifePickUpActor::GetLife() const
{
	return LifePower;
}


