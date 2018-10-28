// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FLevelBlockManager.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "BlockManager.generated.h"

class ABlock;

UCLASS()
class HALLOUEM_API ABlockManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockManager();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Removes Block from BlocksInScreen and deletes it;
	UFUNCTION(BlueprintCallable)
	void DestroyBlock(ABlock* BlockToDestroy);
	//Adds a valid block to BlocksInScreen
	UFUNCTION(BlueprintCallable)
	void AddBlock();
	//Updates the Speed
	UFUNCTION(BlueprintCallable)
	void UpdateSpeed(bool bIsIncreasing, float TimeToReturnToPreviousSpeed = 0.f);
	UFUNCTION(BlueprintCallable)
		void IncreaseLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blocks")
		TArray<ABlock*> AllBlocks;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		int32 CurrentLevel = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blocks")
		int32 BaseSpeed = -50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		int32 DistanceBetweenBlocks = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		TArray<ABlock*> CurrentSpawnedBlocks;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		TArray<TSubclassOf<ABlock>> CurrentBlockList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		TArray<TSubclassOf<ABlock>> BlockList_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		TArray<TSubclassOf<ABlock>> BlockList_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		TArray<TSubclassOf<ABlock>> BlockList_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		TArray<TSubclassOf<ABlock>> BlockList_3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		TArray<TSubclassOf<ABlock>> BlockList_4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		int32 DifficultyMultiplier = 2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		int32 NumberOfBlocksToPowerUp = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		AActor* SpawningLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		float TimeToSpawnBlock = 3.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		float TimeToChangeLevel = 300.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		int32 MaxLevel = 4;

private:
	UPROPERTY(VisibleAnywhere)
		TArray<ABlock*> BlocksInScreen;
	UPROPERTY(VisibleAnywhere)
		int8 LevelModifier;
	UPROPERTY(VisibleAnywhere)
		int32 CurrentNumberOfBlocks = 0;
		FTimerHandle TimerHandle;
		FTimerDelegate TimerDel;
		FTimerHandle TimerHandleLevel;
		FTimerDelegate TimerDelLevel;
};
