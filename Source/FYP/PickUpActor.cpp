// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "PickUpActor.h"


// Sets default values
APickUpActor::APickUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create static mesh component
	PickUpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickUpMesh;

	//Set active on creation
	bIsActive = true;
}

// Called when the game starts or when spawned
void APickUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool APickUpActor::IsActive() const
{
	return bIsActive;
}

void APickUpActor::SetActive(bool PickupState)
{
	bIsActive = PickupState;
}

void APickUpActor::WasCollected_Implementation()
{
	// Log a debug message
	FString PickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("You have collected %s"));
	CompleteDelegate.ExecuteIfBound();
}

