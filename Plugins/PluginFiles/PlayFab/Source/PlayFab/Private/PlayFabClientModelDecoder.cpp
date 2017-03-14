//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Client
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabClientModelDecoder.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Client API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

FClientGetPhotonAuthenticationTokenResult UPlayFabClientModelDecoder::decodeGetPhotonAuthenticationTokenResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPhotonAuthenticationTokenResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PhotonCustomAuthenticationToken = !(dataObj->HasField("PhotonCustomAuthenticationToken")) ? TEXT("") : dataObj->GetStringField("PhotonCustomAuthenticationToken");

    return tempStruct;
}

FClientGetWindowsHelloChallengeResponse UPlayFabClientModelDecoder::decodeGetWindowsHelloChallengeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetWindowsHelloChallengeResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Challenge = !(dataObj->HasField("Challenge")) ? TEXT("") : dataObj->GetStringField("Challenge");

    return tempStruct;
}

FClientLinkWindowsHelloAccountResponse UPlayFabClientModelDecoder::decodeLinkWindowsHelloAccountResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkWindowsHelloAccountResponse tempStruct;


    return tempStruct;
}

FClientLoginResult UPlayFabClientModelDecoder::decodeLoginResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLoginResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.SessionTicket = !(dataObj->HasField("SessionTicket")) ? TEXT("") : dataObj->GetStringField("SessionTicket");
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.NewlyCreated = !(dataObj->HasField("NewlyCreated")) ? false : dataObj->GetBoolField("NewlyCreated");
    tempStruct.SettingsForUser = !(dataObj->HasField("SettingsForUser")) ? nullptr : dataObj->GetObjectField("SettingsForUser");
    tempStruct.LastLoginTime = !(dataObj->HasField("LastLoginTime")) ? TEXT("") : dataObj->GetStringField("LastLoginTime");
    tempStruct.InfoResultPayload = !(dataObj->HasField("InfoResultPayload")) ? nullptr : dataObj->GetObjectField("InfoResultPayload");

    return tempStruct;
}

FClientRegisterPlayFabUserResult UPlayFabClientModelDecoder::decodeRegisterPlayFabUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRegisterPlayFabUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.SessionTicket = !(dataObj->HasField("SessionTicket")) ? TEXT("") : dataObj->GetStringField("SessionTicket");
    tempStruct.Username = !(dataObj->HasField("Username")) ? TEXT("") : dataObj->GetStringField("Username");
    tempStruct.SettingsForUser = !(dataObj->HasField("SettingsForUser")) ? nullptr : dataObj->GetObjectField("SettingsForUser");

    return tempStruct;
}

FClientUnlinkWindowsHelloAccountResponse UPlayFabClientModelDecoder::decodeUnlinkWindowsHelloAccountResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkWindowsHelloAccountResponse tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

FClientAddGenericIDResult UPlayFabClientModelDecoder::decodeAddGenericIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAddGenericIDResult tempStruct;


    return tempStruct;
}

FClientAddUsernamePasswordResult UPlayFabClientModelDecoder::decodeAddUsernamePasswordResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAddUsernamePasswordResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Username = !(dataObj->HasField("Username")) ? TEXT("") : dataObj->GetStringField("Username");

    return tempStruct;
}

FClientGetAccountInfoResult UPlayFabClientModelDecoder::decodeGetAccountInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetAccountInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AccountInfo = !(dataObj->HasField("AccountInfo")) ? nullptr : dataObj->GetObjectField("AccountInfo");

    return tempStruct;
}

FClientGetPlayerCombinedInfoResult UPlayFabClientModelDecoder::decodeGetPlayerCombinedInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayerCombinedInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.InfoResultPayload = !(dataObj->HasField("InfoResultPayload")) ? nullptr : dataObj->GetObjectField("InfoResultPayload");

    return tempStruct;
}

FClientGetPlayFabIDsFromFacebookIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromFacebookIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromFacebookIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromGameCenterIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGameCenterIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromGameCenterIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromGenericIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGenericIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromGenericIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromGoogleIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGoogleIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromGoogleIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromKongregateIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromKongregateIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromKongregateIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromSteamIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromSteamIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromSteamIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromTwitchIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromTwitchIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromTwitchIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientLinkAndroidDeviceIDResult UPlayFabClientModelDecoder::decodeLinkAndroidDeviceIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkAndroidDeviceIDResult tempStruct;


    return tempStruct;
}

