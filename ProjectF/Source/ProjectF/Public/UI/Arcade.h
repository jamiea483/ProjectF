// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Arcade.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class PROJECTF_API UArcade : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		UButton* SaveSettingsButton;

};
