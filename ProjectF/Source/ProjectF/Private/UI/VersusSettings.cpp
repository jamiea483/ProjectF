// Fill out your copyright notice in the Description page of Project Settings.


#include "VersusSettings.h"
#include "Components/TextBlock.h"

UVersusSettings::UVersusSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
	roundsIndex = 1;
	timeIndex = 1;
	bestOfIndex = 0;
}

void UVersusSettings::UpdateScreen()
{
	Rounds->Text.FromString(FString::FromInt(rounds[roundsIndex]));
	TimeLimit->Text.FromString(FString::FromInt(time[timeIndex]));
	BestOf->Text.FromString(FString::FromInt(bestOf[bestOfIndex]));
}