FClientLinkCustomIDResult UPlayFabClientModelDecoder::decodeLinkCustomIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkCustomIDResult tempStruct;


    return tempStruct;
}

FClientLinkFacebookAccountResult UPlayFabClientModelDecoder::decodeLinkFacebookAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkFacebookAccountResult tempStruct;


    return tempStruct;
}

FClientLinkGameCenterAccountResult UPlayFabClientModelDecoder::decodeLinkGameCenterAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkGameCenterAccountResult tempStruct;


    return tempStruct;
}

FClientLinkGoogleAccountResult UPlayFabClientModelDecoder::decodeLinkGoogleAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkGoogleAccountResult tempStruct;


    return tempStruct;
}

FClientLinkIOSDeviceIDResult UPlayFabClientModelDecoder::decodeLinkIOSDeviceIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkIOSDeviceIDResult tempStruct;


    return tempStruct;
}

FClientLinkKongregateAccountResult UPlayFabClientModelDecoder::decodeLinkKongregateAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkKongregateAccountResult tempStruct;


    return tempStruct;
}

FClientLinkSteamAccountResult UPlayFabClientModelDecoder::decodeLinkSteamAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkSteamAccountResult tempStruct;


    return tempStruct;
}

FClientLinkTwitchAccountResult UPlayFabClientModelDecoder::decodeLinkTwitchAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkTwitchAccountResult tempStruct;


    return tempStruct;
}

FClientRemoveGenericIDResult UPlayFabClientModelDecoder::decodeRemoveGenericIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRemoveGenericIDResult tempStruct;


    return tempStruct;
}

FClientReportPlayerClientResult UPlayFabClientModelDecoder::decodeReportPlayerClientResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientReportPlayerClientResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Updated = !(dataObj->HasField("Updated")) ? false : dataObj->GetBoolField("Updated");
    tempStruct.SubmissionsRemaining = !(dataObj->HasField("SubmissionsRemaining")) ? 0 : int(dataObj->GetNumberField("SubmissionsRemaining"));

    return tempStruct;
}

FClientSendAccountRecoveryEmailResult UPlayFabClientModelDecoder::decodeSendAccountRecoveryEmailResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientSendAccountRecoveryEmailResult tempStruct;


    return tempStruct;
}

FClientUnlinkAndroidDeviceIDResult UPlayFabClientModelDecoder::decodeUnlinkAndroidDeviceIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkAndroidDeviceIDResult tempStruct;


    return tempStruct;
}

FClientUnlinkCustomIDResult UPlayFabClientModelDecoder::decodeUnlinkCustomIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkCustomIDResult tempStruct;


    return tempStruct;
}

FClientUnlinkFacebookAccountResult UPlayFabClientModelDecoder::decodeUnlinkFacebookAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkFacebookAccountResult tempStruct;


    return tempStruct;
}

FClientUnlinkGameCenterAccountResult UPlayFabClientModelDecoder::decodeUnlinkGameCenterAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkGameCenterAccountResult tempStruct;


    return tempStruct;
}

FClientUnlinkGoogleAccountResult UPlayFabClientModelDecoder::decodeUnlinkGoogleAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkGoogleAccountResult tempStruct;


    return tempStruct;
}

FClientUnlinkIOSDeviceIDResult UPlayFabClientModelDecoder::decodeUnlinkIOSDeviceIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkIOSDeviceIDResult tempStruct;


    return tempStruct;
}

FClientUnlinkKongregateAccountResult UPlayFabClientModelDecoder::decodeUnlinkKongregateAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkKongregateAccountResult tempStruct;


    return tempStruct;
}

FClientUnlinkSteamAccountResult UPlayFabClientModelDecoder::decodeUnlinkSteamAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkSteamAccountResult tempStruct;


    return tempStruct;
}

FClientUnlinkTwitchAccountResult UPlayFabClientModelDecoder::decodeUnlinkTwitchAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkTwitchAccountResult tempStruct;


    return tempStruct;
}

FClientEmptyResult UPlayFabClientModelDecoder::decodeEmptyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientEmptyResult tempStruct;


    return tempStruct;
}

