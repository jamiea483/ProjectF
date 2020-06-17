// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Option.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class PROJECTF_API UOption : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		UButton* GameplayButton;

	UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		UButton* AudioButton;

};
