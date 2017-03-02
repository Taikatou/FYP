// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "BulletActor.h"
#include "Target.h"


// Sets default values
ABulletActor::ABulletActor()
{
	ProjectileSpeed = 40000.0f;
	GravityDelay = 0.1f;
	GravityScale = 3.5f;

	ProjectileCollision = CreateDefaultSubobject<UBoxComponent>(FName("ProjectileCollision"));
	ProjectileCollision->InitBoxExtent(FVector(2.0f));
	ProjectileCollision->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileCollision->OnComponentHit.AddDynamic(this, &ABulletActor::OnProjectileHit);
	SetRootComponent(ProjectileCollision);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = ProjectileCollision;
	ProjectileMovement->InitialSpeed = ProjectileSpeed;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	// Initialise the bullet mesh. This doesn't need to be set if we don't need bullet
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("ProjectileMesh"));
	ProjectileMesh->SetupAttachment(RootComponent);

	// Initialise the bullets particle system if we want.
	ProjectileParticles = CreateDefaultSubobject <UParticleSystemComponent>(FName("ProjectileParticles"));
	ProjectileParticles->SetupAttachment(RootComponent);

	// If the bullet does not hit anything in 3 seconds, destroy it
	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle DummyHandle;

	// Start bullet dropping after <GravityDelay>
	GetWorldTimerManager().SetTimer(DummyHandle, this, &ABulletActor::ApplyGravity, GravityDelay, false);
}

void ABulletActor::Tick(float DeltaTime)
{
}

void ABulletActor::OnProjectileHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if(OtherActor->IsA((ATarget::StaticClass())))
	{
		if (Hit.BoneName != NAME_None)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("You hit the bots: %s"), *Hit.BoneName.ToString()));
		}
		OtherActor->Destroy();
	}

	// Optional
	Destroy();
}

void ABulletActor::ApplyGravity() const
{
	ProjectileMovement->ProjectileGravityScale = GravityScale;
}