FClientUpdateUserTitleDisplayNameResult UPlayFabClientModelDecoder::decodeUpdateUserTitleDisplayNameResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateUserTitleDisplayNameResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DisplayName = !(dataObj->HasField("DisplayName")) ? TEXT("") : dataObj->GetStringField("DisplayName");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

FClientGetLeaderboardResult UPlayFabClientModelDecoder::decodeGetLeaderboardResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));
    tempStruct.NextReset = !(dataObj->HasField("NextReset")) ? TEXT("") : dataObj->GetStringField("NextReset");

    return tempStruct;
}

FClientGetFriendLeaderboardAroundPlayerResult UPlayFabClientModelDecoder::decodeGetFriendLeaderboardAroundPlayerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetFriendLeaderboardAroundPlayerResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));
    tempStruct.NextReset = !(dataObj->HasField("NextReset")) ? TEXT("") : dataObj->GetStringField("NextReset");

    return tempStruct;
}

FClientGetLeaderboardAroundPlayerResult UPlayFabClientModelDecoder::decodeGetLeaderboardAroundPlayerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardAroundPlayerResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));
    tempStruct.NextReset = !(dataObj->HasField("NextReset")) ? TEXT("") : dataObj->GetStringField("NextReset");

    return tempStruct;
}

FClientGetPlayerStatisticsResult UPlayFabClientModelDecoder::decodeGetPlayerStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayerStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Statistics = !(dataObj->HasField("Statistics")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Statistics");

    return tempStruct;
}

FClientGetPlayerStatisticVersionsResult UPlayFabClientModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayerStatisticVersionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.StatisticVersions = !(dataObj->HasField("StatisticVersions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("StatisticVersions");

    return tempStruct;
}

FClientGetUserDataResult UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}

FClientUpdatePlayerStatisticsResult UPlayFabClientModelDecoder::decodeUpdatePlayerStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdatePlayerStatisticsResult tempStruct;


    return tempStruct;
}

FClientUpdateUserDataResult UPlayFabClientModelDecoder::decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

FClientGetCatalogItemsResult UPlayFabClientModelDecoder::decodeGetCatalogItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCatalogItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Catalog = !(dataObj->HasField("Catalog")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Catalog");

    return tempStruct;
}

FClientGetPublisherDataResult UPlayFabClientModelDecoder::decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPublisherDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FClientGetStoreItemsResult UPlayFabClientModelDecoder::decodeGetStoreItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetStoreItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Store = !(dataObj->HasField("Store")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Store");
    GetEnumValueFromString<EPfSourceType>(TEXT("EPfSourceType"), dataObj->GetStringField("Source"), tempStruct.Source);
    tempStruct.CatalogVersion = !(dataObj->HasField("CatalogVersion")) ? TEXT("") : dataObj->GetStringField("CatalogVersion");
    tempStruct.StoreId = !(dataObj->HasField("StoreId")) ? TEXT("") : dataObj->GetStringField("StoreId");
    tempStruct.MarketingData = !(dataObj->HasField("MarketingData")) ? nullptr : dataObj->GetObjectField("MarketingData");

    return tempStruct;
}

FClientGetTimeResult UPlayFabClientModelDecoder::decodeGetTimeResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetTimeResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Time = !(dataObj->HasField("Time")) ? TEXT("") : dataObj->GetStringField("Time");

    return tempStruct;
}

FClientGetTitleDataResult UPlayFabClientModelDecoder::decodeGetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetTitleDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FClientGetTitleNewsResult UPlayFabClientModelDecoder::decodeGetTitleNewsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetTitleNewsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.News = !(dataObj->HasField("News")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("News");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

FClientModifyUserVirtualCurrencyResult UPlayFabClientModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientModifyUserVirtualCurrencyResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? TEXT("") : dataObj->GetStringField("VirtualCurrency");
    tempStruct.BalanceChange = !(dataObj->HasField("BalanceChange")) ? 0 : int(dataObj->GetNumberField("BalanceChange"));
    tempStruct.Balance = !(dataObj->HasField("Balance")) ? 0 : int(dataObj->GetNumberField("Balance"));

    return tempStruct;
}

