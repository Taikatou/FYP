// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "ExplosiveProjectileActor.h"
#include "PhysicsEngine/DestructibleActor.h"
#include "BaseCharacter.h"
#include "GoogleAnalyticsBlueprintLibrary.h"
#include "Runtime/Analytics/Analytics/Public/Analytics.h"
#include "Runtime/Analytics/Analytics/Public/Interfaces/IAnalyticsProvider.h"


void AExplosiveProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, this, &AExplosiveProjectileActor::OnDetonate, 5.f, false);
}

bool AExplosiveProjectileActor::OnDetonate_Validate()
{
	return true;
}

bool AExplosiveProjectileActor::Explosion_Validate()
{
	return true;
}

void AExplosiveProjectileActor::Explosion_Implementation()
{
	UParticleSystemComponent* Explosion = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetActorTransform());
	// particle effect very small
	Explosion->SetRelativeScale3D(FVector(4.0f));
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());
}


void AExplosiveProjectileActor::OnDetonate_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Start detonation"));

	TArray<FHitResult> HitActors;
	FVector StartTrace = GetActorLocation();
	FVector EndTrace = StartTrace;
	EndTrace.Z += 300.0f;

	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(Radius);

	if(GetWorld()->SweepMultiByChannel(HitActors, StartTrace, EndTrace, FQuat::FQuat(), ECC_WorldStatic, CollisionShape))
	{
		for(auto Actors = HitActors.CreateIterator(); Actors; ++Actors)
		{
			// Check if collision is static mesh or destructable actor
			UStaticMeshComponent* SM = Cast<UStaticMeshComponent>((*Actors).Actor->GetRootComponent());
			ADestructibleActor* DA = Cast<ADestructibleActor>((*Actors).GetActor());
			ABaseCharacter* BC = Cast<ABaseCharacter>((*Actors).GetActor());
			if(SM)
			{
				SM->AddRadialImpulse(GetActorLocation(), 1000.0f, 5000.0f, ERadialImpulseFalloff::RIF_Linear, true);
			}
			else if(DA)
			{
				DA->GetDestructibleComponent()->ApplyRadiusDamage(10.0f, Actors->ImpactPoint, 500.0f, 3000.0f, false);
			}
			else if (BC)
			{
				UGoogleAnalyticsBlueprintLibrary::RecordGoogleEvent(TEXT("Apply Damage"),
					TEXT("Explosive projectile"), TEXT("Event Label"), 1);
				BC->DamagePlayer(Damage, FiredFrom);
			}
		}
	}
	Explosion();
	Destroy();
}

bool AExplosiveProjectileActor::CompleteHit_Validate(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	return true;
}


void AExplosiveProjectileActor::CompleteHit_Implementation(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	OnDetonate();
}