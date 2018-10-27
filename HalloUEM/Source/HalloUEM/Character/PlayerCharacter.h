// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class HALLOUEM_API APlayerCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void MoveLeft();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void MoveRight();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void PowerUp();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void FuckedUp();
	
	
};