FClientConfirmPurchaseResult UPlayFabClientModelDecoder::decodeConfirmPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientConfirmPurchaseResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.OrderId = !(dataObj->HasField("OrderId")) ? TEXT("") : dataObj->GetStringField("OrderId");
    tempStruct.PurchaseDate = !(dataObj->HasField("PurchaseDate")) ? TEXT("") : dataObj->GetStringField("PurchaseDate");
    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FClientConsumeItemResult UPlayFabClientModelDecoder::decodeConsumeItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientConsumeItemResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ItemInstanceId = !(dataObj->HasField("ItemInstanceId")) ? TEXT("") : dataObj->GetStringField("ItemInstanceId");
    tempStruct.RemainingUses = !(dataObj->HasField("RemainingUses")) ? 0 : int(dataObj->GetNumberField("RemainingUses"));

    return tempStruct;
}

FClientGetCharacterInventoryResult UPlayFabClientModelDecoder::decodeGetCharacterInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterInventoryResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");
    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FClientGetPurchaseResult UPlayFabClientModelDecoder::decodeGetPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPurchaseResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.OrderId = !(dataObj->HasField("OrderId")) ? TEXT("") : dataObj->GetStringField("OrderId");
    tempStruct.PaymentProvider = !(dataObj->HasField("PaymentProvider")) ? TEXT("") : dataObj->GetStringField("PaymentProvider");
    tempStruct.TransactionId = !(dataObj->HasField("TransactionId")) ? TEXT("") : dataObj->GetStringField("TransactionId");
    tempStruct.TransactionStatus = !(dataObj->HasField("TransactionStatus")) ? TEXT("") : dataObj->GetStringField("TransactionStatus");
    tempStruct.PurchaseDate = !(dataObj->HasField("PurchaseDate")) ? TEXT("") : dataObj->GetStringField("PurchaseDate");
    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FClientGetUserInventoryResult UPlayFabClientModelDecoder::decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetUserInventoryResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FClientPayForPurchaseResult UPlayFabClientModelDecoder::decodePayForPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientPayForPurchaseResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.OrderId = !(dataObj->HasField("OrderId")) ? TEXT("") : dataObj->GetStringField("OrderId");
    GetEnumValueFromString<ETransactionStatus>(TEXT("ETransactionStatus"), dataObj->GetStringField("Status"), tempStruct.Status);
    tempStruct.VCAmount = !(dataObj->HasField("VCAmount")) ? nullptr : dataObj->GetObjectField("VCAmount");
    tempStruct.PurchaseCurrency = !(dataObj->HasField("PurchaseCurrency")) ? TEXT("") : dataObj->GetStringField("PurchaseCurrency");
    tempStruct.PurchasePrice = !(dataObj->HasField("PurchasePrice")) ? 0 : int(dataObj->GetNumberField("PurchasePrice"));
    tempStruct.CreditApplied = !(dataObj->HasField("CreditApplied")) ? 0 : int(dataObj->GetNumberField("CreditApplied"));
    tempStruct.ProviderData = !(dataObj->HasField("ProviderData")) ? TEXT("") : dataObj->GetStringField("ProviderData");
    tempStruct.PurchaseConfirmationPageURL = !(dataObj->HasField("PurchaseConfirmationPageURL")) ? TEXT("") : dataObj->GetStringField("PurchaseConfirmationPageURL");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");
    tempStruct.ProviderToken = !(dataObj->HasField("ProviderToken")) ? TEXT("") : dataObj->GetStringField("ProviderToken");

    return tempStruct;
}

FClientPurchaseItemResult UPlayFabClientModelDecoder::decodePurchaseItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientPurchaseItemResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FClientRedeemCouponResult UPlayFabClientModelDecoder::decodeRedeemCouponResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRedeemCouponResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.GrantedItems = !(dataObj->HasField("GrantedItems")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GrantedItems");

    return tempStruct;
}

