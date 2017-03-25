// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "AISpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
AAISpawnVolume::AAISpawnVolume()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create box component to epresent spawn volume
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

}

FVector AAISpawnVolume::GetRandomPointInVolume() const
{
	FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
	FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

// Called when the game starts or when spawned
void AAISpawnVolume::SpawnActor()
{
	Super::BeginPlay();
	// Check for valid world
	UWorld* const World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;

		FRotator SpawnRotation;

		// Get spawn location
		FVector SpawnLocation = GetRandomPointInVolume();
		PrintSpawn(SpawnLocation);
	}
}


