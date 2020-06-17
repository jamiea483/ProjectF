// Fill out your copyright notice in the Description page of Project Settings.


#include "FGameInstance.h"
#include "OnlineSessionSettings.h"
#include "..\..\Public\Misc\FGameInstance.h"


void UFGameInstance::Init()
{
	Super::Init();

	IOnlineSubsystem* SubSystem = IOnlineSubsystem::Get();
}

void UFGameInstance::Host(const FString ServerName, const FString password, int32 MaxPlayers, int32 PrivateSlots)
{
}

void UFGameInstance::Join(int32 Index)
{
}

void UFGameInstance::OnCreateSessionComplete(FName Session, bool Success)
{
}

void UFGameInstance::OnDestorySessionComplete(FName Session, bool Success)
{
}

void UFGameInstance::OnFindSessionsComplete(bool Success)
{
}

void UFGameInstance::OnSessionJoinComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
}
