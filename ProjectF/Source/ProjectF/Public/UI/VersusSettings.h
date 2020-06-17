// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VersusSettings.generated.h"

class UButton;
class UTextBlock;
/**
 * 
 */
UCLASS()
class PROJECTF_API UVersusSettings : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UVersusSettings(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		UTextBlock* Rounds;

	UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		UTextBlock* TimeLimit;

	UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		UTextBlock* BestOf;

	UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		UButton* PlayButton;

	UFUNCTION()
		void UpdateScreen();

private:
	int roundsIndex;
	int timeIndex;
	int bestOfIndex;
	TArray<int> rounds = {1, 2, 3};
	TArray<float> time = { 60, 99, 00 };
	TArray <int> bestOf = {1, 3, 5, 7, 9};
};
