// Fill out your copyright notice in the Description page of Project Settings.

#include "TetricController.h"
#include "Character/Manager/PlayerManager.h"
#include "Character/PlayerCharacter.h"
#include "UtilsCommon.h"

 

ATetricController::ATetricController() : Super()
{
}
void ATetricController::BeginPlayingState()
{
	Super::BeginPlayingState();
	PlayerManager = Cast<APlayerManager>(GetPawn());
	SetState(EnumState::STANDARD);
}

void ATetricController::Tick(float DeltaSeconds)
{
}

void ATetricController::SetState(EnumState State)
{
	this->InputComponent->ClearActionBindings();

	this->InputComponent->BindAction("DEBUG1", EInputEvent::IE_Released, this, &ATetricController::DebugFunction1);
	this->InputComponent->BindAction("DEBUG2", EInputEvent::IE_Released, this, &ATetricController::DebugFunction2);
	this->InputComponent->BindAction("DEBUG3", EInputEvent::IE_Released, this, &ATetricController::DebugFunction3);
	this->InputComponent->BindAction("DEBUG4", EInputEvent::IE_Released, this, &ATetricController::DebugFunction4);


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

APlayerManager* ATetricController::GetPlayerManager()
{
	if(PlayerManager->IsValidLowLevel())
	{
		return PlayerManager;
	}else
	{
		return nullptr;
	}
}

void ATetricController::DebugFunction1_Implementation()
{
	if (PlayerManager->IsValidLowLevel())
	{
		PlayerManager->Player1->StepBack();
	}
}

void ATetricController::DebugFunction2_Implementation()
{
	if (PlayerManager->IsValidLowLevel())
	{
		PlayerManager->Player1->StepForward();
	}
}


void ATetricController::DebugFunction3_Implementation()
{
}

void ATetricController::DebugFunction4_Implementation()
{
}


void ATetricController::P1_MoveRight()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->P1_MoveRight();
	}
}

void ATetricController::P1_MoveLeft()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->P1_MoveLeft();
	}
}

void ATetricController::P1_PowerUp()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->P1_PowerUp();
	}
}

void ATetricController::P1_FuckedUp()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->P1_FuckedUp();
	}
}

void ATetricController::P2_MoveRight()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->P2_MoveRight();
	}
}

void ATetricController::P2_MoveLeft()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->P2_MoveLeft();
	}
}

void ATetricController::P2_PowerUp()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->P2_PowerUp();
	}
}

void ATetricController::P2_FuckedUp()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->P2_FuckedUp();
	}
}


void ATetricController::MenuUp()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->MenuUp();
	}
}

void ATetricController::MenuDown()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->MenuDown();
	}
}

void ATetricController::MenuRight()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->MenuRight();
	}
}

void ATetricController::MenuLeft()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->MenuLeft();
	}
}

void ATetricController::MenuSelect()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->MenuSelect();
	}
}

void ATetricController::MenuCancel()
{
	if(PlayerManager->IsValidLowLevel())
	{
		PlayerManager->MenuCancel();
	}
}

void ATetricController::PauseGame()
{
	if(PlayerManager->IsValidLowLevel())
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
	/*
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
	*/
}
