// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "ProjectileReloadWeaponActor.h"


void AProjectileReloadWeaponActor::FireProjectile(TSubclassOf<class AProjectile> projectile, FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera) const
{
	//FireServer(SpawnRotation, Controller, Camera);
	if (projectile != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = (FP_MuzzleLocation != nullptr ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			World->SpawnActor<AProjectile>(projectile, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}
}

void AProjectileReloadWeaponActor::OnFire_Implementation(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera)
{
	UE_LOG(LogTemp, Warning, TEXT("Projectile"));
	FireProjectile(Projectile, SpawnRotation, Controller, Camera);
}

