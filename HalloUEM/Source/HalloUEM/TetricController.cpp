// Fill out your copyright notice in the Description page of Project Settings.

#include "TetricController.h"
#include "Character/Manager/PlayerManager.h"
#include "UtilsCommon.h"

#define MANAGERVALID if(PlayerManager->IsValidLowLevel())

ATetricController::ATetricController() : Super()
{
}
void ATetricController::BeginPlayingState()
{
	Super::BeginPlayingState();
	SetStandardState();
}

void ATetricController::Tick(float DeltaSeconds)
{
}

void ATetricController::SetState(EnumState State)
{
	this->InputComponent->ClearActionBindings();
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
	//MANAGERVALID
	{
		PlayerManager->P1_MoveRight();
	}
}

void ATetricController::P1_MoveLeft()
{
	//MANAGERVALID
	{
		PlayerManager->P1_MoveLeft();
	}
}

void ATetricController::P1_PowerUp()
{
	//MANAGERVALID
	{
		PlayerManager->P1_PowerUp();
	}
}

void ATetricController::P1_FuckedUp()
{
	//MANAGERVALID
	{
		PlayerManager->P1_FuckedUp();
	}
}

void ATetricController::P2_MoveRight()
{
	//MANAGERVALID
	{
		PlayerManager->P2_MoveRight();
	}
}

void ATetricController::P2_MoveLeft()
{
	//MANAGERVALID
	{
		PlayerManager->P2_MoveLeft();
	}
}

void ATetricController::P2_PowerUp()
{
	//MANAGERVALID
	{
		PlayerManager->P2_PowerUp();
	}
}

void ATetricController::P2_FuckedUp()
{
	//MANAGERVALID
	{
		PlayerManager->P2_FuckedUp();
	}
}


void ATetricController::MenuUp()
{
	//MANAGERVALID
	{
		PlayerManager->MenuUp();
	}
}

void ATetricController::MenuDown()
{
	//MANAGERVALID
	{
		PlayerManager->MenuDown();
	}
}

void ATetricController::MenuRight()
{
	//MANAGERVALID
	{
		PlayerManager->MenuRight();
	}
}

void ATetricController::MenuLeft()
{
	//MANAGERVALID
	{
		PlayerManager->MenuLeft();
	}
}

void ATetricController::MenuSelect()
{
	//MANAGERVALID
	{
		PlayerManager->MenuSelect();
	}
}

void ATetricController::MenuCancel()
{
	//MANAGERVALID
	{
		PlayerManager->MenuCancel();
	}
}

void ATetricController::PauseGame()
{
	//MANAGERVALID
	{
		PlayerManager->PauseGame();
	}
}

void ATetricController::SetNoneState()
{

}

void ATetricController::SetStandardState()
{
	this->InputComponent->BindAction("P1_LEFT"		, EInputEvent::IE_Released, this, &ATetricController::P1_MoveLeft);
	this->InputComponent->BindAction("P1_RIGHT"		, EInputEvent::IE_Released, this, &ATetricController::P1_MoveRight);
	this->InputComponent->BindAction("P1_POWERUP"	, EInputEvent::IE_Released, this, &ATetricController::P1_PowerUp);
	this->InputComponent->BindAction("P1_FUCKERUP"	, EInputEvent::IE_Released, this, &ATetricController::P1_FuckedUp);

	this->InputComponent->BindAction("P2_LEFT"		, EInputEvent::IE_Released, this, &ATetricController::P2_MoveLeft);
	this->InputComponent->BindAction("P2_RIGHT"		, EInputEvent::IE_Released, this, &ATetricController::P2_MoveRight);
	this->InputComponent->BindAction("P2_POWERUP"	, EInputEvent::IE_Released, this, &ATetricController::P2_PowerUp);
	this->InputComponent->BindAction("P2_FUCKERUP"	, EInputEvent::IE_Released, this, &ATetricController::P2_FuckedUp);
	
	this->InputComponent->BindAction("PAUSE"		, EInputEvent::IE_Released, this, &ATetricController::PauseGame);

}

void ATetricController::SetMenuState()
{
	this->InputComponent->BindAction("P1_LEFT"		, EInputEvent::IE_Released, this, &ATetricController::MenuLeft);
	this->InputComponent->BindAction("P1_RIGHT"		, EInputEvent::IE_Released, this, &ATetricController::MenuRight);
	this->InputComponent->BindAction("P1_UP"		, EInputEvent::IE_Released, this, &ATetricController::MenuUp);
	this->InputComponent->BindAction("P1_DOWN"		, EInputEvent::IE_Released, this, &ATetricController::MenuDown);
	this->InputComponent->BindAction("P1_POWERUP"	, EInputEvent::IE_Released, this, &ATetricController::MenuSelect);
	this->InputComponent->BindAction("P1_FUCKERUP"	, EInputEvent::IE_Released, this, &ATetricController::MenuCancel);

	this->InputComponent->BindAction("P2_LEFT"		, EInputEvent::IE_Released, this, &ATetricController::MenuLeft);
	this->InputComponent->BindAction("P2_RIGHT"		, EInputEvent::IE_Released, this, &ATetricController::MenuRight);
	this->InputComponent->BindAction("P2_UP"		, EInputEvent::IE_Released, this, &ATetricController::MenuUp);
	this->InputComponent->BindAction("P2_DOWN"		, EInputEvent::IE_Released, this, &ATetricController::MenuDown);
	this->InputComponent->BindAction("P2_POWERUP"	, EInputEvent::IE_Released, this, &ATetricController::MenuSelect);
	this->InputComponent->BindAction("P2_FUCKERUP"	, EInputEvent::IE_Released, this, &ATetricController::MenuCancel);

	this->InputComponent->BindAction("ACCEPT"		, EInputEvent::IE_Released, this, &ATetricController::MenuSelect);
	this->InputComponent->BindAction("CANCEL"		, EInputEvent::IE_Released, this, &ATetricController::MenuCancel);
}
