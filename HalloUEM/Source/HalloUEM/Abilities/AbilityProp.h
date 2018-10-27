// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "UtilsCommon.h"
#include "AbilityProp.generated.h"


UCLASS()
class HALLOUEM_API AAbilityProp : public APaperSpriteActor
{
	GENERATED_BODY()
	
public:
	AAbilityProp();

protected:
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AbilityProp")
		EnumPowerUpType PowerUpType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AbilityProp")
		EnumFuckUpType	EnumFuckUpType;
	
};
