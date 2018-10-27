// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "UtilsCommon.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class HALLOUEM_API APlayerCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayerCharacter")
		EnumPowerUpType CurrentPowerUp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayerCharacter")
		EnumFuckUpType	CurrentFuckUpType;
	
};
