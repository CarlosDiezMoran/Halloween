// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockManager.h"
#include "UtilsCommon.h"
#include "Obstacles/Block/Block.h"
#include "Abilities/AbilityProp.h"
#include "Background/Background.h"
#include "Runtime/Engine/Classes/Engine/World.h"


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

	//Le meto los blocks de level 0 al inicio
	CurrentBlockList.Append(BlockList_0);

	//Timer Generacion Bloques
	TimerDel.BindUFunction(this, FName("AddBlock"));
	GetWorldTimerManager().SetTimer(TimerHandle, TimerDel, TimeToSpawnBlock, true);


	//Timer Control Nivel
	TimerDelLevel.BindUFunction(this, FName("IncreaseLevel"));
	GetWorldTimerManager().SetTimer(TimerHandleLevel, TimerDelLevel, TimeToChangeLevel, true);
	
	FActorSpawnParameters SpawnInfo;
38		SpawnInfo.Owner = this;
39		FVector Location(SpawningLocation->GetActorLocation() - FVector::RightVector*50.f);
40		FRotator Rotation(0.0f, 90.0f, -90.0f);
41	
42		ABackground* NewBackground1 = GetWorld()->SpawnActor<ABackground>(BackgroundBlocks[0], Location, Rotation, SpawnInfo);
43		SpawnedBackgroundBlocks.Add(NewBackground1);
44	
45		FActorSpawnParameters SpawnInfo2;
46		SpawnInfo.Owner = this;
47		FVector Location2(SpawningLocation->GetActorLocation() - FVector::RightVector*50.f);
48		FRotator Rotation2(0.0f, 90.0f, -90.0f);
49		ABackground* NewBackground2 = GetWorld()->SpawnActor<ABackground>(BackgroundBlocks[1], Location2, Rotation2, SpawnInfo2);
50		FVector NewLoc = SpawningLocation->GetActorLocation();
51		NewLoc.X += 200 * 12;
52		NewLoc.Y = NewBackground2->GetActorLocation().Y;
53		NewBackground2->SetActorLocation(NewLoc);
54		SpawnedBackgroundBlocks.Add(NewBackground2);
55	
56		FActorSpawnParameters SpawnInfo3;
57		SpawnInfo.Owner = this;
58		FVector Location3(SpawningLocation->GetActorLocation() - FVector::RightVector*50.f);
59		FRotator Rotation3(0.0f, 90.0f, -90.0f);
60		ABackground* NewBackground3 = GetWorld()->SpawnActor<ABackground>(BackgroundBlocks[2], Location3, Rotation3, SpawnInfo3);
61		FVector NewLoc2 = SpawningLocation->GetActorLocation();
62		NewLoc2.X += 200 * 24;
63		NewLoc2.Y = NewBackground3->GetActorLocation().Y;
64		NewBackground3->SetActorLocation(NewLoc2);
65		SpawnedBackgroundBlocks.Add(NewBackground3);
}

// Called every frame
void ABlockManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (ABlock* Block : CurrentSpawnedBlocks) 
	{
		FVector CurrentLocation = Block->GetActorLocation();
		CurrentLocation.X -= DeltaTime * BaseSpeed;
		Block->SetActorLocation(CurrentLocation,true);
	}
	int32 IndexToBeRemoved = -1;
	uint32 Counter = 0;
	for (AAbilityProp* AbilityProp : AbilityProps)
	{
		if (AbilityProp->IsValidLowLevel())
		{
			if(AbilityProp->bHasToBeRemoved)
			{
				IndexToBeRemoved = Counter;
			}
			else
			{
				Counter++;
				FVector CurrentLocation = AbilityProp->GetActorLocation();
				CurrentLocation.X -= DeltaTime * BaseSpeed;
				AbilityProp->SetActorLocation(CurrentLocation, true);
			}
		}
	}
	if(AbilityProps.IsValidIndex(IndexToBeRemoved))
	{
		AAbilityProp* Ability = AbilityProps[IndexToBeRemoved];
		AbilityProps.RemoveAt(IndexToBeRemoved);
		Ability->Destroy();
	}
	
	for (ABackground* Back : SpawnedBackgroundBlocks) 
	{
		FVector CurrentLocation = Back->GetActorLocation();
		CurrentLocation.X -= DeltaTime * BaseSpeed / 2;
		Back->SetActorLocation(CurrentLocation, true);
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
	int32 NumCurrentSpawnedBlocks = CurrentSpawnedBlocks.Num();
	int32 SelectedIndex = -1;

	while (SelectedIndex == -1)
	{
		bool CanSpawn = false;
		float RandNumber = FMath::RandRange(0.f, (float)LenghtBlockList);
		SelectedIndex = RandNumber;
		//BlockList[CurrentLevel][SelectedIndex]

		if (NumCurrentSpawnedBlocks > 0) 
		{
			float Dist = CurrentSpawnedBlocks[CurrentSpawnedBlocks.Num() - 1]->GetDistanceTo(SpawningLocation);
			
			//Si la distancia es < 0 no hacemos spawn
			if (Dist < 500.f) 
			{
				SelectedIndex = -2;
			}
			else 
			{
				CanSpawn = true;
			}
		}
		else 
		{
			CanSpawn = true;
		}
		
		if (CanSpawn) 
		{

			FActorSpawnParameters SpawnInfo;
			SpawnInfo.Owner = this;
			if(SpawningLocation->IsValidLowLevel())
			{
				FVector Location(SpawningLocation->GetActorLocation() + FVector::RightVector*50.f);
				FRotator Rotation(0.0f, 90.0f, -90.0f);

				ABlock* NewBlock = GetWorld()->SpawnActor<ABlock>(CurrentBlockList[SelectedIndex], Location, Rotation, SpawnInfo);
				CurrentSpawnedBlocks.Add(NewBlock);

				++CurrentNumberOfBlocksWithoutPowerUp;
				if (CurrentNumberOfBlocksWithoutPowerUp > NumberOfBlocksToPowerUp)
				{
					CurrentNumberOfBlocksWithoutPowerUp = 0;
					TArray<FVector2D> PowerUpPositions;
					uint8 Counter = 0;
					if (FMath::RandBool())
					{
						for (bool Tile : NewBlock->Entrances)
						{
							if (Tile)
							{
								PowerUpPositions.Add(FVector2D(0.f, Counter*100));
							}
							Counter++;
						}
					}
					else
					{
						for (bool Tile : NewBlock->Exits)
						{
							if (Tile)
							{
								PowerUpPositions.Add(FVector2D(-400.f, Counter*100));
							}
							Counter++;
						}
					}

					SpawnPowerupProp(Location, PowerUpPositions[FMath::RandRange(0, PowerUpPositions.Num() - 1)]);
				}
			}
		}
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
	if (MaxLevel > CurrentLevel) 
	{
		BaseSpeed *= DifficultyMultiplier;
		TimeToSpawnBlock /= DifficultyMultiplier;
		CurrentLevel++;

		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		GetWorldTimerManager().SetTimer(TimerHandle, TimerDel, TimeToSpawnBlock, true);

		switch (CurrentLevel)
		{
		case 1:
			CurrentBlockList.Append(BlockList_1);
			break;
		case 2:
			CurrentBlockList.Append(BlockList_2);

			break;
		case 3:
			CurrentBlockList.Append(BlockList_3);
			break;
		case 4:
			CurrentBlockList.Append(BlockList_4);
			break;
		}
	}
}

