// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyCreation.h"
#include "Components/TextBlock.h"

ULobbyCreation::ULobbyCreation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
	 roundsIndex = 1;
	 timeIndex = 1;
	 bestOfIndex = 0;
	 maxIndex = 0;
	 slotsIndex = 0;
}

void ULobbyCreation::UpdateScreen()
{
	Rounds->Text.FromString(FString::FromInt(rounds[roundsIndex]));
	TimeLimit->Text.FromString(FString::FromInt(time[timeIndex]));
	BestOf->Text.FromString(FString::FromInt(bestOf[bestOfIndex]));
	MaxPlayers->Text.FromString(FString::FromInt(max[maxIndex]));
	BestOf->Text.FromString(FString::FromInt(slots[slotsIndex]));
}