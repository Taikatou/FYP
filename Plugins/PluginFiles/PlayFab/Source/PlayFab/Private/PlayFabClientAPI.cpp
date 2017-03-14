//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Client
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabEnums.h"
#include "PlayFabClientAPI.h"

UPlayFabClientAPI::UPlayFabClientAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UPlayFabClientAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabClientAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabClientAPI::PercentEncode(const FString& Text)
{
    FString OutText = Text;

    OutText = OutText.Replace(TEXT("!"), TEXT("%21"));
    OutText = OutText.Replace(TEXT("\""), TEXT("%22"));
    OutText = OutText.Replace(TEXT("#"), TEXT("%23"));
    OutText = OutText.Replace(TEXT("$"), TEXT("%24"));
    //OutText = OutText.Replace(TEXT("&"), TEXT("%26"));
    OutText = OutText.Replace(TEXT("'"), TEXT("%27"));
    OutText = OutText.Replace(TEXT("("), TEXT("%28"));
    OutText = OutText.Replace(TEXT(")"), TEXT("%29"));
    OutText = OutText.Replace(TEXT("*"), TEXT("%2A"));
    OutText = OutText.Replace(TEXT("+"), TEXT("%2B"));
    OutText = OutText.Replace(TEXT(","), TEXT("%2C"));
    //OutText = OutText.Replace(TEXT("/"), TEXT("%2F"));
    OutText = OutText.Replace(TEXT(":"), TEXT("%3A"));
    OutText = OutText.Replace(TEXT(";"), TEXT("%3B"));
    OutText = OutText.Replace(TEXT("="), TEXT("%3D"));
    //OutText = OutText.Replace(TEXT("?"), TEXT("%3F"));
    OutText = OutText.Replace(TEXT("@"), TEXT("%40"));
    OutText = OutText.Replace(TEXT("["), TEXT("%5B"));
    OutText = OutText.Replace(TEXT("]"), TEXT("%5D"));
    OutText = OutText.Replace(TEXT("{"), TEXT("%7B"));
    OutText = OutText.Replace(TEXT("}"), TEXT("%7D"));

    return OutText;
}

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Client API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////
/** Gets a Photon custom authentication token that can be used to securely join the player into a Photon room. See https://api.playfab.com/docs/using-photon-with-playfab/ for more details. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPhotonAuthenticationToken(FClientGetPhotonAuthenticationTokenRequest request,
    FDelegateOnSuccessGetPhotonAuthenticationToken onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPhotonAuthenticationToken = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPhotonAuthenticationToken);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPhotonAuthenticationToken";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.PhotonApplicationId.IsEmpty() || request.PhotonApplicationId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PhotonApplicationId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PhotonApplicationId"), request.PhotonApplicationId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPhotonAuthenticationToken(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPhotonAuthenticationTokenResult result = UPlayFabClientModelDecoder::decodeGetPhotonAuthenticationTokenResultResponse(response.responseData);
        if (OnSuccessGetPhotonAuthenticationToken.IsBound())
        {
            OnSuccessGetPhotonAuthenticationToken.Execute(result, mCustomData);
        }
    }
}

/** Requests a challenge from the server to be signed by Windows Hello Passport service to authenticate. */
UPlayFabClientAPI* UPlayFabClientAPI::GetWindowsHelloChallenge(FClientGetWindowsHelloChallengeRequest request,
    FDelegateOnSuccessGetWindowsHelloChallenge onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetWindowsHelloChallenge = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetWindowsHelloChallenge);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetWindowsHelloChallenge";
    manager->useSessionTicket = false;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.PublicKeyHint.IsEmpty() || request.PublicKeyHint == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PublicKeyHint"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PublicKeyHint"), request.PublicKeyHint);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetWindowsHelloChallenge(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetWindowsHelloChallengeResponse result = UPlayFabClientModelDecoder::decodeGetWindowsHelloChallengeResponseResponse(response.responseData);
        if (OnSuccessGetWindowsHelloChallenge.IsBound())
        {
            OnSuccessGetWindowsHelloChallenge.Execute(result, mCustomData);
        }
    }
}

/** Link Windows Hello to the current PlayFab Account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkWindowsHello(FClientLinkWindowsHelloAccountRequest request,
    FDelegateOnSuccessLinkWindowsHello onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLinkWindowsHello = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkWindowsHello);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkWindowsHello";
    manager->useSessionTicket = false;

    // Serialize all the request properties to json
    if (request.UserName.IsEmpty() || request.UserName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("UserName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("UserName"), request.UserName);
    }
    if (request.PublicKey.IsEmpty() || request.PublicKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PublicKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PublicKey"), request.PublicKey);
    }
    if (request.DeviceName.IsEmpty() || request.DeviceName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DeviceName"), request.DeviceName);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkWindowsHello(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLinkWindowsHelloAccountResponse result = UPlayFabClientModelDecoder::decodeLinkWindowsHelloAccountResponseResponse(response.responseData);
        if (OnSuccessLinkWindowsHello.IsBound())
        {
            OnSuccessLinkWindowsHello.Execute(result, mCustomData);
        }
    }
}

/** Signs the user in using the Android device identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithAndroidDeviceID(FClientLoginWithAndroidDeviceIDRequest request,
    FDelegateOnSuccessLoginWithAndroidDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithAndroidDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithAndroidDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithAndroidDeviceID";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.AndroidDeviceId.IsEmpty() || request.AndroidDeviceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDeviceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), request.AndroidDeviceId);
    }
    if (request.OS.IsEmpty() || request.OS == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }
    if (request.AndroidDevice.IsEmpty() || request.AndroidDevice == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDevice"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AndroidDevice"), request.AndroidDevice);
    }
    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithAndroidDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithAndroidDeviceID.IsBound())
        {
            OnSuccessLoginWithAndroidDeviceID.Execute(result, mCustomData);
        }
    }
}

/** Signs the user in using a custom unique identifier generated by the title, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithCustomID(FClientLoginWithCustomIDRequest request,
    FDelegateOnSuccessLoginWithCustomID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithCustomID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithCustomID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithCustomID";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.CustomId.IsEmpty() || request.CustomId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CustomId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CustomId"), request.CustomId);
    }
    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithCustomID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithCustomID.IsBound())
        {
            OnSuccessLoginWithCustomID.Execute(result, mCustomData);
        }
    }
}

/** Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithEmailAddress(FClientLoginWithEmailAddressRequest request,
    FDelegateOnSuccessLoginWithEmailAddress onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithEmailAddress = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithEmailAddress);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithEmailAddress";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.Email.IsEmpty() || request.Email == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }
    if (request.Password.IsEmpty() || request.Password == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithEmailAddress(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithEmailAddress.IsBound())
        {
            OnSuccessLoginWithEmailAddress.Execute(result, mCustomData);
        }
    }
}

/** Signs the user in using a Facebook access token, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithFacebook(FClientLoginWithFacebookRequest request,
    FDelegateOnSuccessLoginWithFacebook onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithFacebook = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithFacebook);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithFacebook";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.AccessToken.IsEmpty() || request.AccessToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }
    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithFacebook(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithFacebook.IsBound())
        {
            OnSuccessLoginWithFacebook.Execute(result, mCustomData);
        }
    }
}

/** Signs the user in using an iOS Game Center player identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithGameCenter(FClientLoginWithGameCenterRequest request,
    FDelegateOnSuccessLoginWithGameCenter onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithGameCenter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithGameCenter);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithGameCenter";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.PlayerId.IsEmpty() || request.PlayerId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayerId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayerId"), request.PlayerId);
    }
    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithGameCenter(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithGameCenter.IsBound())
        {
            OnSuccessLoginWithGameCenter.Execute(result, mCustomData);
        }
    }
}

/** Signs the user in using their Google account credentials */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithGoogleAccount(FClientLoginWithGoogleAccountRequest request,
    FDelegateOnSuccessLoginWithGoogleAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithGoogleAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithGoogleAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithGoogleAccount";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.ServerAuthCode.IsEmpty() || request.ServerAuthCode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ServerAuthCode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ServerAuthCode"), request.ServerAuthCode);
    }
    if (request.AccessToken.IsEmpty() || request.AccessToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }
    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithGoogleAccount(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithGoogleAccount.IsBound())
        {
            OnSuccessLoginWithGoogleAccount.Execute(result, mCustomData);
        }
    }
}

/** Signs the user in using the vendor-specific iOS device identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithIOSDeviceID(FClientLoginWithIOSDeviceIDRequest request,
    FDelegateOnSuccessLoginWithIOSDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithIOSDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithIOSDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithIOSDeviceID";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.DeviceId.IsEmpty() || request.DeviceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DeviceId"), request.DeviceId);
    }
    if (request.OS.IsEmpty() || request.OS == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }
    if (request.DeviceModel.IsEmpty() || request.DeviceModel == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceModel"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DeviceModel"), request.DeviceModel);
    }
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);
    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithIOSDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithIOSDeviceID.IsBound())
        {
            OnSuccessLoginWithIOSDeviceID.Execute(result, mCustomData);
        }
    }
}

/** Signs the user in using a Kongregate player account. */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithKongregate(FClientLoginWithKongregateRequest request,
    FDelegateOnSuccessLoginWithKongregate onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithKongregate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithKongregate);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithKongregate";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.KongregateId.IsEmpty() || request.KongregateId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KongregateId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("KongregateId"), request.KongregateId);
    }
    if (request.AuthTicket.IsEmpty() || request.AuthTicket == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AuthTicket"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AuthTicket"), request.AuthTicket);
    }
    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithKongregate(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithKongregate.IsBound())
        {
            OnSuccessLoginWithKongregate.Execute(result, mCustomData);
        }
    }
}

/** Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user. Unlike other login API calls, LoginWithEmailAddress does not permit the creation of new accounts via the CreateAccountFlag. Email accounts must be created using the RegisterPlayFabUser API or added to existing accounts using AddUsernamePassword. */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithPlayFab(FClientLoginWithPlayFabRequest request,
    FDelegateOnSuccessLoginWithPlayFab onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithPlayFab = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithPlayFab);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithPlayFab";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.Username.IsEmpty() || request.Username == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }
    if (request.Password.IsEmpty() || request.Password == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithPlayFab(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithPlayFab.IsBound())
        {
            OnSuccessLoginWithPlayFab.Execute(result, mCustomData);
        }
    }
}

/** Signs the user in using a Steam authentication ticket, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithSteam(FClientLoginWithSteamRequest request,
    FDelegateOnSuccessLoginWithSteam onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithSteam = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithSteam);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithSteam";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.SteamTicket.IsEmpty() || request.SteamTicket == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SteamTicket"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SteamTicket"), request.SteamTicket);
    }
    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithSteam(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithSteam.IsBound())
        {
            OnSuccessLoginWithSteam.Execute(result, mCustomData);
        }
    }
}

/** Signs the user in using a Twitch access token. */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithTwitch(FClientLoginWithTwitchRequest request,
    FDelegateOnSuccessLoginWithTwitch onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithTwitch = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithTwitch);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithTwitch";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.AccessToken.IsEmpty() || request.AccessToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }
    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithTwitch(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithTwitch.IsBound())
        {
            OnSuccessLoginWithTwitch.Execute(result, mCustomData);
        }
    }
}

/** Completes the Windows Hello login flow by returning the signed value of the challange from GetWindowsHelloChallenge. Windows Hello has a 2 step client to server authentication scheme. Step one is to request from the server a challenge string. Step two is to request the user sign the string via Windows Hello and then send the signed value back to the server.  */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithWindowsHello(FClientLoginWithWindowsHelloRequest request,
    FDelegateOnSuccessLoginWithWindowsHello onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLoginWithWindowsHello = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithWindowsHello);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithWindowsHello";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.ChallengeSignature.IsEmpty() || request.ChallengeSignature == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ChallengeSignature"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ChallengeSignature"), request.ChallengeSignature);
    }
    if (request.PublicKeyHint.IsEmpty() || request.PublicKeyHint == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PublicKeyHint"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PublicKeyHint"), request.PublicKeyHint);
    }
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithWindowsHello(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithWindowsHello.IsBound())
        {
            OnSuccessLoginWithWindowsHello.Execute(result, mCustomData);
        }
    }
}

