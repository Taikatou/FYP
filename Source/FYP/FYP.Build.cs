// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class FYP : ModuleRules
{
	public FYP(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { "GoogleAnalytics" });

        // Uncomment if you are using online features
        PrivateDependencyModuleNames.Add("OnlineSubsystem");
    }
}
