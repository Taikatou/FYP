// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "Target.h"


ATarget::ATarget()
{
	Health = 100;

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Target Mesh"));
	RootComponent = TargetMesh;
}

void ATarget::DestroyTarget()
{
	Destroy();
}

void ATarget::DamageTarget(float Damage)
{
	Health -= Damage;
	if(Health <= 0)
	{
		DestroyTarget();
	}
}