/** Registers a new Playfab user account, returning a session identifier that can subsequently be used for API calls which require an authenticated user. You must supply either a username or an email address. */
UPlayFabClientAPI* UPlayFabClientAPI::RegisterPlayFabUser(FClientRegisterPlayFabUserRequest request,
    FDelegateOnSuccessRegisterPlayFabUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRegisterPlayFabUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRegisterPlayFabUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RegisterPlayFabUser";
    manager->useSessionTicket = false;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.Username.IsEmpty() || request.Username == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }
    if (request.Email.IsEmpty() || request.Email == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }
    if (request.Password.IsEmpty() || request.Password == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }
    OutRestJsonObj->SetBoolField(TEXT("RequireBothUsernameAndEmail"), request.RequireBothUsernameAndEmail);
    if (request.DisplayName.IsEmpty() || request.DisplayName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DisplayName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DisplayName"), request.DisplayName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRegisterPlayFabUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientRegisterPlayFabUserResult result = UPlayFabClientModelDecoder::decodeRegisterPlayFabUserResultResponse(response.responseData);
        if (OnSuccessRegisterPlayFabUser.IsBound())
        {
            OnSuccessRegisterPlayFabUser.Execute(result, mCustomData);
        }
    }
}

/** Register using Windows Hello authentication. Before a user can request a challenge or perform a signin the user must first either register or link a Windows Hello account. */
UPlayFabClientAPI* UPlayFabClientAPI::RegisterWithWindowsHello(FClientRegisterWithWindowsHelloRequest request,
    FDelegateOnSuccessRegisterWithWindowsHello onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRegisterWithWindowsHello = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRegisterWithWindowsHello);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RegisterWithWindowsHello";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.UserName.IsEmpty() || request.UserName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("UserName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("UserName"), request.UserName);
    }
    if (request.PublicKey.IsEmpty() || request.PublicKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PublicKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PublicKey"), request.PublicKey);
    }
    if (request.DeviceName.IsEmpty() || request.DeviceName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DeviceName"), request.DeviceName);
    }
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRegisterWithWindowsHello(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessRegisterWithWindowsHello.IsBound())
        {
            OnSuccessRegisterWithWindowsHello.Execute(result, mCustomData);
        }
    }
}

/** Unlink Windows Hello from the current PlayFab Account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkWindowsHello(FClientUnlinkWindowsHelloAccountRequest request,
    FDelegateOnSuccessUnlinkWindowsHello onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkWindowsHello = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkWindowsHello);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkWindowsHello";
    manager->useSessionTicket = false;

    // Serialize all the request properties to json
    if (request.PublicKeyHint.IsEmpty() || request.PublicKeyHint == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PublicKeyHint"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PublicKeyHint"), request.PublicKeyHint);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkWindowsHello(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlinkWindowsHelloAccountResponse result = UPlayFabClientModelDecoder::decodeUnlinkWindowsHelloAccountResponseResponse(response.responseData);
        if (OnSuccessUnlinkWindowsHello.IsBound())
        {
            OnSuccessUnlinkWindowsHello.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////
/** Adds the specified generic service identifier to the player's PlayFab account. This is designed to allow for a PlayFab ID lookup of any arbitrary service identifier a title wants to add. This identifier should never be used as authentication credentials, as the intent is that it is easily accessible by other players. */
UPlayFabClientAPI* UPlayFabClientAPI::AddGenericID(FClientAddGenericIDRequest request,
    FDelegateOnSuccessAddGenericID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddGenericID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAddGenericID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddGenericID";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.GenericId != nullptr) OutRestJsonObj->SetObjectField(TEXT("GenericId"), request.GenericId);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAddGenericID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientAddGenericIDResult result = UPlayFabClientModelDecoder::decodeAddGenericIDResultResponse(response.responseData);
        if (OnSuccessAddGenericID.IsBound())
        {
            OnSuccessAddGenericID.Execute(result, mCustomData);
        }
    }
}

/** Adds playfab username/password auth to an existing account created via an anonymous auth method, e.g. automatic device ID login. */
UPlayFabClientAPI* UPlayFabClientAPI::AddUsernamePassword(FClientAddUsernamePasswordRequest request,
    FDelegateOnSuccessAddUsernamePassword onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddUsernamePassword = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAddUsernamePassword);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddUsernamePassword";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.Username.IsEmpty() || request.Username == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }
    if (request.Email.IsEmpty() || request.Email == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }
    if (request.Password.IsEmpty() || request.Password == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAddUsernamePassword(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientAddUsernamePasswordResult result = UPlayFabClientModelDecoder::decodeAddUsernamePasswordResultResponse(response.responseData);
        if (OnSuccessAddUsernamePassword.IsBound())
        {
            OnSuccessAddUsernamePassword.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the user's PlayFab account details */
UPlayFabClientAPI* UPlayFabClientAPI::GetAccountInfo(FClientGetAccountInfoRequest request,
    FDelegateOnSuccessGetAccountInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetAccountInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetAccountInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetAccountInfo";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Username.IsEmpty() || request.Username == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }
    if (request.Email.IsEmpty() || request.Email == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }
    if (request.TitleDisplayName.IsEmpty() || request.TitleDisplayName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TitleDisplayName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TitleDisplayName"), request.TitleDisplayName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetAccountInfo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetAccountInfoResult result = UPlayFabClientModelDecoder::decodeGetAccountInfoResultResponse(response.responseData);
        if (OnSuccessGetAccountInfo.IsBound())
        {
            OnSuccessGetAccountInfo.Execute(result, mCustomData);
        }
    }
}

/** Retrieves all of the user's different kinds of info. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayerCombinedInfo(FClientGetPlayerCombinedInfoRequest request,
    FDelegateOnSuccessGetPlayerCombinedInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerCombinedInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayerCombinedInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayerCombinedInfo";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayerCombinedInfo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayerCombinedInfoResult result = UPlayFabClientModelDecoder::decodeGetPlayerCombinedInfoResultResponse(response.responseData);
        if (OnSuccessGetPlayerCombinedInfo.IsBound())
        {
            OnSuccessGetPlayerCombinedInfo.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromFacebookIDs(FClientGetPlayFabIDsFromFacebookIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromFacebookIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromFacebookIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromFacebookIDs";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.FacebookIDs.IsEmpty() || request.FacebookIDs == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FacebookIDs"));
    } else {
        TArray<FString> FacebookIDsArray;
        FString(request.FacebookIDs).ParseIntoArray(FacebookIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("FacebookIDs"), FacebookIDsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromFacebookIDs(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayFabIDsFromFacebookIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromFacebookIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromFacebookIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromFacebookIDs.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Game Center identifiers (referenced in the Game Center Programming Guide as the Player Identifier). */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromGameCenterIDs(FClientGetPlayFabIDsFromGameCenterIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromGameCenterIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromGameCenterIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromGameCenterIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromGameCenterIDs";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.GameCenterIDs.IsEmpty() || request.GameCenterIDs == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GameCenterIDs"));
    } else {
        TArray<FString> GameCenterIDsArray;
        FString(request.GameCenterIDs).ParseIntoArray(GameCenterIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("GameCenterIDs"), GameCenterIDsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromGameCenterIDs(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayFabIDsFromGameCenterIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGameCenterIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromGameCenterIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromGameCenterIDs.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of generic service identifiers. A generic identifier is the service name plus the service-specific ID for the player, as specified by the title when the generic identifier was added to the player account. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromGenericIDs(FClientGetPlayFabIDsFromGenericIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromGenericIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromGenericIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromGenericIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromGenericIDs";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.GenericIDs.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("GenericIDs"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("GenericIDs"), request.GenericIDs);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromGenericIDs(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayFabIDsFromGenericIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGenericIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromGenericIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromGenericIDs.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Google identifiers. The Google identifiers are the IDs for the user accounts, available as "id" in the Google+ People API calls. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromGoogleIDs(FClientGetPlayFabIDsFromGoogleIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromGoogleIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromGoogleIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromGoogleIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromGoogleIDs";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.GoogleIDs.IsEmpty() || request.GoogleIDs == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GoogleIDs"));
    } else {
        TArray<FString> GoogleIDsArray;
        FString(request.GoogleIDs).ParseIntoArray(GoogleIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("GoogleIDs"), GoogleIDsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromGoogleIDs(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayFabIDsFromGoogleIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGoogleIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromGoogleIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromGoogleIDs.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Kongregate identifiers. The Kongregate identifiers are the IDs for the user accounts, available as "user_id" from the Kongregate API methods(ex: http://developers.kongregate.com/docs/client/getUserId). */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromKongregateIDs(FClientGetPlayFabIDsFromKongregateIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromKongregateIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromKongregateIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromKongregateIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromKongregateIDs";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.KongregateIDs.IsEmpty() || request.KongregateIDs == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KongregateIDs"));
    } else {
        TArray<FString> KongregateIDsArray;
        FString(request.KongregateIDs).ParseIntoArray(KongregateIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KongregateIDs"), KongregateIDsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromKongregateIDs(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayFabIDsFromKongregateIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromKongregateIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromKongregateIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromKongregateIDs.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers  are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromSteamIDs(FClientGetPlayFabIDsFromSteamIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromSteamIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromSteamIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromSteamIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromSteamIDs";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.SteamStringIDs.IsEmpty() || request.SteamStringIDs == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SteamStringIDs"));
    } else {
        TArray<FString> SteamStringIDsArray;
        FString(request.SteamStringIDs).ParseIntoArray(SteamStringIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("SteamStringIDs"), SteamStringIDsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromSteamIDs(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayFabIDsFromSteamIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromSteamIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromSteamIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromSteamIDs.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Twitch identifiers. The Twitch identifiers are the IDs for the user accounts, available as "_id" from the Twitch API methods (ex: https://github.com/justintv/Twitch-API/blob/master/v3_resources/users.md#get-usersuser). */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromTwitchIDs(FClientGetPlayFabIDsFromTwitchIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromTwitchIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromTwitchIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromTwitchIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromTwitchIDs";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.TwitchIds.IsEmpty() || request.TwitchIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TwitchIds"));
    } else {
        TArray<FString> TwitchIdsArray;
        FString(request.TwitchIds).ParseIntoArray(TwitchIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("TwitchIds"), TwitchIdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromTwitchIDs(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayFabIDsFromTwitchIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromTwitchIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromTwitchIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromTwitchIDs.Execute(result, mCustomData);
        }
    }
}

/** Links the Android device identifier to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkAndroidDeviceID(FClientLinkAndroidDeviceIDRequest request,
    FDelegateOnSuccessLinkAndroidDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLinkAndroidDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkAndroidDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkAndroidDeviceID";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.AndroidDeviceId.IsEmpty() || request.AndroidDeviceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDeviceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), request.AndroidDeviceId);
    }
    if (request.OS.IsEmpty() || request.OS == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }
    if (request.AndroidDevice.IsEmpty() || request.AndroidDevice == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDevice"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AndroidDevice"), request.AndroidDevice);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkAndroidDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLinkAndroidDeviceIDResult result = UPlayFabClientModelDecoder::decodeLinkAndroidDeviceIDResultResponse(response.responseData);
        if (OnSuccessLinkAndroidDeviceID.IsBound())
        {
            OnSuccessLinkAndroidDeviceID.Execute(result, mCustomData);
        }
    }
}

/** Links the custom identifier, generated by the title, to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkCustomID(FClientLinkCustomIDRequest request,
    FDelegateOnSuccessLinkCustomID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLinkCustomID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkCustomID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkCustomID";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CustomId.IsEmpty() || request.CustomId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CustomId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CustomId"), request.CustomId);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkCustomID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLinkCustomIDResult result = UPlayFabClientModelDecoder::decodeLinkCustomIDResultResponse(response.responseData);
        if (OnSuccessLinkCustomID.IsBound())
        {
            OnSuccessLinkCustomID.Execute(result, mCustomData);
        }
    }
}

/** Links the Facebook account associated with the provided Facebook access token to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkFacebookAccount(FClientLinkFacebookAccountRequest request,
    FDelegateOnSuccessLinkFacebookAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLinkFacebookAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkFacebookAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkFacebookAccount";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.AccessToken.IsEmpty() || request.AccessToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkFacebookAccount(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLinkFacebookAccountResult result = UPlayFabClientModelDecoder::decodeLinkFacebookAccountResultResponse(response.responseData);
        if (OnSuccessLinkFacebookAccount.IsBound())
        {
            OnSuccessLinkFacebookAccount.Execute(result, mCustomData);
        }
    }
}

/** Links the Game Center account associated with the provided Game Center ID to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkGameCenterAccount(FClientLinkGameCenterAccountRequest request,
    FDelegateOnSuccessLinkGameCenterAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLinkGameCenterAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkGameCenterAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkGameCenterAccount";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.GameCenterId.IsEmpty() || request.GameCenterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GameCenterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GameCenterId"), request.GameCenterId);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkGameCenterAccount(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLinkGameCenterAccountResult result = UPlayFabClientModelDecoder::decodeLinkGameCenterAccountResultResponse(response.responseData);
        if (OnSuccessLinkGameCenterAccount.IsBound())
        {
            OnSuccessLinkGameCenterAccount.Execute(result, mCustomData);
        }
    }
}

/** Links the currently signed-in user account to their Google account, using their Google account credentials */
UPlayFabClientAPI* UPlayFabClientAPI::LinkGoogleAccount(FClientLinkGoogleAccountRequest request,
    FDelegateOnSuccessLinkGoogleAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLinkGoogleAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkGoogleAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkGoogleAccount";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.ServerAuthCode.IsEmpty() || request.ServerAuthCode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ServerAuthCode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ServerAuthCode"), request.ServerAuthCode);
    }
    if (request.AccessToken.IsEmpty() || request.AccessToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkGoogleAccount(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLinkGoogleAccountResult result = UPlayFabClientModelDecoder::decodeLinkGoogleAccountResultResponse(response.responseData);
        if (OnSuccessLinkGoogleAccount.IsBound())
        {
            OnSuccessLinkGoogleAccount.Execute(result, mCustomData);
        }
    }
}

/** Links the vendor-specific iOS device identifier to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkIOSDeviceID(FClientLinkIOSDeviceIDRequest request,
    FDelegateOnSuccessLinkIOSDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLinkIOSDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkIOSDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkIOSDeviceID";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.DeviceId.IsEmpty() || request.DeviceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DeviceId"), request.DeviceId);
    }
    if (request.OS.IsEmpty() || request.OS == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }
    if (request.DeviceModel.IsEmpty() || request.DeviceModel == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceModel"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DeviceModel"), request.DeviceModel);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkIOSDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLinkIOSDeviceIDResult result = UPlayFabClientModelDecoder::decodeLinkIOSDeviceIDResultResponse(response.responseData);
        if (OnSuccessLinkIOSDeviceID.IsBound())
        {
            OnSuccessLinkIOSDeviceID.Execute(result, mCustomData);
        }
    }
}

/** Links the Kongregate identifier to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkKongregate(FClientLinkKongregateAccountRequest request,
    FDelegateOnSuccessLinkKongregate onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLinkKongregate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkKongregate);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkKongregate";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.KongregateId.IsEmpty() || request.KongregateId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KongregateId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("KongregateId"), request.KongregateId);
    }
    if (request.AuthTicket.IsEmpty() || request.AuthTicket == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AuthTicket"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AuthTicket"), request.AuthTicket);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkKongregate(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLinkKongregateAccountResult result = UPlayFabClientModelDecoder::decodeLinkKongregateAccountResultResponse(response.responseData);
        if (OnSuccessLinkKongregate.IsBound())
        {
            OnSuccessLinkKongregate.Execute(result, mCustomData);
        }
    }
}

/** Links the Steam account associated with the provided Steam authentication ticket to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkSteamAccount(FClientLinkSteamAccountRequest request,
    FDelegateOnSuccessLinkSteamAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLinkSteamAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkSteamAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkSteamAccount";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.SteamTicket.IsEmpty() || request.SteamTicket == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SteamTicket"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SteamTicket"), request.SteamTicket);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkSteamAccount(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLinkSteamAccountResult result = UPlayFabClientModelDecoder::decodeLinkSteamAccountResultResponse(response.responseData);
        if (OnSuccessLinkSteamAccount.IsBound())
        {
            OnSuccessLinkSteamAccount.Execute(result, mCustomData);
        }
    }
}

/** Links the Twitch account associated with the token to the user's PlayFab account. */
UPlayFabClientAPI* UPlayFabClientAPI::LinkTwitch(FClientLinkTwitchAccountRequest request,
    FDelegateOnSuccessLinkTwitch onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessLinkTwitch = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkTwitch);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkTwitch";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.AccessToken.IsEmpty() || request.AccessToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkTwitch(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientLinkTwitchAccountResult result = UPlayFabClientModelDecoder::decodeLinkTwitchAccountResultResponse(response.responseData);
        if (OnSuccessLinkTwitch.IsBound())
        {
            OnSuccessLinkTwitch.Execute(result, mCustomData);
        }
    }
}

/** Removes the specified generic service identifier from the player's PlayFab account. */
UPlayFabClientAPI* UPlayFabClientAPI::RemoveGenericID(FClientRemoveGenericIDRequest request,
    FDelegateOnSuccessRemoveGenericID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemoveGenericID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRemoveGenericID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RemoveGenericID";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.GenericId != nullptr) OutRestJsonObj->SetObjectField(TEXT("GenericId"), request.GenericId);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRemoveGenericID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientRemoveGenericIDResult result = UPlayFabClientModelDecoder::decodeRemoveGenericIDResultResponse(response.responseData);
        if (OnSuccessRemoveGenericID.IsBound())
        {
            OnSuccessRemoveGenericID.Execute(result, mCustomData);
        }
    }
}

/** Submit a report for another player (due to bad bahavior, etc.), so that customer service representatives for the title can take action concerning potentially toxic players. */
UPlayFabClientAPI* UPlayFabClientAPI::ReportPlayer(FClientReportPlayerClientRequest request,
    FDelegateOnSuccessReportPlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessReportPlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperReportPlayer);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ReportPlayer";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.ReporteeId.IsEmpty() || request.ReporteeId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReporteeId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReporteeId"), request.ReporteeId);
    }
    if (request.Comment.IsEmpty() || request.Comment == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Comment"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Comment"), request.Comment);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperReportPlayer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientReportPlayerClientResult result = UPlayFabClientModelDecoder::decodeReportPlayerClientResultResponse(response.responseData);
        if (OnSuccessReportPlayer.IsBound())
        {
            OnSuccessReportPlayer.Execute(result, mCustomData);
        }
    }
}

