// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class PROJECTF_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	UButton* ArcadeButton;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	UButton* VersusButton;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	UButton* NetplayButton;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	UButton* TrainingButton;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	UButton* OptionButton;

	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	class UArcade* WBP_Arcade;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	class UOption* WBP_Options;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	class UAudioWidget* WBP_Audio;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	class UGameplay* WBP_Gameplay;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	class ULobbyCreation* WBP_LobbyCreation;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	class UNetplay* WBP_Netplay;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	class UVersusSettings* WBP_VersusSettings;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	class UVersusPlayers* WBP_VersusPlayers;
	UPROPERTY(BlueprintReadWrite, Category = "Main Menu", meta = (BindWidget))
	class ULobbys* WBP_Lobbys;


};
