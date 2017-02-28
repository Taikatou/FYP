// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "ExplosiveProjectileActor.h"
#include "PhysicsEngine/DestructibleActor.h"


void AExplosiveProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, this, &AExplosiveProjectileActor::OnDetonate, 5.f, false);
}

void AExplosiveProjectileActor::OnDetonate()
{
	UE_LOG(LogTemp, Warning, TEXT("Start detonation"));
	UParticleSystemComponent* Explosion = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetActorTransform());
	// particle effect very small
	Explosion->SetRelativeScale3D(FVector(4.0f));
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());

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

			if(SM)
			{
				SM->AddRadialImpulse(GetActorLocation(), 1000.0f, 5000.0f, ERadialImpulseFalloff::RIF_Linear, true);
			}
			else if(DA)
			{
				DA->GetDestructibleComponent()->ApplyRadiusDamage(10.0f, Actors->ImpactPoint, 500.0f, 3000.0f, false);
			}
		}
	}
	Destroy();
}

void AExplosiveProjectileActor::CompleteHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	OnDetonate();
}