/** Forces an email to be sent to the registered email address for the user's account, with a link allowing the user to change the password */
UPlayFabClientAPI* UPlayFabClientAPI::SendAccountRecoveryEmail(FClientSendAccountRecoveryEmailRequest request,
    FDelegateOnSuccessSendAccountRecoveryEmail onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSendAccountRecoveryEmail = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperSendAccountRecoveryEmail);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/SendAccountRecoveryEmail";
    manager->useSessionTicket = false;

    // Serialize all the request properties to json
    if (request.Email.IsEmpty() || request.Email == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperSendAccountRecoveryEmail(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientSendAccountRecoveryEmailResult result = UPlayFabClientModelDecoder::decodeSendAccountRecoveryEmailResultResponse(response.responseData);
        if (OnSuccessSendAccountRecoveryEmail.IsBound())
        {
            OnSuccessSendAccountRecoveryEmail.Execute(result, mCustomData);
        }
    }
}

/** Unlinks the related Android device identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkAndroidDeviceID(FClientUnlinkAndroidDeviceIDRequest request,
    FDelegateOnSuccessUnlinkAndroidDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkAndroidDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkAndroidDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkAndroidDeviceID";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.AndroidDeviceId.IsEmpty() || request.AndroidDeviceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDeviceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), request.AndroidDeviceId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkAndroidDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlinkAndroidDeviceIDResult result = UPlayFabClientModelDecoder::decodeUnlinkAndroidDeviceIDResultResponse(response.responseData);
        if (OnSuccessUnlinkAndroidDeviceID.IsBound())
        {
            OnSuccessUnlinkAndroidDeviceID.Execute(result, mCustomData);
        }
    }
}

/** Unlinks the related custom identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkCustomID(FClientUnlinkCustomIDRequest request,
    FDelegateOnSuccessUnlinkCustomID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkCustomID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkCustomID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkCustomID";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CustomId.IsEmpty() || request.CustomId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CustomId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CustomId"), request.CustomId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkCustomID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlinkCustomIDResult result = UPlayFabClientModelDecoder::decodeUnlinkCustomIDResultResponse(response.responseData);
        if (OnSuccessUnlinkCustomID.IsBound())
        {
            OnSuccessUnlinkCustomID.Execute(result, mCustomData);
        }
    }
}

/** Unlinks the related Facebook account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkFacebookAccount(FClientUnlinkFacebookAccountRequest request,
    FDelegateOnSuccessUnlinkFacebookAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkFacebookAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkFacebookAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkFacebookAccount";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkFacebookAccount(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlinkFacebookAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkFacebookAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkFacebookAccount.IsBound())
        {
            OnSuccessUnlinkFacebookAccount.Execute(result, mCustomData);
        }
    }
}

/** Unlinks the related Game Center account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkGameCenterAccount(FClientUnlinkGameCenterAccountRequest request,
    FDelegateOnSuccessUnlinkGameCenterAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkGameCenterAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkGameCenterAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkGameCenterAccount";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkGameCenterAccount(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlinkGameCenterAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkGameCenterAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkGameCenterAccount.IsBound())
        {
            OnSuccessUnlinkGameCenterAccount.Execute(result, mCustomData);
        }
    }
}

/** Unlinks the related Google account from the user's PlayFab account (https://developers.google.com/android/reference/com/google/android/gms/auth/GoogleAuthUtil#public-methods). */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkGoogleAccount(FClientUnlinkGoogleAccountRequest request,
    FDelegateOnSuccessUnlinkGoogleAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkGoogleAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkGoogleAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkGoogleAccount";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkGoogleAccount(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlinkGoogleAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkGoogleAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkGoogleAccount.IsBound())
        {
            OnSuccessUnlinkGoogleAccount.Execute(result, mCustomData);
        }
    }
}

/** Unlinks the related iOS device identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkIOSDeviceID(FClientUnlinkIOSDeviceIDRequest request,
    FDelegateOnSuccessUnlinkIOSDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkIOSDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkIOSDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkIOSDeviceID";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.DeviceId.IsEmpty() || request.DeviceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DeviceId"), request.DeviceId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkIOSDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlinkIOSDeviceIDResult result = UPlayFabClientModelDecoder::decodeUnlinkIOSDeviceIDResultResponse(response.responseData);
        if (OnSuccessUnlinkIOSDeviceID.IsBound())
        {
            OnSuccessUnlinkIOSDeviceID.Execute(result, mCustomData);
        }
    }
}

/** Unlinks the related Kongregate identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkKongregate(FClientUnlinkKongregateAccountRequest request,
    FDelegateOnSuccessUnlinkKongregate onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkKongregate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkKongregate);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkKongregate";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkKongregate(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlinkKongregateAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkKongregateAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkKongregate.IsBound())
        {
            OnSuccessUnlinkKongregate.Execute(result, mCustomData);
        }
    }
}

/** Unlinks the related Steam account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkSteamAccount(FClientUnlinkSteamAccountRequest request,
    FDelegateOnSuccessUnlinkSteamAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkSteamAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkSteamAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkSteamAccount";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkSteamAccount(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlinkSteamAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkSteamAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkSteamAccount.IsBound())
        {
            OnSuccessUnlinkSteamAccount.Execute(result, mCustomData);
        }
    }
}

/** Unlinks the related Twitch account from the user's PlayFab account. */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkTwitch(FClientUnlinkTwitchAccountRequest request,
    FDelegateOnSuccessUnlinkTwitch onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkTwitch = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkTwitch);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkTwitch";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkTwitch(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlinkTwitchAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkTwitchAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkTwitch.IsBound())
        {
            OnSuccessUnlinkTwitch.Execute(result, mCustomData);
        }
    }
}

/** Update the avatar URL of the player */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateAvatarUrl(FClientUpdateAvatarUrlRequest request,
    FDelegateOnSuccessUpdateAvatarUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateAvatarUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateAvatarUrl);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateAvatarUrl";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.ImageUrl.IsEmpty() || request.ImageUrl == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ImageUrl"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ImageUrl"), request.ImageUrl);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateAvatarUrl(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientEmptyResult result = UPlayFabClientModelDecoder::decodeEmptyResultResponse(response.responseData);
        if (OnSuccessUpdateAvatarUrl.IsBound())
        {
            OnSuccessUpdateAvatarUrl.Execute(result, mCustomData);
        }
    }
}

