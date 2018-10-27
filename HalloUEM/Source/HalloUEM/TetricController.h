// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UtilsCommon.h"
#include "TetricController.generated.h"

class APlayerManager;
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

private:
	//Set States
	void SetNoneState();
	void SetStandardState();
	void SetMenuState();

	//Binding functions
	void P1_MoveRight();
	void P1_MoveLeft();
	void P1_PowerUp();
	void P1_FuckedUp();
	void P2_MoveRight();
	void P2_MoveLeft();
	void P2_PowerUp();
	void P2_FuckedUp();
	void MenuUp();
	void MenuDown();
	void MenuRight();
	void MenuLeft();
	void MenuSelect();
	void MenuCancel();
	void PauseGame();
private:
	EnumState CurrentState;
	APlayerManager* PlayerManager;

};
