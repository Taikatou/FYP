// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "ProjectileReloadWeaponActor.h"
#include "BulletActor.h"
#include "BaseCharacter.h"


void AProjectileReloadWeaponActor::FireProjectile(TSubclassOf<class AProjectile> projectile, FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector SpawnLocation) const
{
	//FireServer(SpawnRotation, Controller, Camera);
	if (projectile != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			//const FVector SpawnLocation = ForwardVector * 100.0f;
			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

			// spawn the projectile at the muzzle
			AProjectile* ProjectileActor = World->SpawnActor<AProjectile>(projectile, SpawnLocation, SpawnRotation, ActorSpawnParams);
			ProjectileActor->FiredFrom = Cast<ABaseCharacter>(GetOwner());
			ABulletActor* const Bullet = Cast<ABulletActor>(ProjectileActor);
			if(Bullet)
			{
				FVector ForwardVector = Camera->GetForwardVector();
				FVector NewVelocity = ForwardVector * 5000.0f;
				Bullet->Velocity = FVector(NewVelocity);
			}
		}
	}
}

void AProjectileReloadWeaponActor::OnFire_Implementation(FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector SpawnLocation)
{
	FireProjectile(Projectile, SpawnRotation, Controller, Camera, SpawnLocation);
}

