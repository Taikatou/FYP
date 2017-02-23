// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "WeaponActor.h"


int32 AWeaponActor::GetCurrentCapacity()
{
	return 0;
}

// Sets default values
AWeaponActor::AWeaponActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create gun mesh component
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->bCastDynamicShadow = false;
	WeaponMesh->CastShadow = false;
	WeaponMesh->SetOnlyOwnerSee(true);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(WeaponMesh);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));
}

// Called when the game starts or when spawned
void AWeaponActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

UAnimMontage* AWeaponActor::FireWeapon(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera)
{
	OnFire(SpawnRotation, Controller, Camera);
	return FireAnimation;
}

void AWeaponActor::OnFire_Implementation(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera)
{
}
