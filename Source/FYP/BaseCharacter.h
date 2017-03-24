// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponActor.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class AGamePlayPlayerController;
UCLASS()
class FYP_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	// Starting life
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Life")
	float InitialLife = 2000;

private:
	// Current life
	UPROPERTY(VisibleAnywhere, Category = "Life")
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
		void DamagePlayer(float LifeDelta, ABaseCharacter* Killer);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath(AGamePlayPlayerController* PlayerController);

	// FPS camera.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
		UCameraComponent* FPSCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool DestroyOnDeath = false;

	bool PlayerAlive = true;

	/** player pressed reload action */
	virtual void OnReload();

	UFUNCTION(Server, WithValidation, reliable)
	virtual void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool CurrentlyReloading;

	void Reloaded();

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	int32 GetMaxAmmo();

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	int32 GetCurrentAmmo();

	virtual FVector GetSpawnLocation();

	UPROPERTY(EditAnywhere, Category = "Animation")
		UAnimMontage* DeathAnimation;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void DestroyWeapon();

	UPROPERTY(EditAnywhere, Category = "Weapon")
		bool SpawnThirdPersonWeapon = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AWeaponActor* VisibleWeapon;


	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class AWeaponActor> ThirdPersonWeaponBlueprint;

	void PlayDeathAnimation() const;

	class AGamePlayPlayerController* GetGamePlayController();

	FTimerHandle AnimationTimerHandle;

	virtual AWeaponActor* GetWeapon();


	void EndPlay(EEndPlayReason::Type EndPlayReason) override;
	
	virtual UAnimInstance* GetArmsAnimInstance();

	// Called when the game starts or when spawned
	void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Name")
		void SetName(FText NewName);


	UFUNCTION(BlueprintCallable, Category = "Name")
		FText GetName();
};
