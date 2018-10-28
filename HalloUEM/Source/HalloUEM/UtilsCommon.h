// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"


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
	SLOW
};

UENUM(BlueprintType)
enum class EnumFuckUpType : uint8 {
	NONE,
	SPEED,
	BLIND
};

UENUM(BlueprintType)
enum class EnumPieceType : uint8 {
	NONE,
	BLOCK,
	T,
	S,
	STICK,
	L
};
