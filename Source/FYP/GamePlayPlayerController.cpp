// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "GamePlayPlayerController.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

void AGamePlayPlayerController::ShowMenu(UUserWidget* MyMainMenu)
{
	bShowMouseCursor = true;
	MyMainMenu->AddToViewport();
}
