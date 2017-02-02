// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "PickUpSpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"
#include "PickUpActor.h"

// Sets default values
APickUpSpawnVolume::APickUpSpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    // Create box component to epresent spawn volume
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

	// Set spawn delay range
	SpawnDelayRangeLow = 1.0f;
	SpawnDelayRangeHigh = 4.5f;
}

// Called when the game starts or when spawned
void APickUpSpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &APickUpSpawnVolume::SpawnPickup, SpawnDelay);
}

// Called every frame
void APickUpSpawnVolume::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

FVector APickUpSpawnVolume::GetRandomPointInVolume() const
{
	FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
	FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

void APickUpSpawnVolume::SpawnPickup()
{
	if(WhatToSpawn != nullptr)
	{
		// Check for valid world
		UWorld* const World = GetWorld();
		if(World)
		{
			// Set spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			// Get spawn location
			FVector SpawnLocation = GetRandomPointInVolume();

			// Choose spawn rotation
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;

			// Spawn the pickup
			APickUpActor* const SpawnedPickup = World->SpawnActor<APickUpActor>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
			SpawnedPickup->CompleteDelegate.BindUObject(this, &APickUpSpawnVolume::SpawnPickupTimer);
		}
	}
}

void APickUpSpawnVolume::SpawnPickupTimer()
{
	SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &APickUpSpawnVolume::SpawnPickup, SpawnDelay);
}

