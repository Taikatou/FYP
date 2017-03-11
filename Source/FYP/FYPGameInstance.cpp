// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPGameInstance.h"
#include "UnrealNetwork.h"


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
