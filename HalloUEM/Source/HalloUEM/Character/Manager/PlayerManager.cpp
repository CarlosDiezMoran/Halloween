// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerManager.h"
#include "Character/PlayerCharacter.h"

#define P1_VALID  if(Player1->IsValidLowLevel())
#define P2_VALID  if(Player2->IsValidLowLevel())
#define P12_VALID if(Player1->IsValidLowLevel() && Player2->IsValidLowLevel())

// Sets default values
APlayerManager::APlayerManager()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerManager::P1_MoveRight()
{
	P1_VALID
	{
		Player1->MoveRight();
	}
}

void APlayerManager::P1_MoveLeft()
{
	P1_VALID
	{
		Player1->MoveLeft();
	}
}

void APlayerManager::P1_PowerUp()
{
	P1_VALID
	{
		Player1->PowerUp();
	}
}

void APlayerManager::P1_FuckedUp()
{
	P1_VALID
	{
		Player1->FuckedUp();
	}
}

void APlayerManager::P2_MoveRight()
{
	P2_VALID
	{
		Player2->MoveRight();
	}
}

void APlayerManager::P2_MoveLeft()
{
	P2_VALID
	{
		Player2->MoveLeft();
	}
}

void APlayerManager::P2_PowerUp()
{
	P2_VALID
	{
		Player2->PowerUp();
	}
}

void APlayerManager::P2_FuckedUp()
{
	P2_VALID
	{
		Player2->FuckedUp();
	}
}


void APlayerManager::MenuUp_Implementation()
{
}

void APlayerManager::MenuDown_Implementation()
{
}

void APlayerManager::MenuRight_Implementation()
{
}

void APlayerManager::MenuLeft_Implementation()
{
}

void APlayerManager::MenuSelect_Implementation()
{
}

void APlayerManager::MenuCancel_Implementation()
{
}

void APlayerManager::PauseGame_Implementation()
{
}



