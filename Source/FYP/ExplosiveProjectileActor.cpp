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
	
	for (TActorIterator<ABaseCharacter> aItr(GetWorld()); aItr; ++aItr)
	{
		float distance = GetDistanceTo(*aItr);

		if (distance <= 300)
		{
			UGameplayStatics::ApplyDamage(*aItr, Damage,
				GetInstigatorController(), this, UDamageType::StaticClass());
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