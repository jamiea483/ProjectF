// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AudioWidget.generated.h"

class UButton;
class USlider;
/**
 * 
 */
UCLASS()
class PROJECTF_API UAudioWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

		UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		UButton* SaveSettingButton;

		UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		USlider* MasterVolumeSlider;

	UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		USlider* SFXVolumeSlider;

	UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		USlider* MusicVolumeSlider;

	UPROPERTY(BlueprintReadWrite, Category = "Settings", meta = (BindWidget))
		USlider* VoiceVolumeSlider;

	UFUNCTION(BlueprintCallable)
		void SaveSettings();

};
