// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadVersionINI.h"

UFUNCTION(BlueprintCallable, Category = "SpyGame Utilities")
bool UReadVersionINI::ReadBuildInfo(FString& OutBuildCommit)
{
    // Path to the custom BuildInfo.ini file
    FString BuildInfoPath = FPaths::Combine(FPaths::ProjectConfigDir(), TEXT("DefaultBuild.ini"));

    // Ensure GConfig is valid and the file exists
    if (!GConfig || !FPaths::FileExists(BuildInfoPath))
    {
        OutBuildCommit = TEXT("");
        return false; // File not found or GConfig invalid
    }

    FString BuildNumber;
    FString CommitHash;

    // Attempt to retrieve BuildNumber and LastCommitHash
    if (GConfig->GetString(TEXT("BuildInfo"), TEXT("BuildNumber"), BuildNumber, BuildInfoPath) &&
        GConfig->GetString(TEXT("BuildInfo"), TEXT("LastCommitHash"), CommitHash, BuildInfoPath))
    {
        // Combine BuildNumber and CommitHash in the desired format
        OutBuildCommit = FString::Printf(TEXT("%s_%s"), *BuildNumber, *CommitHash);
        return true; // Successfully retrieved and combined the values
    }

    // If retrieval failed, clear the output and return false
    OutBuildCommit = TEXT("");
    return false;
}