FClientStartPurchaseResult UPlayFabClientModelDecoder::decodeStartPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientStartPurchaseResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.OrderId = !(dataObj->HasField("OrderId")) ? TEXT("") : dataObj->GetStringField("OrderId");
    tempStruct.Contents = !(dataObj->HasField("Contents")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Contents");
    tempStruct.PaymentOptions = !(dataObj->HasField("PaymentOptions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("PaymentOptions");
    tempStruct.VirtualCurrencyBalances = !(dataObj->HasField("VirtualCurrencyBalances")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyBalances");

    return tempStruct;
}

FClientUnlockContainerItemResult UPlayFabClientModelDecoder::decodeUnlockContainerItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlockContainerItemResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.UnlockedItemInstanceId = !(dataObj->HasField("UnlockedItemInstanceId")) ? TEXT("") : dataObj->GetStringField("UnlockedItemInstanceId");
    tempStruct.UnlockedWithItemInstanceId = !(dataObj->HasField("UnlockedWithItemInstanceId")) ? TEXT("") : dataObj->GetStringField("UnlockedWithItemInstanceId");
    tempStruct.GrantedItems = !(dataObj->HasField("GrantedItems")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GrantedItems");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////

FClientAddFriendResult UPlayFabClientModelDecoder::decodeAddFriendResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAddFriendResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");

    return tempStruct;
}

FClientGetFriendsListResult UPlayFabClientModelDecoder::decodeGetFriendsListResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetFriendsListResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Friends = !(dataObj->HasField("Friends")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Friends");

    return tempStruct;
}

FClientRemoveFriendResult UPlayFabClientModelDecoder::decodeRemoveFriendResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRemoveFriendResult tempStruct;


    return tempStruct;
}

FClientSetFriendTagsResult UPlayFabClientModelDecoder::decodeSetFriendTagsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientSetFriendTagsResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// IOS-Specific APIs
//////////////////////////////////////////////////////

FClientRegisterForIOSPushNotificationResult UPlayFabClientModelDecoder::decodeRegisterForIOSPushNotificationResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRegisterForIOSPushNotificationResult tempStruct;


    return tempStruct;
}

FClientRestoreIOSPurchasesResult UPlayFabClientModelDecoder::decodeRestoreIOSPurchasesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRestoreIOSPurchasesResult tempStruct;


    return tempStruct;
}

FClientValidateIOSReceiptResult UPlayFabClientModelDecoder::decodeValidateIOSReceiptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientValidateIOSReceiptResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////

FClientCurrentGamesResult UPlayFabClientModelDecoder::decodeCurrentGamesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientCurrentGamesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Games = !(dataObj->HasField("Games")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Games");
    tempStruct.PlayerCount = !(dataObj->HasField("PlayerCount")) ? 0 : int(dataObj->GetNumberField("PlayerCount"));
    tempStruct.GameCount = !(dataObj->HasField("GameCount")) ? 0 : int(dataObj->GetNumberField("GameCount"));

    return tempStruct;
}

FClientGameServerRegionsResult UPlayFabClientModelDecoder::decodeGameServerRegionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGameServerRegionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Regions = !(dataObj->HasField("Regions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Regions");

    return tempStruct;
}

FClientMatchmakeResult UPlayFabClientModelDecoder::decodeMatchmakeResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientMatchmakeResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.LobbyID = !(dataObj->HasField("LobbyID")) ? TEXT("") : dataObj->GetStringField("LobbyID");
    tempStruct.ServerHostname = !(dataObj->HasField("ServerHostname")) ? TEXT("") : dataObj->GetStringField("ServerHostname");
    tempStruct.ServerPort = !(dataObj->HasField("ServerPort")) ? 0 : int(dataObj->GetNumberField("ServerPort"));
    tempStruct.Ticket = !(dataObj->HasField("Ticket")) ? TEXT("") : dataObj->GetStringField("Ticket");
    tempStruct.Expires = !(dataObj->HasField("Expires")) ? TEXT("") : dataObj->GetStringField("Expires");
    tempStruct.PollWaitTimeMS = !(dataObj->HasField("PollWaitTimeMS")) ? 0 : int(dataObj->GetNumberField("PollWaitTimeMS"));
    GetEnumValueFromString<EMatchmakeStatus>(TEXT("EMatchmakeStatus"), dataObj->GetStringField("Status"), tempStruct.Status);

    return tempStruct;
}

FClientStartGameResult UPlayFabClientModelDecoder::decodeStartGameResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientStartGameResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.LobbyID = !(dataObj->HasField("LobbyID")) ? TEXT("") : dataObj->GetStringField("LobbyID");
    tempStruct.ServerHostname = !(dataObj->HasField("ServerHostname")) ? TEXT("") : dataObj->GetStringField("ServerHostname");
    tempStruct.ServerPort = !(dataObj->HasField("ServerPort")) ? 0 : int(dataObj->GetNumberField("ServerPort"));
    tempStruct.Ticket = !(dataObj->HasField("Ticket")) ? TEXT("") : dataObj->GetStringField("Ticket");
    tempStruct.Expires = !(dataObj->HasField("Expires")) ? TEXT("") : dataObj->GetStringField("Expires");
    tempStruct.Password = !(dataObj->HasField("Password")) ? TEXT("") : dataObj->GetStringField("Password");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Android-Specific APIs
