// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "UtilsCommon.h"
#include "PlayerCharacter.generated.h"

class APlayerMovementPoint;

UCLASS()
class HALLOUEM_API APlayerCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	APlayerCharacter();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
		void Init();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void MoveLeft();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void MoveRight();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void PowerUp();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void FuckedUp();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
		void Die();
	UFUNCTION(BlueprintCallable, Category = "Damaged")
		void StepBack();
	UFUNCTION(BlueprintCallable, Category = "Damaged")
		void StepForward();



protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	//Checks if the array is valid and moves the player
	void SetPlayerLocationByIndex(int32 Index);
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PowerUp")
		EnumPowerUpType CurrentPowerUp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PowerUp")
		EnumFuckUpType	CurrentFuckUpType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		TArray<APlayerMovementPoint*> MovementPoints;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
		int32 CurrentMovementPointIndex;
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
		int32 MovementPointsSize;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
		int32 NumberOfLifes = 3;
};