/** Updates the title specific display name for the user */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserTitleDisplayName(FClientUpdateUserTitleDisplayNameRequest request,
    FDelegateOnSuccessUpdateUserTitleDisplayName onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserTitleDisplayName = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateUserTitleDisplayName);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserTitleDisplayName";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.DisplayName.IsEmpty() || request.DisplayName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DisplayName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DisplayName"), request.DisplayName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateUserTitleDisplayName(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUpdateUserTitleDisplayNameResult result = UPlayFabClientModelDecoder::decodeUpdateUserTitleDisplayNameResultResponse(response.responseData);
        if (OnSuccessUpdateUserTitleDisplayName.IsBound())
        {
            OnSuccessUpdateUserTitleDisplayName.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////
/** Retrieves a list of ranked friends of the current player for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendLeaderboard(FClientGetFriendLeaderboardRequest request,
    FDelegateOnSuccessGetFriendLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetFriendLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetFriendLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendLeaderboard";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetBoolField(TEXT("UseSpecificVersion"), request.UseSpecificVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetFriendLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetLeaderboardResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardResultResponse(response.responseData);
        if (OnSuccessGetFriendLeaderboard.IsBound())
        {
            OnSuccessGetFriendLeaderboard.Execute(result, mCustomData);
        }
    }
}

/** Retrieves a list of ranked friends of the current player for the given statistic, centered on the requested PlayFab user. If PlayFabId is empty or null will return currently logged in user. */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendLeaderboardAroundPlayer(FClientGetFriendLeaderboardAroundPlayerRequest request,
    FDelegateOnSuccessGetFriendLeaderboardAroundPlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetFriendLeaderboardAroundPlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetFriendLeaderboardAroundPlayer);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendLeaderboardAroundPlayer";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetBoolField(TEXT("UseSpecificVersion"), request.UseSpecificVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetFriendLeaderboardAroundPlayer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetFriendLeaderboardAroundPlayerResult result = UPlayFabClientModelDecoder::decodeGetFriendLeaderboardAroundPlayerResultResponse(response.responseData);
        if (OnSuccessGetFriendLeaderboardAroundPlayer.IsBound())
        {
            OnSuccessGetFriendLeaderboardAroundPlayer.Execute(result, mCustomData);
        }
    }
}

/** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboard(FClientGetLeaderboardRequest request,
    FDelegateOnSuccessGetLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboard";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetBoolField(TEXT("UseSpecificVersion"), request.UseSpecificVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetLeaderboardResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardResultResponse(response.responseData);
        if (OnSuccessGetLeaderboard.IsBound())
        {
            OnSuccessGetLeaderboard.Execute(result, mCustomData);
        }
    }
}

/** Retrieves a list of ranked users for the given statistic, centered on the requested player. If PlayFabId is empty or null will return currently logged in user. */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardAroundPlayer(FClientGetLeaderboardAroundPlayerRequest request,
    FDelegateOnSuccessGetLeaderboardAroundPlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboardAroundPlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetLeaderboardAroundPlayer);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardAroundPlayer";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetBoolField(TEXT("UseSpecificVersion"), request.UseSpecificVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetLeaderboardAroundPlayer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetLeaderboardAroundPlayerResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardAroundPlayerResultResponse(response.responseData);
        if (OnSuccessGetLeaderboardAroundPlayer.IsBound())
        {
            OnSuccessGetLeaderboardAroundPlayer.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the indicated statistics (current version and values for all statistics, if none are specified), for the local player. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayerStatistics(FClientGetPlayerStatisticsRequest request,
    FDelegateOnSuccessGetPlayerStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayerStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayerStatistics";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.StatisticNames.IsEmpty() || request.StatisticNames == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticNames"));
    } else {
        TArray<FString> StatisticNamesArray;
        FString(request.StatisticNames).ParseIntoArray(StatisticNamesArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("StatisticNames"), StatisticNamesArray);
    }
    if (request.StatisticNameVersions.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticNameVersions"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("StatisticNameVersions"), request.StatisticNameVersions);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayerStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayerStatisticsResult result = UPlayFabClientModelDecoder::decodeGetPlayerStatisticsResultResponse(response.responseData);
        if (OnSuccessGetPlayerStatistics.IsBound())
        {
            OnSuccessGetPlayerStatistics.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the information on the available versions of the specified statistic. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayerStatisticVersions(FClientGetPlayerStatisticVersionsRequest request,
    FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerStatisticVersions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayerStatisticVersions);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayerStatisticVersions";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayerStatisticVersionsResult result = UPlayFabClientModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(response.responseData);
        if (OnSuccessGetPlayerStatisticVersions.IsBound())
        {
            OnSuccessGetPlayerStatisticVersions.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserData(FClientGetUserDataRequest request,
    FDelegateOnSuccessGetUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetUserDataResult result = UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserData.IsBound())
        {
            OnSuccessGetUserData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserPublisherData(FClientGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserPublisherData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetUserDataResult result = UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherData.IsBound())
        {
            OnSuccessGetUserPublisherData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which can only be read by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserPublisherReadOnlyData(FClientGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserPublisherReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserPublisherReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserPublisherReadOnlyData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetUserDataResult result = UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherReadOnlyData.IsBound())
        {
            OnSuccessGetUserPublisherReadOnlyData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the title-specific custom data for the user which can only be read by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserReadOnlyData(FClientGetUserDataRequest request,
    FDelegateOnSuccessGetUserReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserReadOnlyData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetUserDataResult result = UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserReadOnlyData.IsBound())
        {
            OnSuccessGetUserReadOnlyData.Execute(result, mCustomData);
        }
    }
}

/** Updates the values of the specified title-specific statistics for the user. By default, clients are not permitted to update statistics. Developers may override this setting in the Game Manager > Settings > API Features. */
UPlayFabClientAPI* UPlayFabClientAPI::UpdatePlayerStatistics(FClientUpdatePlayerStatisticsRequest request,
    FDelegateOnSuccessUpdatePlayerStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdatePlayerStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdatePlayerStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdatePlayerStatistics";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.Statistics.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Statistics"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Statistics"), request.Statistics);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdatePlayerStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUpdatePlayerStatisticsResult result = UPlayFabClientModelDecoder::decodeUpdatePlayerStatisticsResultResponse(response.responseData);
        if (OnSuccessUpdatePlayerStatistics.IsBound())
        {
            OnSuccessUpdatePlayerStatistics.Execute(result, mCustomData);
        }
    }
}

/** Creates and updates the title-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserData(FClientUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateUserData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateUserData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUpdateUserDataResult result = UPlayFabClientModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserData.IsBound())
        {
            OnSuccessUpdateUserData.Execute(result, mCustomData);
        }
    }
}

/** Creates and updates the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserPublisherData(FClientUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateUserPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserPublisherData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUpdateUserDataResult result = UPlayFabClientModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherData.IsBound())
        {
            OnSuccessUpdateUserPublisherData.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////
/** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
UPlayFabClientAPI* UPlayFabClientAPI::GetCatalogItems(FClientGetCatalogItemsRequest request,
    FDelegateOnSuccessGetCatalogItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCatalogItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCatalogItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCatalogItems";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCatalogItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetCatalogItemsResult result = UPlayFabClientModelDecoder::decodeGetCatalogItemsResultResponse(response.responseData);
        if (OnSuccessGetCatalogItems.IsBound())
        {
            OnSuccessGetCatalogItems.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the key-value store of custom publisher settings */
UPlayFabClientAPI* UPlayFabClientAPI::GetPublisherData(FClientGetPublisherDataRequest request,
    FDelegateOnSuccessGetPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPublisherData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPublisherDataResult result = UPlayFabClientModelDecoder::decodeGetPublisherDataResultResponse(response.responseData);
        if (OnSuccessGetPublisherData.IsBound())
        {
            OnSuccessGetPublisherData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the set of items defined for the specified store, including all prices defined */
UPlayFabClientAPI* UPlayFabClientAPI::GetStoreItems(FClientGetStoreItemsRequest request,
    FDelegateOnSuccessGetStoreItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetStoreItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetStoreItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetStoreItems";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.StoreId.IsEmpty() || request.StoreId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetStoreItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetStoreItemsResult result = UPlayFabClientModelDecoder::decodeGetStoreItemsResultResponse(response.responseData);
        if (OnSuccessGetStoreItems.IsBound())
        {
            OnSuccessGetStoreItems.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the current server time */
UPlayFabClientAPI* UPlayFabClientAPI::GetTime(FClientGetTimeRequest request,
    FDelegateOnSuccessGetTime onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTime = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetTime);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetTime";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetTime(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetTimeResult result = UPlayFabClientModelDecoder::decodeGetTimeResultResponse(response.responseData);
        if (OnSuccessGetTime.IsBound())
        {
            OnSuccessGetTime.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the key-value store of custom title settings */
UPlayFabClientAPI* UPlayFabClientAPI::GetTitleData(FClientGetTitleDataRequest request,
    FDelegateOnSuccessGetTitleData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTitleData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetTitleData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetTitleData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetTitleData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetTitleDataResult result = UPlayFabClientModelDecoder::decodeGetTitleDataResultResponse(response.responseData);
        if (OnSuccessGetTitleData.IsBound())
        {
            OnSuccessGetTitleData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the title news feed, as configured in the developer portal */
UPlayFabClientAPI* UPlayFabClientAPI::GetTitleNews(FClientGetTitleNewsRequest request,
    FDelegateOnSuccessGetTitleNews onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTitleNews = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetTitleNews);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetTitleNews";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("Count"), request.Count);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetTitleNews(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetTitleNewsResult result = UPlayFabClientModelDecoder::decodeGetTitleNewsResultResponse(response.responseData);
        if (OnSuccessGetTitleNews.IsBound())
        {
            OnSuccessGetTitleNews.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////
/** Increments the user's balance of the specified virtual currency by the stated amount */
UPlayFabClientAPI* UPlayFabClientAPI::AddUserVirtualCurrency(FClientAddUserVirtualCurrencyRequest request,
    FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAddUserVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddUserVirtualCurrency";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "") {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }
    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAddUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientModifyUserVirtualCurrencyResult result = UPlayFabClientModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessAddUserVirtualCurrency.IsBound())
        {
            OnSuccessAddUserVirtualCurrency.Execute(result, mCustomData);
        }
    }
}

/** Confirms with the payment provider that the purchase was approved (if applicable) and adjusts inventory and  virtual currency balances as appropriate */
UPlayFabClientAPI* UPlayFabClientAPI::ConfirmPurchase(FClientConfirmPurchaseRequest request,
    FDelegateOnSuccessConfirmPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessConfirmPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperConfirmPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ConfirmPurchase";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.OrderId.IsEmpty() || request.OrderId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperConfirmPurchase(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientConfirmPurchaseResult result = UPlayFabClientModelDecoder::decodeConfirmPurchaseResultResponse(response.responseData);
        if (OnSuccessConfirmPurchase.IsBound())
        {
            OnSuccessConfirmPurchase.Execute(result, mCustomData);
        }
    }
}

/** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
UPlayFabClientAPI* UPlayFabClientAPI::ConsumeItem(FClientConsumeItemRequest request,
    FDelegateOnSuccessConsumeItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessConsumeItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperConsumeItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ConsumeItem";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }
    OutRestJsonObj->SetNumberField(TEXT("ConsumeCount"), request.ConsumeCount);
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperConsumeItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientConsumeItemResult result = UPlayFabClientModelDecoder::decodeConsumeItemResultResponse(response.responseData);
        if (OnSuccessConsumeItem.IsBound())
        {
            OnSuccessConsumeItem.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the specified character's current inventory of virtual goods */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterInventory(FClientGetCharacterInventoryRequest request,
    FDelegateOnSuccessGetCharacterInventory onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterInventory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCharacterInventory);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterInventory";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCharacterInventory(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetCharacterInventoryResult result = UPlayFabClientModelDecoder::decodeGetCharacterInventoryResultResponse(response.responseData);
        if (OnSuccessGetCharacterInventory.IsBound())
        {
            OnSuccessGetCharacterInventory.Execute(result, mCustomData);
        }
    }
}

/** Retrieves a completed purchase along with its current PlayFab status. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPurchase(FClientGetPurchaseRequest request,
    FDelegateOnSuccessGetPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPurchase";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.OrderId.IsEmpty() || request.OrderId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPurchase(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPurchaseResult result = UPlayFabClientModelDecoder::decodeGetPurchaseResultResponse(response.responseData);
        if (OnSuccessGetPurchase.IsBound())
        {
            OnSuccessGetPurchase.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the user's current inventory of virtual goods */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserInventory(FClientGetUserInventoryRequest request,
    FDelegateOnSuccessGetUserInventory onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserInventory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserInventory);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserInventory";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserInventory(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetUserInventoryResult result = UPlayFabClientModelDecoder::decodeGetUserInventoryResultResponse(response.responseData);
        if (OnSuccessGetUserInventory.IsBound())
        {
            OnSuccessGetUserInventory.Execute(result, mCustomData);
        }
    }
}

/** Selects a payment option for purchase order created via StartPurchase */
UPlayFabClientAPI* UPlayFabClientAPI::PayForPurchase(FClientPayForPurchaseRequest request,
    FDelegateOnSuccessPayForPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessPayForPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperPayForPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/PayForPurchase";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.OrderId.IsEmpty() || request.OrderId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }
    if (request.ProviderName.IsEmpty() || request.ProviderName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ProviderName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ProviderName"), request.ProviderName);
    }
    if (request.Currency.IsEmpty() || request.Currency == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Currency"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Currency"), request.Currency);
    }
    if (request.ProviderTransactionId.IsEmpty() || request.ProviderTransactionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ProviderTransactionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ProviderTransactionId"), request.ProviderTransactionId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperPayForPurchase(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientPayForPurchaseResult result = UPlayFabClientModelDecoder::decodePayForPurchaseResultResponse(response.responseData);
        if (OnSuccessPayForPurchase.IsBound())
        {
            OnSuccessPayForPurchase.Execute(result, mCustomData);
        }
    }
}

/** Buys a single item with virtual currency. You must specify both the virtual currency to use to purchase,  as well as what the client believes the price to be. This lets the server fail the purchase if the price has changed. */
UPlayFabClientAPI* UPlayFabClientAPI::PurchaseItem(FClientPurchaseItemRequest request,
    FDelegateOnSuccessPurchaseItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessPurchaseItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperPurchaseItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/PurchaseItem";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.ItemId.IsEmpty() || request.ItemId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemId"), request.ItemId);
    }
    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "") {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }
    OutRestJsonObj->SetNumberField(TEXT("Price"), request.Price);
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.StoreId.IsEmpty() || request.StoreId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperPurchaseItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientPurchaseItemResult result = UPlayFabClientModelDecoder::decodePurchaseItemResultResponse(response.responseData);
        if (OnSuccessPurchaseItem.IsBound())
        {
            OnSuccessPurchaseItem.Execute(result, mCustomData);
        }
    }
}

/** Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Economy->Catalogs tab in the PlayFab Game Manager. */
UPlayFabClientAPI* UPlayFabClientAPI::RedeemCoupon(FClientRedeemCouponRequest request,
    FDelegateOnSuccessRedeemCoupon onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRedeemCoupon = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRedeemCoupon);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RedeemCoupon";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CouponCode.IsEmpty() || request.CouponCode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CouponCode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CouponCode"), request.CouponCode);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRedeemCoupon(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientRedeemCouponResult result = UPlayFabClientModelDecoder::decodeRedeemCouponResultResponse(response.responseData);
        if (OnSuccessRedeemCoupon.IsBound())
        {
            OnSuccessRedeemCoupon.Execute(result, mCustomData);
        }
    }
}

/** Creates an order for a list of items from the title catalog */
UPlayFabClientAPI* UPlayFabClientAPI::StartPurchase(FClientStartPurchaseRequest request,
    FDelegateOnSuccessStartPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessStartPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperStartPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/StartPurchase";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.StoreId.IsEmpty() || request.StoreId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }
    if (request.Items.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Items"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Items"), request.Items);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperStartPurchase(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientStartPurchaseResult result = UPlayFabClientModelDecoder::decodeStartPurchaseResultResponse(response.responseData);
        if (OnSuccessStartPurchase.IsBound())
        {
            OnSuccessStartPurchase.Execute(result, mCustomData);
        }
    }
}

/** Decrements the user's balance of the specified virtual currency by the stated amount */
UPlayFabClientAPI* UPlayFabClientAPI::SubtractUserVirtualCurrency(FClientSubtractUserVirtualCurrencyRequest request,
    FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSubtractUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperSubtractUserVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/SubtractUserVirtualCurrency";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "") {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }
    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientModifyUserVirtualCurrencyResult result = UPlayFabClientModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessSubtractUserVirtualCurrency.IsBound())
        {
            OnSuccessSubtractUserVirtualCurrency.Execute(result, mCustomData);
        }
    }
}

/** Opens the specified container, with the specified key (when required), and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
UPlayFabClientAPI* UPlayFabClientAPI::UnlockContainerInstance(FClientUnlockContainerInstanceRequest request,
    FDelegateOnSuccessUnlockContainerInstance onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlockContainerInstance = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlockContainerInstance);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlockContainerInstance";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.ContainerItemInstanceId.IsEmpty() || request.ContainerItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ContainerItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ContainerItemInstanceId"), request.ContainerItemInstanceId);
    }
    if (request.KeyItemInstanceId.IsEmpty() || request.KeyItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeyItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("KeyItemInstanceId"), request.KeyItemInstanceId);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlockContainerInstance(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlockContainerItemResult result = UPlayFabClientModelDecoder::decodeUnlockContainerItemResultResponse(response.responseData);
        if (OnSuccessUnlockContainerInstance.IsBound())
        {
            OnSuccessUnlockContainerInstance.Execute(result, mCustomData);
        }
    }
}

/** Searches target inventory for an ItemInstance matching the given CatalogItemId, if necessary unlocks it using an appropriate key, and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
UPlayFabClientAPI* UPlayFabClientAPI::UnlockContainerItem(FClientUnlockContainerItemRequest request,
    FDelegateOnSuccessUnlockContainerItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlockContainerItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlockContainerItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlockContainerItem";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.ContainerItemId.IsEmpty() || request.ContainerItemId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ContainerItemId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ContainerItemId"), request.ContainerItemId);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlockContainerItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUnlockContainerItemResult result = UPlayFabClientModelDecoder::decodeUnlockContainerItemResultResponse(response.responseData);
        if (OnSuccessUnlockContainerItem.IsBound())
        {
            OnSuccessUnlockContainerItem.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////
/** Adds the PlayFab user, based upon a match against a supplied unique identifier, to the friend list of the local user. At least one of FriendPlayFabId,FriendUsername,FriendEmail, or FriendTitleDisplayName should be initialized. */
UPlayFabClientAPI* UPlayFabClientAPI::AddFriend(FClientAddFriendRequest request,
    FDelegateOnSuccessAddFriend onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddFriend = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAddFriend);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddFriend";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }
    if (request.FriendUsername.IsEmpty() || request.FriendUsername == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendUsername"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendUsername"), request.FriendUsername);
    }
    if (request.FriendEmail.IsEmpty() || request.FriendEmail == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendEmail"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendEmail"), request.FriendEmail);
    }
    if (request.FriendTitleDisplayName.IsEmpty() || request.FriendTitleDisplayName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendTitleDisplayName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendTitleDisplayName"), request.FriendTitleDisplayName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAddFriend(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientAddFriendResult result = UPlayFabClientModelDecoder::decodeAddFriendResultResponse(response.responseData);
        if (OnSuccessAddFriend.IsBound())
        {
            OnSuccessAddFriend.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the current friend list for the local user, constrained to users who have PlayFab accounts. Friends from linked accounts (Facebook, Steam) are also included. You may optionally exclude some linked services' friends. */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendsList(FClientGetFriendsListRequest request,
    FDelegateOnSuccessGetFriendsList onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetFriendsList = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetFriendsList);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendsList";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetFriendsList(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetFriendsListResult result = UPlayFabClientModelDecoder::decodeGetFriendsListResultResponse(response.responseData);
        if (OnSuccessGetFriendsList.IsBound())
        {
            OnSuccessGetFriendsList.Execute(result, mCustomData);
        }
    }
}

/** Removes a specified user from the friend list of the local user */
UPlayFabClientAPI* UPlayFabClientAPI::RemoveFriend(FClientRemoveFriendRequest request,
    FDelegateOnSuccessRemoveFriend onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemoveFriend = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRemoveFriend);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RemoveFriend";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRemoveFriend(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientRemoveFriendResult result = UPlayFabClientModelDecoder::decodeRemoveFriendResultResponse(response.responseData);
        if (OnSuccessRemoveFriend.IsBound())
        {
            OnSuccessRemoveFriend.Execute(result, mCustomData);
        }
    }
}

/** Updates the tag list for a specified user in the friend list of the local user */
UPlayFabClientAPI* UPlayFabClientAPI::SetFriendTags(FClientSetFriendTagsRequest request,
    FDelegateOnSuccessSetFriendTags onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetFriendTags = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperSetFriendTags);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/SetFriendTags";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }
    // Check to see if string is empty
    if (request.Tags.IsEmpty() || request.Tags == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Tags"));
    } else {
        TArray<FString> TagsArray;
        FString(request.Tags).ParseIntoArray(TagsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Tags"), TagsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperSetFriendTags(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientSetFriendTagsResult result = UPlayFabClientModelDecoder::decodeSetFriendTagsResultResponse(response.responseData);
        if (OnSuccessSetFriendTags.IsBound())
        {
            OnSuccessSetFriendTags.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// IOS-Specific APIs
//////////////////////////////////////////////////////
/** Registers the iOS device to receive push notifications */
UPlayFabClientAPI* UPlayFabClientAPI::RegisterForIOSPushNotification(FClientRegisterForIOSPushNotificationRequest request,
    FDelegateOnSuccessRegisterForIOSPushNotification onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRegisterForIOSPushNotification = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRegisterForIOSPushNotification);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RegisterForIOSPushNotification";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.DeviceToken.IsEmpty() || request.DeviceToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DeviceToken"), request.DeviceToken);
    }
    OutRestJsonObj->SetBoolField(TEXT("SendPushNotificationConfirmation"), request.SendPushNotificationConfirmation);
    if (request.ConfirmationMessage.IsEmpty() || request.ConfirmationMessage == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ConfirmationMessage"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ConfirmationMessage"), request.ConfirmationMessage);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRegisterForIOSPushNotification(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientRegisterForIOSPushNotificationResult result = UPlayFabClientModelDecoder::decodeRegisterForIOSPushNotificationResultResponse(response.responseData);
        if (OnSuccessRegisterForIOSPushNotification.IsBound())
        {
            OnSuccessRegisterForIOSPushNotification.Execute(result, mCustomData);
        }
    }
}

/** Restores all in-app purchases based on the given refresh receipt. */
UPlayFabClientAPI* UPlayFabClientAPI::RestoreIOSPurchases(FClientRestoreIOSPurchasesRequest request,
    FDelegateOnSuccessRestoreIOSPurchases onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRestoreIOSPurchases = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRestoreIOSPurchases);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RestoreIOSPurchases";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.ReceiptData.IsEmpty() || request.ReceiptData == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptData"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReceiptData"), request.ReceiptData);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRestoreIOSPurchases(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientRestoreIOSPurchasesResult result = UPlayFabClientModelDecoder::decodeRestoreIOSPurchasesResultResponse(response.responseData);
        if (OnSuccessRestoreIOSPurchases.IsBound())
        {
            OnSuccessRestoreIOSPurchases.Execute(result, mCustomData);
        }
    }
}

