// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyCreation.generated.h"

class UButton;
class UTextBlock;
/**
 * 
 */
UCLASS()
class PROJECTF_API ULobbyCreation : public UUserWidget
{
	GENERATED_BODY()
	
public:

	ULobbyCreation(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, Category = "LobbyCreation", meta = (BindWidget))
		UTextBlock* Rounds;

	UPROPERTY(BlueprintReadWrite, Category = "LobbyCreation", meta = (BindWidget))
		UTextBlock* TimeLimit;

	UPROPERTY(BlueprintReadWrite, Category = "LobbyCreation", meta = (BindWidget))
		UTextBlock* BestOf;

	UPROPERTY(BlueprintReadWrite, Category = "LobbyCreation", meta = (BindWidget))
		UTextBlock* MaxPlayers;

	UPROPERTY(BlueprintReadWrite, Category = "LobbyCreation", meta = (BindWidget))
		UTextBlock* PrivateSlot;

	UPROPERTY(BlueprintReadWrite, Category = "LobbyCreation", meta = (BindWidget))
		UButton* CreateButton;

	UFUNCTION()
		void UpdateScreen();

private:
	int roundsIndex;
	int timeIndex;
	int bestOfIndex;
	int maxIndex;
	int slotsIndex;
	TArray<int> rounds = { 1, 2, 3 };
	TArray<float> time = { 60, 99, 00 };
	TArray <int> bestOf = { 1, 3, 5, 7, 9 };
	TArray<int> max = { 2,3,4,5,6,7 };
	TArray<int> slots = { 1,2,3,4,5,6,7 };
};
