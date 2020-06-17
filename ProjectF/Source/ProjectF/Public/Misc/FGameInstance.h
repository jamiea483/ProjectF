// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "OnlineSubSystem.h"
#include "OnlineSessionInterface.h"

#include "FGameInstance.generated.h"

class UMainMenu;
class FOnlineSessionSearch;

/**
 * 
 */
UCLASS()
class PROJECTF_API UFGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	virtual void Init()override;

	UFUNCTION(BlueprintCallable)
		void Host(const FString ServerName, const FString password, int32 MaxPlayers, int32 PrivateSlots);

		UFUNCTION(BlueprintCallable)
		void Join(int32 Index);


protected:

	IOnlineSessionPtr SessionInterface;

	void OnCreateSessionComplete(FName Session, bool Success);

	void OnDestorySessionComplete(FName Session, bool Success);

	void OnFindSessionsComplete(bool Success);

	void OnSessionJoinComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	TSharedPtr<FOnlineSessionSearch> SessionSearch;

};
