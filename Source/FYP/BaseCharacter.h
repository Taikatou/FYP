// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponActor.h"
#include "ThirdPersonWeapon.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class AGamePlayPlayerController;
UCLASS()
class FYP_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when we press a key to collect any pickups inside the CollectionSphere
	UFUNCTION(BlueprintCallable, Category = "PickUps")
	void CollectPickups();

	// Starting life
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Life")
	float InitialLife = 2000;

	FTimerHandle AnimationTimerHandle;

	// Get actor currently in players view
	class AUsableActor* GetUsableInView() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float MaxUseDistance;

	bool bHasNewFocus;

	AUsableActor* FocusedUsableActor;

private:
	// Current life
	UPROPERTY(VisibleAnywhere, Category = "Life")
	float CurrentLife;

	AWeaponActor* Weapon;

public:
	FORCEINLINE
	AWeaponActor* GetWeapon() const { return Weapon; }

	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual AWeaponActor* GetWeapon();

	void EndPlay(EEndPlayReason::Type EndPlayReason) override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handles input for moving forward and backward.
	UFUNCTION()
	void MoveForward(float Value);

	// Handles input for moving right and left.
	UFUNCTION()
	void MoveRight(float Value);

	// Sets jump flag when key is pressed.
	UFUNCTION()
	void StartJump();

	// Clears jump flag when key is released.
	UFUNCTION()
	void StopJump();

	// FPS camera.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* FPSCameraComponent;

	// First-person mesh (arms), visible only to the owning player.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* FPSMesh;

	FORCEINLINE class USphereComponent* GetSphereComponent() const { return CollectionSphere; }

	// Collection sphere for items
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USphereComponent* CollectionSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AThirdPersonWeapon* ThirdPersonWeapon;

	// Accessor function for initial power
	UFUNCTION(BlueprintPure, Category = "Life")
	float GetInitialLife() const;

	// Accessor function for current power
	UFUNCTION(BlueprintPure, Category = "Life")
	float GetCurrentLife() const;

	UFUNCTION(BlueprintPure, Category = "Camera")
	UCameraComponent* GetCamera() const;

	/* Update current power
	* @param LifeDelta: amount to change life by, positive or negative
	*/
	UFUNCTION(Server, reliable, WithValidation, BlueprintCallable, Category="Life")
	void DamagePlayer(float LifeDelta, ABaseCharacter* Killer);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath(AGamePlayPlayerController* PlayerController);

	bool PlayerAlive = true;

	/** player pressed reload action */
	virtual void OnReload();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<class AWeaponActor> WeaponBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class AThirdPersonWeapon> ThirdPersonWeaponBlueprint;

	UFUNCTION(Server, WithValidation, reliable)
	virtual void Fire();

	UFUNCTION(BlueprintNativeEvent, Category = "Fire")
		void FireEvent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool CurrentlyReloading;

	void Reloaded();

	/** Use the actor currently in view (if derived from UsableActor) */
	UFUNCTION(BlueprintCallable, WithValidation, Server, Reliable, Category = PlayerAbility)
	virtual void Use();

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	int32 GetMaxAmmo() const;

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	int32 GetCurrentAmmo() const;

	virtual FVector GetSpawnLocation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> wMainMenu;

	// Variable to hold the widget After Creating it.
	UUserWidget* MyMainMenu;

	void Pause();

	class AGamePlayPlayerController* GetGamePlayController();

	UFUNCTION(BlueprintPure, Category="State")
		class AGameModePlayerState* GetGamePlayState();

	UFUNCTION(BlueprintCallable, Category = "Name")
		void SetName(FText NewName);

	UFUNCTION(BlueprintCallable, Category = "Name")
		FText GetName();

	void PlayDeathAnimation() const;

	UPROPERTY(EditAnywhere, Category = "Animation")
		UAnimMontage* DeathAnimation;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void DestroyWeapon() const;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		bool SpawnThirdPersonWeapon = false;
};
