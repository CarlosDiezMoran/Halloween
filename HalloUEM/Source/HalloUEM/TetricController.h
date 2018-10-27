// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UtilsCommon.h"

#include "TetricController.generated.h"


/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HALLOUEM_API ATetricController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATetricController();
	// Called when the game starts
	virtual void BeginPlayingState() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
		void SetState(EnumState State);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		EnumState GetCurrentState();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void P1_MoveRight();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void P1_MoveLeft();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void P1_PowerUp();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void P1_FuckedUp();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void P2_MoveRight();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void P2_MoveLeft();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void P2_PowerUp();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void P2_FuckedUp();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void Pause();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void MenuUp();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void MenuDown();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void MenuRight();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void MenuLeft();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void MenuSelect();
	UFUNCTION(BlueprintCallable, Category = "Tetric Function")
		void MenuCancel();
private:
	void SetNoneState();
	void SetStandardState();
	void SetMenuState();

private:
	EnumState CurrentState;

};
