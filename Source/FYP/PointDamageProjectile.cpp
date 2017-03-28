// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "PointDamageProjectile.h"
#include "GoogleAnalyticsBlueprintLibrary.h"


void APointDamageProjectile::CompleteHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ABaseCharacter* BC = Cast<ABaseCharacter>(OtherActor);
	if (BC)
	{
		UGameplayStatics::ApplyDamage(BC, BaseDamage,
			GetInstigatorController(), this, UDamageType::StaticClass());
		UGoogleAnalyticsBlueprintLibrary::RecordGoogleEvent(TEXT("Apply Damage"),
			ProjectileName, TEXT("Event Label"), 1);
	}
	Destroy();
}

