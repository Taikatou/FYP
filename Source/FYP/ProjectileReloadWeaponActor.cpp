// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "ProjectileReloadWeaponActor.h"
#include "BulletActor.h"


void AProjectileReloadWeaponActor::FireProjectile(TSubclassOf<class AActor> projectile, FRotator SpawnRotation, AController* Controller, UCameraComponent* Camera, FVector SpawnLocation) const
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
			AActor* ProjectileActor = World->SpawnActor<AActor>(projectile, SpawnLocation, SpawnRotation, ActorSpawnParams);
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
	UE_LOG(LogTemp, Warning, TEXT("Projectile"));
	FireProjectile(Projectile, SpawnRotation, Controller, Camera, SpawnLocation);
}

