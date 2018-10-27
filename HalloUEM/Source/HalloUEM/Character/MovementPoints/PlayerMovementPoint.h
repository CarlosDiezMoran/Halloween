// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "PlayerMovementPoint.generated.h"

/**
 * 
 */
UCLASS()
class HALLOUEM_API APlayerMovementPoint : public ATargetPoint
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Id = 0;
};
