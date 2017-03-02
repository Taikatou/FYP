// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "ProjectileReloadWeaponActor.h"
#include "BulletActor.h"


void AProjectileReloadWeaponActor::FireProjectile(TSubclassOf<class AActor> projectile, FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector ForwardVector) const
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
			AActor* ProjectileActor = World->SpawnActor<AActor>(projectile, SpawnLocation, SpawnRotation, ActorSpawnParams);
			ABulletActor* const Bullet = Cast<ABulletActor>(ProjectileActor);
			if(Bullet)
			{
				FVector NewVelocity = ForwardVector * 5000.0f;
				Bullet->Velocity = FVector(NewVelocity);
			}
		}
	}
}

void AProjectileReloadWeaponActor::OnFire_Implementation(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector ForwardVector)
{
	UE_LOG(LogTemp, Warning, TEXT("Projectile"));
	FireProjectile(Projectile, SpawnRotation, Controller, Camera, ForwardVector);
}

