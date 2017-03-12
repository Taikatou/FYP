// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "GamePlayPlayerController.generated.h"

class UUserWidget;
/**
 * 
 */
UCLASS()
class FYP_API AGamePlayPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void ShowMenu(UUserWidget* MyMainMenu);

	UFUNCTION(BlueprintPure, Category = "State")
		class AGameModePlayerState* GetGamePlayState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, replicated)
		int32 KillStreak = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, replicated)
		int32 BestKillStreak = 0;

	UFUNCTION(BlueprintCallable, Category = "Kills")
		void SetKillStreak(int32 value);

	UFUNCTION(BlueprintPure, Category = "Kills")
		int32 GetKillStreak() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, replicated)
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, replicated)
		FText Name;

	UFUNCTION(BlueprintCallable, Category = "Name")
		void SetName(FText NewName);

	UFUNCTION(BlueprintCallable, Category = "Name")
		FText GetName() const;
};
