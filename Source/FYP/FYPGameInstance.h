// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "FYPGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API UFYPGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(Replicated)
	int32 MaxLevelTime = 15*60;

	UPROPERTY(Replicated)
	int32 LevelTime = 5*60;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelInfo")
		FString MapName = FString(TEXT("Arena01"));
	
	UFUNCTION(BlueprintPure, Category = "LevelInfo")
		FString GetMapName() const;

	UFUNCTION(BlueprintCallable, Category = "LevelInfo")
		void SetMapName(FString name);

	UFUNCTION(BlueprintPure, Category = "LevelInfo")
		int32 GetMaxLevelTime() const;

	UFUNCTION(BlueprintPure, Category = "LevelInfo")
		int32 GetLevelTime() const;

	UFUNCTION(BlueprintCallable, Category = "LevelInfo")
		void SetLevelTime(int32 NewTime);
};