//////////////////////////////////////////////////////

FClientAndroidDevicePushNotificationRegistrationResult UPlayFabClientModelDecoder::decodeAndroidDevicePushNotificationRegistrationResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAndroidDevicePushNotificationRegistrationResult tempStruct;


    return tempStruct;
}

FClientValidateGooglePlayPurchaseResult UPlayFabClientModelDecoder::decodeValidateGooglePlayPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientValidateGooglePlayPurchaseResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

FClientWriteEventResponse UPlayFabClientModelDecoder::decodeWriteEventResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientWriteEventResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.EventId = !(dataObj->HasField("EventId")) ? TEXT("") : dataObj->GetStringField("EventId");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

FClientAddSharedGroupMembersResult UPlayFabClientModelDecoder::decodeAddSharedGroupMembersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAddSharedGroupMembersResult tempStruct;


    return tempStruct;
}

FClientCreateSharedGroupResult UPlayFabClientModelDecoder::decodeCreateSharedGroupResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientCreateSharedGroupResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.SharedGroupId = !(dataObj->HasField("SharedGroupId")) ? TEXT("") : dataObj->GetStringField("SharedGroupId");

    return tempStruct;
}

FClientGetSharedGroupDataResult UPlayFabClientModelDecoder::decodeGetSharedGroupDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetSharedGroupDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");
    tempStruct.Members = !(dataObj->HasField("Members")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Members"), TEXT(","));

    return tempStruct;
}

FClientRemoveSharedGroupMembersResult UPlayFabClientModelDecoder::decodeRemoveSharedGroupMembersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRemoveSharedGroupMembersResult tempStruct;


    return tempStruct;
}

FClientUpdateSharedGroupDataResult UPlayFabClientModelDecoder::decodeUpdateSharedGroupDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateSharedGroupDataResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Sony-specific APIs
//////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

FClientExecuteCloudScriptResult UPlayFabClientModelDecoder::decodeExecuteCloudScriptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientExecuteCloudScriptResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.FunctionName = !(dataObj->HasField("FunctionName")) ? TEXT("") : dataObj->GetStringField("FunctionName");
    tempStruct.Revision = !(dataObj->HasField("Revision")) ? 0 : int(dataObj->GetNumberField("Revision"));
    tempStruct.FunctionResult = !(dataObj->HasField("FunctionResult")) ? nullptr : dataObj->GetObjectField("FunctionResult");
    tempStruct.Logs = !(dataObj->HasField("Logs")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Logs");
    tempStruct.ExecutionTimeSeconds = !(dataObj->HasField("ExecutionTimeSeconds")) ? 0 : int(dataObj->GetNumberField("ExecutionTimeSeconds"));
    tempStruct.ProcessorTimeSeconds = !(dataObj->HasField("ProcessorTimeSeconds")) ? 0 : int(dataObj->GetNumberField("ProcessorTimeSeconds"));
    tempStruct.MemoryConsumedBytes = !(dataObj->HasField("MemoryConsumedBytes")) ? 0 : int(dataObj->GetNumberField("MemoryConsumedBytes"));
    tempStruct.APIRequestsIssued = !(dataObj->HasField("APIRequestsIssued")) ? 0 : int(dataObj->GetNumberField("APIRequestsIssued"));
    tempStruct.HttpRequestsIssued = !(dataObj->HasField("HttpRequestsIssued")) ? 0 : int(dataObj->GetNumberField("HttpRequestsIssued"));
    tempStruct.Error = !(dataObj->HasField("Error")) ? nullptr : dataObj->GetObjectField("Error");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

FClientGetContentDownloadUrlResult UPlayFabClientModelDecoder::decodeGetContentDownloadUrlResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetContentDownloadUrlResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.URL = !(dataObj->HasField("URL")) ? TEXT("") : dataObj->GetStringField("URL");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

FClientListUsersCharactersResult UPlayFabClientModelDecoder::decodeListUsersCharactersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientListUsersCharactersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Characters = !(dataObj->HasField("Characters")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Characters");

    return tempStruct;
}

FClientGetCharacterLeaderboardResult UPlayFabClientModelDecoder::decodeGetCharacterLeaderboardResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterLeaderboardResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetCharacterStatisticsResult UPlayFabClientModelDecoder::decodeGetCharacterStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CharacterStatistics = !(dataObj->HasField("CharacterStatistics")) ? nullptr : dataObj->GetObjectField("CharacterStatistics");

    return tempStruct;
}

