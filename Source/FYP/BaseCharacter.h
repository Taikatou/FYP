// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponActor.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealth);

class AGamePlayPlayerController;
UCLASS()
class FYP_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	// Starting life
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Life")
	float InitialLife = 2000;

	// Current life
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Life")
		float CurrentLife;

public:

	// Sets default values for this character's properties
	ABaseCharacter();

	// Accessor function for initial power
	UFUNCTION(BlueprintPure, Category = "Life")
	float GetInitialLife() const;

	// Accessor function for current power
	UFUNCTION(BlueprintPure, Category = "Life")
	float GetCurrentLife() const;

	/* Update current power
	* @param LifeDelta: amount to change life by, positive or negative
	*/
	UFUNCTION(Server, reliable, WithValidation, BlueprintCallable, Category="Life")
		void DamagePlayer(float LifeDelta, AActor* Killer);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath(AGamePlayPlayerController* PlayerController);

	bool PlayerAlive = true;

	UPROPERTY(EditAnywhere, Category = "Animation")
		UAnimMontage* DeathAnimation;

	void PlayDeathAnimation() const;

	class AGamePlayPlayerController* GetGamePlayController() const;

	FTimerHandle AnimationTimerHandle;

	UFUNCTION(BlueprintCallable, Category = "Name")
		void SetName(FText NewName);

	UFUNCTION(BlueprintCallable, Category = "Name")
		FText GetName();

	UFUNCTION(BlueprintPure, Category = "Death")
		bool GetDead() const;

	float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Death")
		void DeathEvent();

	UPROPERTY(BlueprintAssignable, Category = "Update Health")
		FHealth UpdateHealthEvent;

	void UpdateHealth();

	UFUNCTION(BlueprintPure, Category = "Widgets")
		TSubclassOf<class UUserWidget> GetUI() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> UI;

	// Called when the game starts or when spawned
	void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Pause")
		void Pause();
};
