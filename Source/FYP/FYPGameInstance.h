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
	int32 LevelTime = 10;

public:
	UFYPGameInstance();

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

	/** Delegate for destroying a session */
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;

	/** Handle to registered delegate for destroying a session */
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;

	/**
	*	Delegate fired when a destroying an online session has completed
	*
	*	@param SessionName the name of the session this callback is for
	*	@param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	virtual void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
};
