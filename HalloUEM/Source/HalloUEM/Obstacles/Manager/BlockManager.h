// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blocks")
		TArray<ABlock*> AllBlocks;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		int32 CurrentLevel = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blocks")
		int32 BaseSpeed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blocks")
		int32 DistanceBetweenBlocks = 0;
private:
	UPROPERTY(VisibleAnywhere)
		TArray<ABlock*> BlocksInScreen;
	UPROPERTY(VisibleAnywhere)
		int8 LevelModifier;
	
};