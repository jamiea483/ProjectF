// Fill out your copyright notice in the Description page of Project Settings.


#include "FGameInstance.h"
#include "OnlineSessionSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Lobbys.h"
#include "..\..\Public\Misc\FGameInstance.h"

static const FName SESSION_NAME = TEXT("GameSession");
static const FName SERVER_NAME_SETTINGS_KEY = TEXT("ServerName");
static const FName PASSWORD_SETTINGS_KEY = TEXT("Password");

void UFGameInstance::Init()
{
	Super::Init();

	IOnlineSubsystem* SubSystem = IOnlineSubsystem::Get();
	if (SubSystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found subsystem %s."), *SubSystem->GetSubsystemName().ToString());
		SessionInterface = SubSystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UFGameInstance::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UFGameInstance::OnDestorySessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UFGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UFGameInstance::OnSessionJoinComplete);
			UE_LOG(LogTemp, Warning, TEXT("Found Online Session Interface."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No subsystem found."));
	}
}

void UFGameInstance::Host(const FString ServerName, const FString password, int32 MaxPlayers, int32 PrivateSlots)
{
	if (SessionInterface.IsValid())
	{
		if (ServerName == "")
		{
			ServerSettings.ServerName = TEXT("Test");
		}
		else
		{
			ServerSettings.ServerName = ServerName;
		}
		ServerSettings.SetPassword = password;
		ServerSettings.PublicSlots = MaxPlayers;
		ServerSettings.PrivateSlots = PrivateSlots;
		auto ExistingSession = SessionInterface->GetNamedSession(SESSION_NAME);
		if (!ExistingSession)
		{
			CreateSession();
		}
		else
		{
			DestroyExistingSession();
		}
	}
}

void UFGameInstance::CreateSession()
{
	FOnlineSessionSettings SessionSettings;
	if (IOnlineSubsystem::Get()->GetSubsystemName() == "NULL")
	{
		SessionSettings.bIsLANMatch = true;
	}
	else
	{
		SessionSettings.bIsLANMatch = false;
	}
	SessionSettings.NumPublicConnections = ServerSettings.PublicSlots;
	SessionSettings.NumPrivateConnections = ServerSettings.PrivateSlots;
	SessionSettings.bUsesPresence = true;
	SessionSettings.bShouldAdvertise = true;
	UE_LOG(LogTemp, Warning, TEXT("Server Name is %s."), *ServerSettings.ServerName);
	SessionSettings.Set(SERVER_NAME_SETTINGS_KEY, ServerSettings.ServerName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	SessionInterface->CreateSession(0, SESSION_NAME, SessionSettings);
}

void UFGameInstance::DestroyExistingSession()
{
	SessionInterface->DestroySession(SESSION_NAME);
}

void UFGameInstance::Join(int32 Index)
{
	if (!SessionInterface.IsValid())return;
	if (UGameplayStatics::GetPlayerControllerFromID(GetWorld(), 0))
	{
		JoinFunction(Index);
	}
}

void UFGameInstance::JoinFunction(const int32 &Index)
{
	FInputModeGameOnly inputmode;
	UGameplayStatics::GetPlayerControllerFromID(GetWorld(), 0)->SetInputMode(inputmode);
	SessionInterface->JoinSession(0, SESSION_NAME, SessionSearch->SearchResults[Index]);
}

void UFGameInstance::OnCreateSessionComplete(FName Session, bool Success)
{
	if (!Success)
	{
		return;
	}
	UWorld* world = GetWorld();
	if (world)
	{
		///ToDo::Make a lobby map.
		world->ServerTravel("");
	}
}

void UFGameInstance::OnDestorySessionComplete(FName Session, bool Success)
{
	if (Success)
	{
		///ToDo: destroy session when there is a dup or leaving a session.
		UE_LOG(LogTemp, Warning, TEXT("Destroyed session."));
	}
}

void UFGameInstance::OnFindSessionsComplete(bool Success)
{
	if (Success && SessionSearch.IsValid())
	{
		if (SessionSearch->SearchResults.Num() > 0)
		{
			TArray<FServerStruct> ServerData;
			for (const FOnlineSessionSearchResult& SearchResult: SessionSearch->SearchResults)
			{
				FServerStruct Data;

				Data.MaxPlayers = SearchResult.Session.SessionSettings.NumPublicConnections;
				Data.CurrentPlayers = Data.MaxPlayers - SearchResult.Session.NumOpenPublicConnections;
				Data.UserName = SearchResult.Session.OwningUserName;
				FString NewServerName;
				if (SearchResult.Session.SessionSettings.Get(SERVER_NAME_SETTINGS_KEY, NewServerName))
				{
					Data.Name = NewServerName;
				}
				else
				{
					Data.Name = "Could not find name.";
				}

				ServerData.Add(Data);
			}
			///TODO::send the serverdata to the lobby widget.
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("no Server found"));
		}
	}
}

void UFGameInstance::OnSessionJoinComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (!SessionInterface.IsValid())return;
	FString Address;
		if(!SessionInterface->GetResolvedConnectString(SessionName, Address))return;
		{
			UGameplayStatics::GetPlayerControllerFromID(GetWorld(), 0)->ClientTravel(Address, ETravelType::TRAVEL_Relative);
		}
}
