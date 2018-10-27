// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockManager.h"
#include "UtilsCommon.h"
#include "Obstacles/Block/Block.h"


// Sets default values
ABlockManager::ABlockManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlockManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlockManager::DestroyBlock(ABlock * BlockToDestroy)
{
	BlocksInScreen.RemoveSingle(BlockToDestroy);
	BlockToDestroy->Destroy();
}

void ABlockManager::AddBlock()
{
	//while has not been added

	//Select Random Block

	//if distance == 0

	//Check if entrace == exit

	//add it
 }

void ABlockManager::UpdateSpeed(bool bIsIncreasing, float TimeToReturnToPreviousSpeed)
{
	//if is increasing
	//++levelmodifier
	//else
	//--
	//set new speed
	//set timer if time != 0
}