FClientGetLeaderboardAroundCharacterResult UPlayFabClientModelDecoder::decodeGetLeaderboardAroundCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardAroundCharacterResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetLeaderboardForUsersCharactersResult UPlayFabClientModelDecoder::decodeGetLeaderboardForUsersCharactersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardForUsersCharactersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGrantCharacterToUserResult UPlayFabClientModelDecoder::decodeGrantCharacterToUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGrantCharacterToUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");
    tempStruct.CharacterType = !(dataObj->HasField("CharacterType")) ? TEXT("") : dataObj->GetStringField("CharacterType");
    tempStruct.Result = !(dataObj->HasField("Result")) ? false : dataObj->GetBoolField("Result");

    return tempStruct;
}

FClientUpdateCharacterStatisticsResult UPlayFabClientModelDecoder::decodeUpdateCharacterStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateCharacterStatisticsResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

FClientGetCharacterDataResult UPlayFabClientModelDecoder::decodeGetCharacterDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}

FClientUpdateCharacterDataResult UPlayFabClientModelDecoder::decodeUpdateCharacterDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateCharacterDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Amazon-Specific APIs
//////////////////////////////////////////////////////

FClientValidateAmazonReceiptResult UPlayFabClientModelDecoder::decodeValidateAmazonReceiptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientValidateAmazonReceiptResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Trading
//////////////////////////////////////////////////////

FClientAcceptTradeResponse UPlayFabClientModelDecoder::decodeAcceptTradeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAcceptTradeResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Trade = !(dataObj->HasField("Trade")) ? nullptr : dataObj->GetObjectField("Trade");

    return tempStruct;
}

FClientCancelTradeResponse UPlayFabClientModelDecoder::decodeCancelTradeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientCancelTradeResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Trade = !(dataObj->HasField("Trade")) ? nullptr : dataObj->GetObjectField("Trade");

    return tempStruct;
}

FClientGetPlayerTradesResponse UPlayFabClientModelDecoder::decodeGetPlayerTradesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayerTradesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.OpenedTrades = !(dataObj->HasField("OpenedTrades")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("OpenedTrades");
    tempStruct.AcceptedTrades = !(dataObj->HasField("AcceptedTrades")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("AcceptedTrades");

    return tempStruct;
}

FClientGetTradeStatusResponse UPlayFabClientModelDecoder::decodeGetTradeStatusResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetTradeStatusResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Trade = !(dataObj->HasField("Trade")) ? nullptr : dataObj->GetObjectField("Trade");

    return tempStruct;
}

FClientOpenTradeResponse UPlayFabClientModelDecoder::decodeOpenTradeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientOpenTradeResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Trade = !(dataObj->HasField("Trade")) ? nullptr : dataObj->GetObjectField("Trade");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Advertising
//////////////////////////////////////////////////////

FClientAttributeInstallResult UPlayFabClientModelDecoder::decodeAttributeInstallResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAttributeInstallResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Guilds
//////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////

FClientGetPlayerSegmentsResult UPlayFabClientModelDecoder::decodeGetPlayerSegmentsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayerSegmentsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Segments = !(dataObj->HasField("Segments")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Segments");

    return tempStruct;
}

FClientGetPlayerTagsResult UPlayFabClientModelDecoder::decodeGetPlayerTagsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayerTagsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.Tags = !(dataObj->HasField("Tags")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Tags"), TEXT(","));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Windows
//////////////////////////////////////////////////////

FClientValidateWindowsReceiptResult UPlayFabClientModelDecoder::decodeValidateWindowsReceiptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientValidateWindowsReceiptResult tempStruct;


    return tempStruct;
}


