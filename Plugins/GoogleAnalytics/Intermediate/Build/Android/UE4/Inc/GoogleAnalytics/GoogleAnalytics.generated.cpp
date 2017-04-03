// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "Private/GoogleAnalyticsPrivatePCH.h"
#include "GeneratedCppIncludes.h"
#include "GoogleAnalytics.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1GoogleAnalytics() {}
	void UGoogleAnalyticsBlueprintLibrary::StaticRegisterNativesUGoogleAnalyticsBlueprintLibrary()
	{
		FNativeFunctionRegistrar::RegisterFunction(UGoogleAnalyticsBlueprintLibrary::StaticClass(), "GetTrackingId",(Native)&UGoogleAnalyticsBlueprintLibrary::execGetTrackingId);
		FNativeFunctionRegistrar::RegisterFunction(UGoogleAnalyticsBlueprintLibrary::StaticClass(), "RecordGoogleEvent",(Native)&UGoogleAnalyticsBlueprintLibrary::execRecordGoogleEvent);
		FNativeFunctionRegistrar::RegisterFunction(UGoogleAnalyticsBlueprintLibrary::StaticClass(), "RecordGoogleScreen",(Native)&UGoogleAnalyticsBlueprintLibrary::execRecordGoogleScreen);
		FNativeFunctionRegistrar::RegisterFunction(UGoogleAnalyticsBlueprintLibrary::StaticClass(), "RecordGoogleSocialInteraction",(Native)&UGoogleAnalyticsBlueprintLibrary::execRecordGoogleSocialInteraction);
		FNativeFunctionRegistrar::RegisterFunction(UGoogleAnalyticsBlueprintLibrary::StaticClass(), "RecordGoogleUserTiming",(Native)&UGoogleAnalyticsBlueprintLibrary::execRecordGoogleUserTiming);
		FNativeFunctionRegistrar::RegisterFunction(UGoogleAnalyticsBlueprintLibrary::StaticClass(), "SetTrackingId",(Native)&UGoogleAnalyticsBlueprintLibrary::execSetTrackingId);
	}
	IMPLEMENT_CLASS(UGoogleAnalyticsBlueprintLibrary, 1692109240);
	void UGoogleAnalyticsSettings::StaticRegisterNativesUGoogleAnalyticsSettings()
	{
	}
	IMPLEMENT_CLASS(UGoogleAnalyticsSettings, 1744584816);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	COREUOBJECT_API class UClass* Z_Construct_UClass_UObject();

	GOOGLEANALYTICS_API class UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_GetTrackingId();
	GOOGLEANALYTICS_API class UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleEvent();
	GOOGLEANALYTICS_API class UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleScreen();
	GOOGLEANALYTICS_API class UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleSocialInteraction();
	GOOGLEANALYTICS_API class UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleUserTiming();
	GOOGLEANALYTICS_API class UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_SetTrackingId();
	GOOGLEANALYTICS_API class UClass* Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary_NoRegister();
	GOOGLEANALYTICS_API class UClass* Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary();
	GOOGLEANALYTICS_API class UClass* Z_Construct_UClass_UGoogleAnalyticsSettings_NoRegister();
	GOOGLEANALYTICS_API class UClass* Z_Construct_UClass_UGoogleAnalyticsSettings();
	GOOGLEANALYTICS_API class UPackage* Z_Construct_UPackage__Script_GoogleAnalytics();
	UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_GetTrackingId()
	{
		struct GoogleAnalyticsBlueprintLibrary_eventGetTrackingId_Parms
		{
			FString ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetTrackingId"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(GoogleAnalyticsBlueprintLibrary_eventGetTrackingId_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(ReturnValue, GoogleAnalyticsBlueprintLibrary_eventGetTrackingId_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Analytics"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Classes/GoogleAnalyticsBlueprintLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Get current Tracking Id (only for Google Analytics)"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleEvent()
	{
		struct GoogleAnalyticsBlueprintLibrary_eventRecordGoogleEvent_Parms
		{
			FString EventCategory;
			FString EventAction;
			FString EventLabel;
			int32 EventValue;
		};
		UObject* Outer=Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RecordGoogleEvent"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(GoogleAnalyticsBlueprintLibrary_eventRecordGoogleEvent_Parms));
			UProperty* NewProp_EventValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("EventValue"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(EventValue, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleEvent_Parms), 0x0010000000000082);
			UProperty* NewProp_EventLabel = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("EventLabel"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(EventLabel, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleEvent_Parms), 0x0010000000000080);
			UProperty* NewProp_EventAction = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("EventAction"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(EventAction, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleEvent_Parms), 0x0010000000000080);
			UProperty* NewProp_EventCategory = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("EventCategory"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(EventCategory, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleEvent_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Analytics"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Classes/GoogleAnalyticsBlueprintLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Records an event with all attributes (only for Google Analytics)"));
			MetaData->SetValue(NewProp_EventValue, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_EventLabel, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_EventAction, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_EventCategory, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleScreen()
	{
		struct GoogleAnalyticsBlueprintLibrary_eventRecordGoogleScreen_Parms
		{
			FString ScreenName;
		};
		UObject* Outer=Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RecordGoogleScreen"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(GoogleAnalyticsBlueprintLibrary_eventRecordGoogleScreen_Parms));
			UProperty* NewProp_ScreenName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ScreenName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(ScreenName, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleScreen_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Analytics"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Classes/GoogleAnalyticsBlueprintLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Records a screen (only for Google Analytics)"));
			MetaData->SetValue(NewProp_ScreenName, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleSocialInteraction()
	{
		struct GoogleAnalyticsBlueprintLibrary_eventRecordGoogleSocialInteraction_Parms
		{
			FString SocialNetwork;
			FString SocialAction;
			FString SocialTarget;
		};
		UObject* Outer=Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RecordGoogleSocialInteraction"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(GoogleAnalyticsBlueprintLibrary_eventRecordGoogleSocialInteraction_Parms));
			UProperty* NewProp_SocialTarget = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SocialTarget"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(SocialTarget, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleSocialInteraction_Parms), 0x0010000000000080);
			UProperty* NewProp_SocialAction = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SocialAction"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(SocialAction, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleSocialInteraction_Parms), 0x0010000000000080);
			UProperty* NewProp_SocialNetwork = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SocialNetwork"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(SocialNetwork, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleSocialInteraction_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Analytics"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Classes/GoogleAnalyticsBlueprintLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Records a social interaction (only for Google Analytics)"));
			MetaData->SetValue(NewProp_SocialTarget, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_SocialAction, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_SocialNetwork, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleUserTiming()
	{
		struct GoogleAnalyticsBlueprintLibrary_eventRecordGoogleUserTiming_Parms
		{
			FString TimingCategory;
			int32 TimingValue;
			FString TimingName;
		};
		UObject* Outer=Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RecordGoogleUserTiming"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(GoogleAnalyticsBlueprintLibrary_eventRecordGoogleUserTiming_Parms));
			UProperty* NewProp_TimingName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("TimingName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(TimingName, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleUserTiming_Parms), 0x0010000000000080);
			UProperty* NewProp_TimingValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("TimingValue"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(TimingValue, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleUserTiming_Parms), 0x0010000000000082);
			UProperty* NewProp_TimingCategory = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("TimingCategory"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(TimingCategory, GoogleAnalyticsBlueprintLibrary_eventRecordGoogleUserTiming_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Analytics"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Classes/GoogleAnalyticsBlueprintLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Records an user timing (only for Google Analytics)"));
			MetaData->SetValue(NewProp_TimingName, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_TimingValue, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_TimingCategory, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_SetTrackingId()
	{
		struct GoogleAnalyticsBlueprintLibrary_eventSetTrackingId_Parms
		{
			FString TrackingId;
		};
		UObject* Outer=Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetTrackingId"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(GoogleAnalyticsBlueprintLibrary_eventSetTrackingId_Parms));
			UProperty* NewProp_TrackingId = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("TrackingId"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(TrackingId, GoogleAnalyticsBlueprintLibrary_eventSetTrackingId_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Analytics"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Classes/GoogleAnalyticsBlueprintLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Set new Tracking Id (only for Google Analytics)"));
			MetaData->SetValue(NewProp_TrackingId, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary_NoRegister()
	{
		return UGoogleAnalyticsBlueprintLibrary::StaticClass();
	}
	UClass* Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UBlueprintFunctionLibrary();
			Z_Construct_UPackage__Script_GoogleAnalytics();
			OuterClass = UGoogleAnalyticsBlueprintLibrary::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20100080;

				OuterClass->LinkChild(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_GetTrackingId());
				OuterClass->LinkChild(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleEvent());
				OuterClass->LinkChild(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleScreen());
				OuterClass->LinkChild(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleSocialInteraction());
				OuterClass->LinkChild(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleUserTiming());
				OuterClass->LinkChild(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_SetTrackingId());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_GetTrackingId(), "GetTrackingId"); // 916901909
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleEvent(), "RecordGoogleEvent"); // 2463811317
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleScreen(), "RecordGoogleScreen"); // 1602742393
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleSocialInteraction(), "RecordGoogleSocialInteraction"); // 485340234
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_RecordGoogleUserTiming(), "RecordGoogleUserTiming"); // 321095527
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UGoogleAnalyticsBlueprintLibrary_SetTrackingId(), "SetTrackingId"); // 3968328362
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("GoogleAnalyticsBlueprintLibrary.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Classes/GoogleAnalyticsBlueprintLibrary.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGoogleAnalyticsBlueprintLibrary(Z_Construct_UClass_UGoogleAnalyticsBlueprintLibrary, &UGoogleAnalyticsBlueprintLibrary::StaticClass, TEXT("UGoogleAnalyticsBlueprintLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGoogleAnalyticsBlueprintLibrary);
	UClass* Z_Construct_UClass_UGoogleAnalyticsSettings_NoRegister()
	{
		return UGoogleAnalyticsSettings::StaticClass();
	}
	UClass* Z_Construct_UClass_UGoogleAnalyticsSettings()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_GoogleAnalytics();
			OuterClass = UGoogleAnalyticsSettings::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000082;


				OuterClass->ClassConfigName = FName(TEXT("Engine"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("GoogleAnalyticsSettings.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Classes/GoogleAnalyticsSettings.h"));
				MetaData->SetValue(OuterClass, TEXT("ObjectInitializerConstructorDeclared"), TEXT(""));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGoogleAnalyticsSettings(Z_Construct_UClass_UGoogleAnalyticsSettings, &UGoogleAnalyticsSettings::StaticClass, TEXT("UGoogleAnalyticsSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGoogleAnalyticsSettings);
	UPackage* Z_Construct_UPackage__Script_GoogleAnalytics()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/GoogleAnalytics")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x924ED1D6;
			Guid.B = 0xC9271723;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