/** Validates with the Apple store that the receipt for an iOS in-app purchase is valid and that it matches the purchased catalog item */
UPlayFabClientAPI* UPlayFabClientAPI::ValidateIOSReceipt(FClientValidateIOSReceiptRequest request,
    FDelegateOnSuccessValidateIOSReceipt onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessValidateIOSReceipt = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperValidateIOSReceipt);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ValidateIOSReceipt";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.ReceiptData.IsEmpty() || request.ReceiptData == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptData"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReceiptData"), request.ReceiptData);
    }
    if (request.CurrencyCode.IsEmpty() || request.CurrencyCode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CurrencyCode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), request.CurrencyCode);
    }
    OutRestJsonObj->SetNumberField(TEXT("PurchasePrice"), request.PurchasePrice);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperValidateIOSReceipt(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientValidateIOSReceiptResult result = UPlayFabClientModelDecoder::decodeValidateIOSReceiptResultResponse(response.responseData);
        if (OnSuccessValidateIOSReceipt.IsBound())
        {
            OnSuccessValidateIOSReceipt.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////
/** Get details about all current running game servers matching the given parameters. */
UPlayFabClientAPI* UPlayFabClientAPI::GetCurrentGames(FClientCurrentGamesRequest request,
    FDelegateOnSuccessGetCurrentGames onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCurrentGames = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCurrentGames);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCurrentGames";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    FString temp_Region;
    if (GetEnumValueToString<ERegion>(TEXT("ERegion"), request.Region, temp_Region))
        OutRestJsonObj->SetStringField(TEXT("Region"), temp_Region);
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }
    if (request.GameMode.IsEmpty() || request.GameMode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    if (request.TagFilter != nullptr) OutRestJsonObj->SetObjectField(TEXT("TagFilter"), request.TagFilter);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCurrentGames(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientCurrentGamesResult result = UPlayFabClientModelDecoder::decodeCurrentGamesResultResponse(response.responseData);
        if (OnSuccessGetCurrentGames.IsBound())
        {
            OnSuccessGetCurrentGames.Execute(result, mCustomData);
        }
    }
}

/**  Get details about the regions hosting game servers matching the given parameters. */
UPlayFabClientAPI* UPlayFabClientAPI::GetGameServerRegions(FClientGameServerRegionsRequest request,
    FDelegateOnSuccessGetGameServerRegions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetGameServerRegions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetGameServerRegions);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetGameServerRegions";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetGameServerRegions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGameServerRegionsResult result = UPlayFabClientModelDecoder::decodeGameServerRegionsResultResponse(response.responseData);
        if (OnSuccessGetGameServerRegions.IsBound())
        {
            OnSuccessGetGameServerRegions.Execute(result, mCustomData);
        }
    }
}

/** Attempts to locate a game session matching the given parameters. If the goal is to match the player into a specific active session, only the LobbyId is required. Otherwise, the BuildVersion, GameMode, and Region are all required parameters. Note that parameters specified in the search are required (they are not weighting factors). If a slot is found in a server instance matching the parameters, the slot will be assigned to that player, removing it from the availabe set. In that case, the information on the game session will be returned, otherwise the Status returned will be GameNotFound. Note that EnableQueue is deprecated at this time. */
UPlayFabClientAPI* UPlayFabClientAPI::Matchmake(FClientMatchmakeRequest request,
    FDelegateOnSuccessMatchmake onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessMatchmake = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperMatchmake);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/Matchmake";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }
    FString temp_Region;
    if (GetEnumValueToString<ERegion>(TEXT("ERegion"), request.Region, temp_Region))
        OutRestJsonObj->SetStringField(TEXT("Region"), temp_Region);
    if (request.GameMode.IsEmpty() || request.GameMode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    OutRestJsonObj->SetBoolField(TEXT("StartNewIfNoneFound"), request.StartNewIfNoneFound);
    if (request.TagFilter != nullptr) OutRestJsonObj->SetObjectField(TEXT("TagFilter"), request.TagFilter);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperMatchmake(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientMatchmakeResult result = UPlayFabClientModelDecoder::decodeMatchmakeResultResponse(response.responseData);
        if (OnSuccessMatchmake.IsBound())
        {
            OnSuccessMatchmake.Execute(result, mCustomData);
        }
    }
}

/** Start a new game server with a given configuration, add the current player and return the connection information. */
UPlayFabClientAPI* UPlayFabClientAPI::StartGame(FClientStartGameRequest request,
    FDelegateOnSuccessStartGame onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessStartGame = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperStartGame);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/StartGame";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }
    FString temp_Region;
    if (GetEnumValueToString<ERegion>(TEXT("ERegion"), request.Region, temp_Region))
        OutRestJsonObj->SetStringField(TEXT("Region"), temp_Region);
    if (request.GameMode.IsEmpty() || request.GameMode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.CustomCommandLineData.IsEmpty() || request.CustomCommandLineData == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CustomCommandLineData"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CustomCommandLineData"), request.CustomCommandLineData);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperStartGame(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientStartGameResult result = UPlayFabClientModelDecoder::decodeStartGameResultResponse(response.responseData);
        if (OnSuccessStartGame.IsBound())
        {
            OnSuccessStartGame.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Android-Specific APIs
//////////////////////////////////////////////////////
/** Registers the Android device to receive push notifications */
UPlayFabClientAPI* UPlayFabClientAPI::AndroidDevicePushNotificationRegistration(FClientAndroidDevicePushNotificationRegistrationRequest request,
    FDelegateOnSuccessAndroidDevicePushNotificationRegistration onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAndroidDevicePushNotificationRegistration = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAndroidDevicePushNotificationRegistration);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AndroidDevicePushNotificationRegistration";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.DeviceToken.IsEmpty() || request.DeviceToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DeviceToken"), request.DeviceToken);
    }
    OutRestJsonObj->SetBoolField(TEXT("SendPushNotificationConfirmation"), request.SendPushNotificationConfirmation);
    if (request.ConfirmationMessage.IsEmpty() || request.ConfirmationMessage == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ConfirmationMessage"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ConfirmationMessage"), request.ConfirmationMessage);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAndroidDevicePushNotificationRegistration(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientAndroidDevicePushNotificationRegistrationResult result = UPlayFabClientModelDecoder::decodeAndroidDevicePushNotificationRegistrationResultResponse(response.responseData);
        if (OnSuccessAndroidDevicePushNotificationRegistration.IsBound())
        {
            OnSuccessAndroidDevicePushNotificationRegistration.Execute(result, mCustomData);
        }
    }
}

/** Validates a Google Play purchase and gives the corresponding item to the player. */
UPlayFabClientAPI* UPlayFabClientAPI::ValidateGooglePlayPurchase(FClientValidateGooglePlayPurchaseRequest request,
    FDelegateOnSuccessValidateGooglePlayPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessValidateGooglePlayPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperValidateGooglePlayPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ValidateGooglePlayPurchase";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.ReceiptJson.IsEmpty() || request.ReceiptJson == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptJson"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReceiptJson"), request.ReceiptJson);
    }
    if (request.Signature.IsEmpty() || request.Signature == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Signature"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Signature"), request.Signature);
    }
    if (request.CurrencyCode.IsEmpty() || request.CurrencyCode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CurrencyCode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), request.CurrencyCode);
    }
    OutRestJsonObj->SetNumberField(TEXT("PurchasePrice"), request.PurchasePrice);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperValidateGooglePlayPurchase(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientValidateGooglePlayPurchaseResult result = UPlayFabClientModelDecoder::decodeValidateGooglePlayPurchaseResultResponse(response.responseData);
        if (OnSuccessValidateGooglePlayPurchase.IsBound())
        {
            OnSuccessValidateGooglePlayPurchase.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////
/** Writes a character-based event into PlayStream. */
UPlayFabClientAPI* UPlayFabClientAPI::WriteCharacterEvent(FClientWriteClientCharacterEventRequest request,
    FDelegateOnSuccessWriteCharacterEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessWriteCharacterEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperWriteCharacterEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/WriteCharacterEvent";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.EventName.IsEmpty() || request.EventName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }
    if (request.Timestamp.IsEmpty() || request.Timestamp == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }
    if (request.Body != nullptr) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperWriteCharacterEvent(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientWriteEventResponse result = UPlayFabClientModelDecoder::decodeWriteEventResponseResponse(response.responseData);
        if (OnSuccessWriteCharacterEvent.IsBound())
        {
            OnSuccessWriteCharacterEvent.Execute(result, mCustomData);
        }
    }
}

/** Writes a player-based event into PlayStream. */
UPlayFabClientAPI* UPlayFabClientAPI::WritePlayerEvent(FClientWriteClientPlayerEventRequest request,
    FDelegateOnSuccessWritePlayerEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessWritePlayerEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperWritePlayerEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/WritePlayerEvent";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.EventName.IsEmpty() || request.EventName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }
    if (request.Timestamp.IsEmpty() || request.Timestamp == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }
    if (request.Body != nullptr) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperWritePlayerEvent(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientWriteEventResponse result = UPlayFabClientModelDecoder::decodeWriteEventResponseResponse(response.responseData);
        if (OnSuccessWritePlayerEvent.IsBound())
        {
            OnSuccessWritePlayerEvent.Execute(result, mCustomData);
        }
    }
}

/** Writes a title-based event into PlayStream. */
UPlayFabClientAPI* UPlayFabClientAPI::WriteTitleEvent(FClientWriteTitleEventRequest request,
    FDelegateOnSuccessWriteTitleEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessWriteTitleEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperWriteTitleEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/WriteTitleEvent";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.EventName.IsEmpty() || request.EventName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }
    if (request.Timestamp.IsEmpty() || request.Timestamp == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }
    if (request.Body != nullptr) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperWriteTitleEvent(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientWriteEventResponse result = UPlayFabClientModelDecoder::decodeWriteEventResponseResponse(response.responseData);
        if (OnSuccessWriteTitleEvent.IsBound())
        {
            OnSuccessWriteTitleEvent.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////
/** Adds users to the set of those able to update both the shared data, as well as the set of users in the group. Only users in the group can add new members. */
UPlayFabClientAPI* UPlayFabClientAPI::AddSharedGroupMembers(FClientAddSharedGroupMembersRequest request,
    FDelegateOnSuccessAddSharedGroupMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddSharedGroupMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAddSharedGroupMembers);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddSharedGroupMembers";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }
    // Check to see if string is empty
    if (request.PlayFabIds.IsEmpty() || request.PlayFabIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabIds"));
    } else {
        TArray<FString> PlayFabIdsArray;
        FString(request.PlayFabIds).ParseIntoArray(PlayFabIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAddSharedGroupMembers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientAddSharedGroupMembersResult result = UPlayFabClientModelDecoder::decodeAddSharedGroupMembersResultResponse(response.responseData);
        if (OnSuccessAddSharedGroupMembers.IsBound())
        {
            OnSuccessAddSharedGroupMembers.Execute(result, mCustomData);
        }
    }
}

/** Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of the group. Upon creation, the current user will be the only member of the group. */
UPlayFabClientAPI* UPlayFabClientAPI::CreateSharedGroup(FClientCreateSharedGroupRequest request,
    FDelegateOnSuccessCreateSharedGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateSharedGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperCreateSharedGroup);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/CreateSharedGroup";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperCreateSharedGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientCreateSharedGroupResult result = UPlayFabClientModelDecoder::decodeCreateSharedGroupResultResponse(response.responseData);
        if (OnSuccessCreateSharedGroup.IsBound())
        {
            OnSuccessCreateSharedGroup.Execute(result, mCustomData);
        }
    }
}

/** Retrieves data stored in a shared group object, as well as the list of members in the group. Non-members of the group may use this to retrieve group data, including membership, but they will not receive data for keys marked as private. */
UPlayFabClientAPI* UPlayFabClientAPI::GetSharedGroupData(FClientGetSharedGroupDataRequest request,
    FDelegateOnSuccessGetSharedGroupData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetSharedGroupData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetSharedGroupData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetSharedGroupData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetBoolField(TEXT("GetMembers"), request.GetMembers);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetSharedGroupData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetSharedGroupDataResult result = UPlayFabClientModelDecoder::decodeGetSharedGroupDataResultResponse(response.responseData);
        if (OnSuccessGetSharedGroupData.IsBound())
        {
            OnSuccessGetSharedGroupData.Execute(result, mCustomData);
        }
    }
}

/** Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the group can remove members. If as a result of the call, zero users remain with access, the group and its associated data will be deleted. */
UPlayFabClientAPI* UPlayFabClientAPI::RemoveSharedGroupMembers(FClientRemoveSharedGroupMembersRequest request,
    FDelegateOnSuccessRemoveSharedGroupMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemoveSharedGroupMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRemoveSharedGroupMembers);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RemoveSharedGroupMembers";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }
    // Check to see if string is empty
    if (request.PlayFabIds.IsEmpty() || request.PlayFabIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabIds"));
    } else {
        TArray<FString> PlayFabIdsArray;
        FString(request.PlayFabIds).ParseIntoArray(PlayFabIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRemoveSharedGroupMembers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientRemoveSharedGroupMembersResult result = UPlayFabClientModelDecoder::decodeRemoveSharedGroupMembersResultResponse(response.responseData);
        if (OnSuccessRemoveSharedGroupMembers.IsBound())
        {
            OnSuccessRemoveSharedGroupMembers.Execute(result, mCustomData);
        }
    }
}

/** Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group can update the data. */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateSharedGroupData(FClientUpdateSharedGroupDataRequest request,
    FDelegateOnSuccessUpdateSharedGroupData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateSharedGroupData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateSharedGroupData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateSharedGroupData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateSharedGroupData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUpdateSharedGroupDataResult result = UPlayFabClientModelDecoder::decodeUpdateSharedGroupDataResultResponse(response.responseData);
        if (OnSuccessUpdateSharedGroupData.IsBound())
        {
            OnSuccessUpdateSharedGroupData.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Sony-specific APIs
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////
/** Executes a CloudScript function, with the 'currentPlayerId' set to the PlayFab ID of the authenticated player. */
UPlayFabClientAPI* UPlayFabClientAPI::ExecuteCloudScript(FClientExecuteCloudScriptRequest request,
    FDelegateOnSuccessExecuteCloudScript onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessExecuteCloudScript = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperExecuteCloudScript);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ExecuteCloudScript";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.FunctionName.IsEmpty() || request.FunctionName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FunctionName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FunctionName"), request.FunctionName);
    }
    if (request.FunctionParameter != nullptr) OutRestJsonObj->SetObjectField(TEXT("FunctionParameter"), request.FunctionParameter);
    FString temp_RevisionSelection;
    if (GetEnumValueToString<ECloudScriptRevisionOption>(TEXT("ECloudScriptRevisionOption"), request.RevisionSelection, temp_RevisionSelection))
        OutRestJsonObj->SetStringField(TEXT("RevisionSelection"), temp_RevisionSelection);
    OutRestJsonObj->SetNumberField(TEXT("SpecificRevision"), request.SpecificRevision);
    OutRestJsonObj->SetBoolField(TEXT("GeneratePlayStreamEvent"), request.GeneratePlayStreamEvent);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperExecuteCloudScript(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientExecuteCloudScriptResult result = UPlayFabClientModelDecoder::decodeExecuteCloudScriptResultResponse(response.responseData);
        if (OnSuccessExecuteCloudScript.IsBound())
        {
            OnSuccessExecuteCloudScript.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////
/** This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent  HTTP GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will attempt to  retrieve the metadata of the content. Note that a successful result does not guarantee the existence of this content -  if it has not been uploaded, the query to retrieve the data will fail. See this post for more information:  https://community.playfab.com/hc/en-us/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service.  Also, please be aware that the Content service is specifically PlayFab's CDN offering, for which standard CDN rates apply. */
UPlayFabClientAPI* UPlayFabClientAPI::GetContentDownloadUrl(FClientGetContentDownloadUrlRequest request,
    FDelegateOnSuccessGetContentDownloadUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetContentDownloadUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetContentDownloadUrl);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetContentDownloadUrl";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.Key.IsEmpty() || request.Key == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }
    if (request.HttpMethod.IsEmpty() || request.HttpMethod == "") {
        OutRestJsonObj->SetFieldNull(TEXT("HttpMethod"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("HttpMethod"), request.HttpMethod);
    }
    OutRestJsonObj->SetBoolField(TEXT("ThruCDN"), request.ThruCDN);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetContentDownloadUrl(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetContentDownloadUrlResult result = UPlayFabClientModelDecoder::decodeGetContentDownloadUrlResultResponse(response.responseData);
        if (OnSuccessGetContentDownloadUrl.IsBound())
        {
            OnSuccessGetContentDownloadUrl.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////
/** Lists all of the characters that belong to a specific user. CharacterIds are not globally unique; characterId must be evaluated with the parent PlayFabId to guarantee uniqueness. */
UPlayFabClientAPI* UPlayFabClientAPI::GetAllUsersCharacters(FClientListUsersCharactersRequest request,
    FDelegateOnSuccessGetAllUsersCharacters onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetAllUsersCharacters = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetAllUsersCharacters);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetAllUsersCharacters";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetAllUsersCharacters(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientListUsersCharactersResult result = UPlayFabClientModelDecoder::decodeListUsersCharactersResultResponse(response.responseData);
        if (OnSuccessGetAllUsersCharacters.IsBound())
        {
            OnSuccessGetAllUsersCharacters.Execute(result, mCustomData);
        }
    }
}

/** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterLeaderboard(FClientGetCharacterLeaderboardRequest request,
    FDelegateOnSuccessGetCharacterLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCharacterLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterLeaderboard";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CharacterType.IsEmpty() || request.CharacterType == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterType"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterType"), request.CharacterType);
    }
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCharacterLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetCharacterLeaderboardResult result = UPlayFabClientModelDecoder::decodeGetCharacterLeaderboardResultResponse(response.responseData);
        if (OnSuccessGetCharacterLeaderboard.IsBound())
        {
            OnSuccessGetCharacterLeaderboard.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the details of all title-specific statistics for the user */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterStatistics(FClientGetCharacterStatisticsRequest request,
    FDelegateOnSuccessGetCharacterStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCharacterStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterStatistics";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCharacterStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetCharacterStatisticsResult result = UPlayFabClientModelDecoder::decodeGetCharacterStatisticsResultResponse(response.responseData);
        if (OnSuccessGetCharacterStatistics.IsBound())
        {
            OnSuccessGetCharacterStatistics.Execute(result, mCustomData);
        }
    }
}

/** Retrieves a list of ranked characters for the given statistic, centered on the requested Character ID */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardAroundCharacter(FClientGetLeaderboardAroundCharacterRequest request,
    FDelegateOnSuccessGetLeaderboardAroundCharacter onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboardAroundCharacter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetLeaderboardAroundCharacter);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardAroundCharacter";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.CharacterType.IsEmpty() || request.CharacterType == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterType"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterType"), request.CharacterType);
    }
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetLeaderboardAroundCharacter(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetLeaderboardAroundCharacterResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardAroundCharacterResultResponse(response.responseData);
        if (OnSuccessGetLeaderboardAroundCharacter.IsBound())
        {
            OnSuccessGetLeaderboardAroundCharacter.Execute(result, mCustomData);
        }
    }
}

/** Retrieves a list of all of the user's characters for the given statistic. */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardForUserCharacters(FClientGetLeaderboardForUsersCharactersRequest request,
    FDelegateOnSuccessGetLeaderboardForUserCharacters onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboardForUserCharacters = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetLeaderboardForUserCharacters);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardForUserCharacters";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetLeaderboardForUserCharacters(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetLeaderboardForUsersCharactersResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardForUsersCharactersResultResponse(response.responseData);
        if (OnSuccessGetLeaderboardForUserCharacters.IsBound())
        {
            OnSuccessGetLeaderboardForUserCharacters.Execute(result, mCustomData);
        }
    }
}

