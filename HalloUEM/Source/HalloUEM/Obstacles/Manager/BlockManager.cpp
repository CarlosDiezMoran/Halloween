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

	for (ABlock* Block : CurrentSpawnedBlocks) 
	{
		FVector CurrentLocation = Block->GetActorLocation();
		CurrentLocation.X -= DeltaTime * BaseSpeed;
		Block->SetActorLocation(CurrentLocation);
	}
}

void ABlockManager::DestroyBlock(ABlock * BlockToDestroy)
{
	BlocksInScreen.RemoveSingle(BlockToDestroy);
	BlockToDestroy->Destroy();
}

void ABlockManager::AddBlock()
{
	int32 LenghtBlockList = CurrentBlockList.Num();
	int32 SelectedIndex = -1;

	while (SelectedIndex == -1)
	{
		float RandNumber = FMath::RandRange(0.f, (float)LenghtBlockList);
		SelectedIndex = RandNumber;
		//BlockList[CurrentLevel][SelectedIndex]
		CurrentBlockList[SelectedIndex];
	}

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

void ABlockManager::IncreaseLevel()
{
	BaseSpeed *= DifficultyMultiplier;
}

