// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Public/TimerManager.h"


UENUM(BlueprintType)
enum class EnumState : uint8 {
	NONE,					//Disabled
	STANDARD,				//Standard movement
	MENU
};

UENUM(BlueprintType)
enum class EnumPowerUpType : uint8 {
	NONE,
	DASH,
	SLOW,
	SHOOT
};

enum class EnumFuckUpType : uint8 {
	NONE,
	SPEED,
	GHOST,
	BLIND
};

