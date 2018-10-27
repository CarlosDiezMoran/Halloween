// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "AbilityProp.generated.h"

enum class EnumPowerUpType;
enum class EnumFuckUpType;


UCLASS()
class HALLOUEM_API AAbilityProp : public APaperSpriteActor
{
	GENERATED_BODY()
	
public:
	AAbilityProp();

protected:
	virtual void BeginPlay() override;

public:

	EnumPowerUpType PowerUpType;
	EnumFuckUpType	EnumFuckUpType;
	
};
