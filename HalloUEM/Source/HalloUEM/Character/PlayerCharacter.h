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
	



protected:
	virtual void BeginPlay() override;
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayerCharacter")
		EnumPowerUpType CurrentPowerUp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayerCharacter")
		EnumFuckUpType	CurrentFuckUpType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerCharacter")
		TArray<APlayerMovementPoint*> MovementPoints;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayerCharacter")
		int32 CurrentMovementPointIndex;
};
