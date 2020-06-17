// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Netplay.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class PROJECTF_API UNetplay : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, Category = "Netplay", meta = (BindWidget))
		UButton* LobbysButton;

	UPROPERTY(BlueprintReadWrite, Category = "Netplay", meta = (BindWidget))
		UButton* LobbyCreationButton;

	UPROPERTY(BlueprintReadWrite, Category = "Netplay", meta = (BindWidget))
		UButton* QuickMatchButton;
};
