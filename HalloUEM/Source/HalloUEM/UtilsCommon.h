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