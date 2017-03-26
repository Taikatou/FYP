// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "CampaignGamePlayPlayerController.h"
#include "UserWidget.h"


void ACampaignGamePlayPlayerController::BeginPlay()
{
	if (wBloodHud) // Check if the Asset is assigned in the blueprint.
	{
		MyBloodHud = CreateWidget<UUserWidget>(this, wBloodHud);

		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (MyBloodHud)
		{
			//let add it to the view port
			MyBloodHud->AddToViewport();
		}
	}
	InitMenuSystem();
}


