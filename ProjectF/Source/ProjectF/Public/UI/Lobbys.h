// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Lobbys.generated.h"

USTRUCT()
struct FServerStruct
{
	GENERATED_BODY()

		FString Name;

	uint32 CurrentPlayers;

	uint32 MaxPlayers;

	FString UserName;
};
/**
 * 
 */
UCLASS()
class PROJECTF_API ULobbys : public UUserWidget
{
	GENERATED_BODY()
	
};
