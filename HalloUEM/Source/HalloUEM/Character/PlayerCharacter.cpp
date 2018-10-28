// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "PowerUpsComponent.h"
#include "Character/MovementPoints/PlayerMovementPoint.h"

#define GRIDDISTANCE 100

APlayerCharacter::APlayerCharacter() : Super()
{
	PowerUps = CreateDefaultSubobject<UPowerUpsComponent>(TEXT("PowerUps"));
	AddOwnedComponent(PowerUps);
}

void APlayerCharacter::Die_Implementation()
{

}

void APlayerCharacter::StepBack()
{
	if (!bIsInvulnerable) {
		for (APlayerMovementPoint* Positions : MovementPoints)
		{
			Positions->AddActorLocalOffset(FVector::ForwardVector*GRIDDISTANCE);
		}
		SetPlayerLocationByIndex(CurrentMovementPointIndex);
		MakeInvulnerable(true);
		--NumberOfLifes;
		if (NumberOfLifes < 0)
		{
			Die();
		}
	}
}

void APlayerCharacter::StepForward()
{
	MakeInvulnerable(false);
	if (NumberOfLifes < 3)
	{
		++NumberOfLifes;
		for (APlayerMovementPoint* Positions : MovementPoints)
		{
			Positions->AddActorLocalOffset(FVector::ForwardVector*-GRIDDISTANCE);
		}
		SetPlayerLocationByIndex(CurrentMovementPointIndex);

	}
}

/*void APlayerCharacter::MakeInvulnerable_Implementation()
{
}*/

void APlayerCharacter::AddPowerUps(EnumPowerUpType NewPowerUp, EnumFuckUpType NewFuckUp)
{
	PowerUps->CurrentPowerUp = NewPowerUp;
	PowerUps->CurrentFuckerUp = NewFuckUp;
	CreatePowerUpWidget();
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	Init();
	MovementPointsSize = MovementPoints.Num();
	CurrentMovementPointIndex = 3;
	SetPlayerLocationByIndex(CurrentMovementPointIndex);
}

void APlayerCharacter::SetPlayerLocationByIndex(int32 Index)
{
	if (MovementPoints.IsValidIndex(Index))
	{
		SetActorLocation(MovementPoints[Index]->GetActorLocation());
	}
}

void APlayerCharacter::Init_Implementation()
{

}
void APlayerCharacter::MoveLeft_Implementation() 
{
	if(CurrentMovementPointIndex > 0)
	{
		--CurrentMovementPointIndex;
		SetPlayerLocationByIndex(CurrentMovementPointIndex);
	}
}
void APlayerCharacter::MoveRight_Implementation()
{
	if (CurrentMovementPointIndex < MovementPointsSize - 1)
	{
		++CurrentMovementPointIndex;
		SetPlayerLocationByIndex(CurrentMovementPointIndex);
	}
}
void APlayerCharacter::PowerUp()
{
	PowerUps->UsePowerUp();
}
void APlayerCharacter::FuckedUp()
{
	PowerUps->UseFuckedUp();
}

