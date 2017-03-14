// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "ThirdPersonWeapon.h"


// Sets default values
AThirdPersonWeapon::AThirdPersonWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create gun mesh component
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->bCastDynamicShadow = false;
	WeaponMesh->CastShadow = false;
	WeaponMesh->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void AThirdPersonWeapon::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("begin play"));
}