// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FLevelBlockManager.generated.h"

class ABlock;

USTRUCT(BlueprintType)
struct HALLOUEM_API FLevelBlockManager
{
	GENERATED_USTRUCT_BODY()

public:
		UPROPERTY() TArray<TSubclassOf<ABlock>> Levels;

	FLevelBlockManager() { }
};

