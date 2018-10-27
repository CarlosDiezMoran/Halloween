// Fill out your copyright notice in the Description page of Project Settings.

#include "TetricController.h"
#include "UtilsCommon.h"

ATetricController::ATetricController() : Super()
{
}
void ATetricController::BeginPlayingState()
{
	Super::BeginPlayingState();
}

void ATetricController::Tick(float DeltaSeconds)
{
}

void ATetricController::SetState(EnumState State)
{
	switch(State)
	{
	case EnumState::NONE:
		SetNoneState();
		break;
	case EnumState::STANDARD:
		SetStandardState();
		break;
	case EnumState::MENU:
		SetMenuState();
		break;

	}
}

EnumState ATetricController::GetCurrentState()
{
	return CurrentState;
}

void ATetricController::P1_MoveRight()
{
}

void ATetricController::P1_MoveLeft()
{
}

void ATetricController::P1_PowerUp()
{
}

void ATetricController::P1_FuckedUp()
{
}

void ATetricController::P2_MoveRight()
{
}

void ATetricController::P2_MoveLeft()
{
}

void ATetricController::P2_PowerUp()
{
}

void ATetricController::P2_FuckedUp()
{
}

void ATetricController::Pause()
{
}

void ATetricController::MenuUp()
{
}

void ATetricController::MenuDown()
{
}

void ATetricController::MenuRight()
{
}

void ATetricController::MenuLeft()
{
}

void ATetricController::MenuSelect()
{
}

void ATetricController::MenuCancel()
{
}

void ATetricController::SetNoneState()
{
}

void ATetricController::SetStandardState()
{
}

void ATetricController::SetMenuState()
{
}
