// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPGameInstance.h"
#include "UnrealNetwork.h"
#include "OnlineSubsystem.h"

UFYPGameInstance::UFYPGameInstance()
{
	/** Bind function for DESTROYING a Session */
	OnDestroySessionCompleteDelegate = FOnDestroySessionCompleteDelegate::CreateUObject(this, &UFYPGameInstance::OnDestroySessionComplete);
}

FString UFYPGameInstance::GetMapName() const
{
	return MapName;
}

void UFYPGameInstance::SetMapName(FString name)
{
	MapName = name;
}

int32 UFYPGameInstance::GetMaxLevelTime() const
{
	return MaxLevelTime;
}

int32 UFYPGameInstance::GetLevelTime() const
{
	return LevelTime;
}

void UFYPGameInstance::SetLevelTime(int32 NewTime)
{
	if(NewTime > 0 && NewTime <= MaxLevelTime)
	{
		LevelTime = NewTime;
	}
}

void UFYPGameInstance::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	DOREPLIFETIME(UFYPGameInstance, MaxLevelTime);
	DOREPLIFETIME(UFYPGameInstance, LevelTime);
}

void UFYPGameInstance::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("OnDestroySessionComplete %s, %d"), *SessionName.ToString(), bWasSuccessful));

	// Get the OnlineSubsystem we want to work with
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		// Get the SessionInterface from the OnlineSubsystem
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

		if (Sessions.IsValid())
		{
			// Clear the Delegate
			Sessions->ClearOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegateHandle);

			// If it was successful, we just load another level (could be a MainMenu!)
			if (bWasSuccessful)
			{
				UGameplayStatics::OpenLevel(GetWorld(), "ThirdPersonExampleMap", true);
			}
		}
	}
}