/** Grants the specified character type to the user. CharacterIds are not globally unique; characterId must be evaluated with the parent PlayFabId to guarantee uniqueness. */
UPlayFabClientAPI* UPlayFabClientAPI::GrantCharacterToUser(FClientGrantCharacterToUserRequest request,
    FDelegateOnSuccessGrantCharacterToUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGrantCharacterToUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGrantCharacterToUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GrantCharacterToUser";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.ItemId.IsEmpty() || request.ItemId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemId"), request.ItemId);
    }
    if (request.CharacterName.IsEmpty() || request.CharacterName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterName"), request.CharacterName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGrantCharacterToUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGrantCharacterToUserResult result = UPlayFabClientModelDecoder::decodeGrantCharacterToUserResultResponse(response.responseData);
        if (OnSuccessGrantCharacterToUser.IsBound())
        {
            OnSuccessGrantCharacterToUser.Execute(result, mCustomData);
        }
    }
}

/** Updates the values of the specified title-specific statistics for the specific character. By default, clients are not permitted to update statistics. Developers may override this setting in the Game Manager > Settings > API Features. */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateCharacterStatistics(FClientUpdateCharacterStatisticsRequest request,
    FDelegateOnSuccessUpdateCharacterStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateCharacterStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateCharacterStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateCharacterStatistics";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.CharacterStatistics != nullptr) OutRestJsonObj->SetObjectField(TEXT("CharacterStatistics"), request.CharacterStatistics);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateCharacterStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUpdateCharacterStatisticsResult result = UPlayFabClientModelDecoder::decodeUpdateCharacterStatisticsResultResponse(response.responseData);
        if (OnSuccessUpdateCharacterStatistics.IsBound())
        {
            OnSuccessUpdateCharacterStatistics.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////
/** Retrieves the title-specific custom data for the character which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterData(FClientGetCharacterDataRequest request,
    FDelegateOnSuccessGetCharacterData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCharacterData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCharacterData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetCharacterDataResult result = UPlayFabClientModelDecoder::decodeGetCharacterDataResultResponse(response.responseData);
        if (OnSuccessGetCharacterData.IsBound())
        {
            OnSuccessGetCharacterData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the title-specific custom data for the character which can only be read by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterReadOnlyData(FClientGetCharacterDataRequest request,
    FDelegateOnSuccessGetCharacterReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCharacterReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterReadOnlyData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCharacterReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetCharacterDataResult result = UPlayFabClientModelDecoder::decodeGetCharacterDataResultResponse(response.responseData);
        if (OnSuccessGetCharacterReadOnlyData.IsBound())
        {
            OnSuccessGetCharacterReadOnlyData.Execute(result, mCustomData);
        }
    }
}

/** Creates and updates the title-specific custom data for the user's character which is readable  and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateCharacterData(FClientUpdateCharacterDataRequest request,
    FDelegateOnSuccessUpdateCharacterData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateCharacterData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateCharacterData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateCharacterData";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateCharacterData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientUpdateCharacterDataResult result = UPlayFabClientModelDecoder::decodeUpdateCharacterDataResultResponse(response.responseData);
        if (OnSuccessUpdateCharacterData.IsBound())
        {
            OnSuccessUpdateCharacterData.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Amazon-Specific APIs
//////////////////////////////////////////////////////
/** Validates with Amazon that the receipt for an Amazon App Store in-app purchase is valid and that it matches the purchased catalog item */
UPlayFabClientAPI* UPlayFabClientAPI::ValidateAmazonIAPReceipt(FClientValidateAmazonReceiptRequest request,
    FDelegateOnSuccessValidateAmazonIAPReceipt onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessValidateAmazonIAPReceipt = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperValidateAmazonIAPReceipt);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ValidateAmazonIAPReceipt";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.ReceiptId.IsEmpty() || request.ReceiptId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReceiptId"), request.ReceiptId);
    }
    if (request.UserId.IsEmpty() || request.UserId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("UserId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("UserId"), request.UserId);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.CurrencyCode.IsEmpty() || request.CurrencyCode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CurrencyCode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), request.CurrencyCode);
    }
    OutRestJsonObj->SetNumberField(TEXT("PurchasePrice"), request.PurchasePrice);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperValidateAmazonIAPReceipt(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientValidateAmazonReceiptResult result = UPlayFabClientModelDecoder::decodeValidateAmazonReceiptResultResponse(response.responseData);
        if (OnSuccessValidateAmazonIAPReceipt.IsBound())
        {
            OnSuccessValidateAmazonIAPReceipt.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Trading
//////////////////////////////////////////////////////
/** Accepts an open trade. If the call is successful, the offered and accepted items will be swapped between the two players' inventories. */
UPlayFabClientAPI* UPlayFabClientAPI::AcceptTrade(FClientAcceptTradeRequest request,
    FDelegateOnSuccessAcceptTrade onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAcceptTrade = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAcceptTrade);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AcceptTrade";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.OfferingPlayerId.IsEmpty() || request.OfferingPlayerId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OfferingPlayerId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OfferingPlayerId"), request.OfferingPlayerId);
    }
    if (request.TradeId.IsEmpty() || request.TradeId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TradeId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TradeId"), request.TradeId);
    }
    // Check to see if string is empty
    if (request.AcceptedInventoryInstanceIds.IsEmpty() || request.AcceptedInventoryInstanceIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AcceptedInventoryInstanceIds"));
    } else {
        TArray<FString> AcceptedInventoryInstanceIdsArray;
        FString(request.AcceptedInventoryInstanceIds).ParseIntoArray(AcceptedInventoryInstanceIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("AcceptedInventoryInstanceIds"), AcceptedInventoryInstanceIdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAcceptTrade(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientAcceptTradeResponse result = UPlayFabClientModelDecoder::decodeAcceptTradeResponseResponse(response.responseData);
        if (OnSuccessAcceptTrade.IsBound())
        {
            OnSuccessAcceptTrade.Execute(result, mCustomData);
        }
    }
}

/** Cancels an open trade. */
UPlayFabClientAPI* UPlayFabClientAPI::CancelTrade(FClientCancelTradeRequest request,
    FDelegateOnSuccessCancelTrade onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCancelTrade = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperCancelTrade);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/CancelTrade";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.TradeId.IsEmpty() || request.TradeId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TradeId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TradeId"), request.TradeId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperCancelTrade(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientCancelTradeResponse result = UPlayFabClientModelDecoder::decodeCancelTradeResponseResponse(response.responseData);
        if (OnSuccessCancelTrade.IsBound())
        {
            OnSuccessCancelTrade.Execute(result, mCustomData);
        }
    }
}

