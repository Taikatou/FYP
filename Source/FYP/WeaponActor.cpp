// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "WeaponActor.h"
#include "Kismet/KismetMathLibrary.h"


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

void AWeaponActor::OnFire(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera)
{
	UE_LOG(LogTemp, Warning, TEXT("Weapon"));
}

FShootInformationStruct AWeaponActor::CalculateShootInformationStruct(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera) const
{
	FVector camLoc;
	FRotator camRot;
	const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
	Controller->GetPlayerViewPoint(camLoc, camRot);
	const FVector start_trace = camLoc;
	const FVector direction = camRot.Vector();
	const FVector end_trace = start_trace + (direction * MaxFireDistance);

	FCollisionQueryParams TraceParams(FName(TEXT("")), true, this);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.bTraceComplex = true;

	FHitResult Hit(ForceInit);
	FTransform LocalTransform;
	FVector LocalEndLocation;


	FVector Scale = FVector(1.0, 1.0, 1.0);
	bool DidHit = GetWorld()->LineTraceSingleByChannel(Hit, start_trace, end_trace, COLLISION_PROJECTILE, TraceParams);
	if (DidHit)
	{
		FRotator LocalRotation = UKismetMathLibrary::FindLookAtRotation(SpawnLocation, Hit.ImpactPoint);
		LocalTransform = UKismetMathLibrary::MakeTransform(SpawnLocation, LocalRotation, Scale);
		LocalEndLocation = Hit.ImpactPoint;
	}
	else
	{
		APawn* owner = Cast<APawn>(Camera->GetOwner());
		FRotator LocalRotation = owner->GetControlRotation();
		LocalTransform = UKismetMathLibrary::MakeTransform(SpawnLocation, LocalRotation, Scale);

		FTransform WorldTransform = Camera->GetComponentTransform();
		FVector EndPoint = WorldTransform.GetRotation().GetForwardVector() * 10000;
		LocalEndLocation = WorldTransform.GetLocation() + EndPoint;
	}
	FShootInformationStruct ShotInformation = FShootInformationStruct();
	ShotInformation.ProjectileTransform = LocalTransform;
	ShotInformation.EndLocation = LocalEndLocation;
	ShotInformation.HitResult = Hit;
	return ShotInformation;
}