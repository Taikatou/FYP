// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "GameModePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API AGameModePlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 KillStreak = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 BestKillStreak = 0;

	UFUNCTION(BlueprintCallable, Category = "Kills")
		void SetKillStreak(int32 value);

	UFUNCTION(BlueprintPure, Category = "Kills")
		int32 GetKillStreak() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 TotalKills = 0;

	UFUNCTION(BlueprintCallable, Category = "Kills")
		void SetTotalKills(int32 value);

	UFUNCTION(BlueprintCallable, Category = "Kills")
		void ResetKillStreak();

	UFUNCTION(BlueprintPure, Category = "Kills")
		int32 GetTotalKills() const;

	UFUNCTION(BlueprintCallable, Category = "Death")
		void OnDeath();

	UFUNCTION(BlueprintCallable, Category = "Kills")
		void IncrementKills(int32 Killed = 1);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;

	UFUNCTION(BlueprintCallable, Category = "Name")
		void SetName(FText NewName);

	UFUNCTION(BlueprintCallable, Category = "Name")
		FText GetName() const;
	
};
