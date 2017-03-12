// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "GamePlayPlayerController.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "GameModePlayerState.h"

void AGamePlayPlayerController::ShowMenu(UUserWidget* MyMainMenu)
{
	bShowMouseCursor = true;
	FInputModeUIOnly input = FInputModeUIOnly();
	SetInputMode(input);
	MyMainMenu->AddToViewport();
}

AGameModePlayerState* AGamePlayPlayerController::GetGamePlayState()
{
	return Cast<AGameModePlayerState>(PlayerState);
}