/** Gets all trades the player has either opened or accepted, optionally filtered by trade status. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayerTrades(FClientGetPlayerTradesRequest request,
    FDelegateOnSuccessGetPlayerTrades onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerTrades = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayerTrades);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayerTrades";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    FString temp_StatusFilter;
    if (GetEnumValueToString<ETradeStatus>(TEXT("ETradeStatus"), request.StatusFilter, temp_StatusFilter))
        OutRestJsonObj->SetStringField(TEXT("StatusFilter"), temp_StatusFilter);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayerTrades(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayerTradesResponse result = UPlayFabClientModelDecoder::decodeGetPlayerTradesResponseResponse(response.responseData);
        if (OnSuccessGetPlayerTrades.IsBound())
        {
            OnSuccessGetPlayerTrades.Execute(result, mCustomData);
        }
    }
}

/** Gets the current status of an existing trade. */
UPlayFabClientAPI* UPlayFabClientAPI::GetTradeStatus(FClientGetTradeStatusRequest request,
    FDelegateOnSuccessGetTradeStatus onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTradeStatus = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetTradeStatus);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetTradeStatus";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.OfferingPlayerId.IsEmpty() || request.OfferingPlayerId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OfferingPlayerId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OfferingPlayerId"), request.OfferingPlayerId);
    }
    if (request.TradeId.IsEmpty() || request.TradeId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TradeId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TradeId"), request.TradeId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetTradeStatus(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetTradeStatusResponse result = UPlayFabClientModelDecoder::decodeGetTradeStatusResponseResponse(response.responseData);
        if (OnSuccessGetTradeStatus.IsBound())
        {
            OnSuccessGetTradeStatus.Execute(result, mCustomData);
        }
    }
}

/** Opens a new outstanding trade. */
UPlayFabClientAPI* UPlayFabClientAPI::OpenTrade(FClientOpenTradeRequest request,
    FDelegateOnSuccessOpenTrade onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessOpenTrade = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperOpenTrade);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/OpenTrade";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.OfferedInventoryInstanceIds.IsEmpty() || request.OfferedInventoryInstanceIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OfferedInventoryInstanceIds"));
    } else {
        TArray<FString> OfferedInventoryInstanceIdsArray;
        FString(request.OfferedInventoryInstanceIds).ParseIntoArray(OfferedInventoryInstanceIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("OfferedInventoryInstanceIds"), OfferedInventoryInstanceIdsArray);
    }
    // Check to see if string is empty
    if (request.RequestedCatalogItemIds.IsEmpty() || request.RequestedCatalogItemIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RequestedCatalogItemIds"));
    } else {
        TArray<FString> RequestedCatalogItemIdsArray;
        FString(request.RequestedCatalogItemIds).ParseIntoArray(RequestedCatalogItemIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("RequestedCatalogItemIds"), RequestedCatalogItemIdsArray);
    }
    // Check to see if string is empty
    if (request.AllowedPlayerIds.IsEmpty() || request.AllowedPlayerIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AllowedPlayerIds"));
    } else {
        TArray<FString> AllowedPlayerIdsArray;
        FString(request.AllowedPlayerIds).ParseIntoArray(AllowedPlayerIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("AllowedPlayerIds"), AllowedPlayerIdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperOpenTrade(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientOpenTradeResponse result = UPlayFabClientModelDecoder::decodeOpenTradeResponseResponse(response.responseData);
        if (OnSuccessOpenTrade.IsBound())
        {
            OnSuccessOpenTrade.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Advertising
//////////////////////////////////////////////////////
/** Attributes an install for advertisment. */
UPlayFabClientAPI* UPlayFabClientAPI::AttributeInstall(FClientAttributeInstallRequest request,
    FDelegateOnSuccessAttributeInstall onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAttributeInstall = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAttributeInstall);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AttributeInstall";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.Idfa.IsEmpty() || request.Idfa == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Idfa"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Idfa"), request.Idfa);
    }
    if (request.Adid.IsEmpty() || request.Adid == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Adid"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Adid"), request.Adid);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAttributeInstall(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientAttributeInstallResult result = UPlayFabClientModelDecoder::decodeAttributeInstallResultResponse(response.responseData);
        if (OnSuccessAttributeInstall.IsBound())
        {
            OnSuccessAttributeInstall.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Guilds
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////
/** List all segments that a player currently belongs to at this moment in time. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayerSegments(FClientGetPlayerSegmentsRequest request,
    FDelegateOnSuccessGetPlayerSegments onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerSegments = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayerSegments);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayerSegments";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayerSegments(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayerSegmentsResult result = UPlayFabClientModelDecoder::decodeGetPlayerSegmentsResultResponse(response.responseData);
        if (OnSuccessGetPlayerSegments.IsBound())
        {
            OnSuccessGetPlayerSegments.Execute(result, mCustomData);
        }
    }
}

/** Get all tags with a given Namespace (optional) from a player profile. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayerTags(FClientGetPlayerTagsRequest request,
    FDelegateOnSuccessGetPlayerTags onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerTags = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayerTags);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayerTags";
    manager->useSessionTicket = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Namespace.IsEmpty() || request.Namespace == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Namespace"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Namespace"), request.Namespace);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayerTags(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientGetPlayerTagsResult result = UPlayFabClientModelDecoder::decodeGetPlayerTagsResultResponse(response.responseData);
        if (OnSuccessGetPlayerTags.IsBound())
        {
            OnSuccessGetPlayerTags.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Windows
//////////////////////////////////////////////////////
/** Validates with Windows that the receipt for an Windows App Store in-app purchase is valid and that it matches the purchased catalog item */
UPlayFabClientAPI* UPlayFabClientAPI::ValidateWindowsStoreReceipt(FClientValidateWindowsReceiptRequest request,
    FDelegateOnSuccessValidateWindowsStoreReceipt onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessValidateWindowsStoreReceipt = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperValidateWindowsStoreReceipt);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ValidateWindowsStoreReceipt";
    manager->useSessionTicket = false;

    // Serialize all the request properties to json
    if (request.Receipt.IsEmpty() || request.Receipt == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Receipt"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Receipt"), request.Receipt);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.CurrencyCode.IsEmpty() || request.CurrencyCode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CurrencyCode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), request.CurrencyCode);
    }
    OutRestJsonObj->SetNumberField(TEXT("PurchasePrice"), request.PurchasePrice);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperValidateWindowsStoreReceipt(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FClientValidateWindowsReceiptResult result = UPlayFabClientModelDecoder::decodeValidateWindowsReceiptResultResponse(response.responseData);
        if (OnSuccessValidateWindowsStoreReceipt.IsBound())
        {
            OnSuccessValidateWindowsStoreReceipt.Execute(result, mCustomData);
        }
    }
}



void UPlayFabClientAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    // Be sure that we have no data from previous response
    ResetResponseData();

    if (!IsValidLowLevel())
    {
        UE_LOG(LogPlayFab, Error, TEXT("The request object is invalid during OnProcessRequestComplete."));
        return;
    }
    if (!OnPlayFabResponse.IsBound())
    {
        UE_LOG(LogPlayFab, Error, TEXT("OnPlayFabResponse has come un-bound during OnProcessRequestComplete."));
        return;
    }

    FPlayFabBaseModel myResponse;

    // Check we have result to process further
    if (!bWasSuccessful)
    {
        UE_LOG(LogPlayFab, Error, TEXT("Request failed: %s"), *Request->GetURL());

        // Broadcast the result event
        myResponse.responseError.hasError = true;
        myResponse.responseError.ErrorCode = 503;
        myResponse.responseError.ErrorName = "Unable to contact server";
        myResponse.responseError.ErrorMessage = "Unable to contact server";

        OnPlayFabResponse.Broadcast(myResponse, mCustomData, false);

        return;
    }

    // Save response data as a string
    ResponseContent = Response->GetContentAsString();

    // Save response code as int32
    ResponseCode = Response->GetResponseCode();

    // Try to deserialize data to JSON
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);
    FJsonSerializer::Deserialize(JsonReader, ResponseJsonObj->GetRootObject());

    // Decide whether the request was successful
    bIsValidJsonResponse = bWasSuccessful && ResponseJsonObj->GetRootObject().IsValid();

    // Log errors
    if (!bIsValidJsonResponse)
    {
        UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));
    }

    // Log response state
    UE_LOG(LogPlayFab, Log, TEXT("Response : %s"), *ResponseContent);

    myResponse.responseError.decodeError(ResponseJsonObj);
    myResponse.responseData = ResponseJsonObj;
    IPlayFab* pfSettings = &(IPlayFab::Get());

    if (isLoginRequest && !myResponse.responseError.hasError)
    {
        pfSettings->setSessionTicket(myResponse.responseData->GetObjectField("data")->GetStringField("SessionTicket"));
        bool needsAttribution = myResponse.responseData->GetObjectField("data")->GetBoolField("SessionTicket");
        if (needsAttribution && !pfSettings->DisableAdvertising && !pfSettings->AdvertisingIdType.IsEmpty() && !pfSettings->AdvertisingIdValue.IsEmpty())
        {
            FClientAttributeInstallRequest request;
            bool makeAttrCall = true;
            if (pfSettings->AdvertisingIdType == pfSettings->AD_TYPE_IDFA)
                request.Idfa = pfSettings->AdvertisingIdValue;
            else if (pfSettings->AdvertisingIdType == pfSettings->AD_TYPE_ANDROID_ID)
                request.Adid = pfSettings->AdvertisingIdValue;
            else
                makeAttrCall = false;
            if (makeAttrCall)
            {
                // TODO: This request might be getting memory collected before it's complete...
                FDelegateOnSuccessAttributeInstall onSuccess;
                FDelegateOnFailurePlayFabError onFailure;
                UPlayFabClientAPI* callObj = AttributeInstall(request, onSuccess, onFailure, mCustomData);
                callObj->Activate();
            }
        }
    }

    // Broadcast the result event
    OnPlayFabResponse.Broadcast(myResponse, mCustomData, myResponse.responseError.hasError);
    pfSettings->ModifyPendingCallCount(-1);
}

void UPlayFabClientAPI::Activate()
{
    IPlayFab* pfSettings = &(IPlayFab::Get());

    FString RequestUrl;
    RequestUrl = TEXT("https://") + pfSettings->getGameTitleId() + IPlayFab::PlayFabURL + PlayFabRequestURL;

    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL(RequestUrl);
    HttpRequest->SetVerb("POST");

    // Headers
    if (useSessionTicket)
        HttpRequest->SetHeader("X-Authentication", pfSettings->getSessionTicket());
    if (useSecretKey)
        HttpRequest->SetHeader("X-SecretKey", pfSettings->getSecretApiKey());
    HttpRequest->SetHeader("Content-Type", "application/json");
    HttpRequest->SetHeader(TEXT("X-PlayFabSDK"), pfSettings->VersionString);
    HttpRequest->SetHeader("X-ReportErrorAsSuccess", "true"); // FHttpResponsePtr doesn't provide sufficient information when an error code is returned
    for (TMap<FString, FString>::TConstIterator It(RequestHeaders); It; ++It)
        HttpRequest->SetHeader(It.Key(), It.Value());

    // Serialize data to json string
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(RequestJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Set Json content
    HttpRequest->SetContentAsString(OutputString);

    UE_LOG(LogPlayFab, Log, TEXT("Request: %s"), *OutputString);

    // Bind event
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabClientAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabClientAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
    {
        ResponseJsonObj->Reset();
    }
    else
    {
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    }

    bIsValidJsonResponse = false;
}
