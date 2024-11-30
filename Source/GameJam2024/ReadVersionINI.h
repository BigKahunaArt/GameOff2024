// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadVersionINI.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM2024_API UReadVersionINI : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
		UFUNCTION(BlueprintCallable, Category = "SpyGame Utilities")
		static bool ReadBuildInfo(FString& OutBuildCommit);
};
