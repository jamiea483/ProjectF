// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartScreen.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTF_API UStartScreen : public UUserWidget
{
	GENERATED_BODY()
	

public:

	UFUNCTION(BlueprintCallable)
		void ChangeScreen();

};
