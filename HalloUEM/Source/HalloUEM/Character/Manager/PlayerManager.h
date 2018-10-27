// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerManager.generated.h"

class APlayerCharacter;
UCLASS()
class HALLOUEM_API APlayerManager : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerManager();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/*// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	*/
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
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void MenuUp();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void MenuDown();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void MenuRight();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void MenuLeft();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void MenuSelect();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void MenuCancel();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tetric Function")
	void PauseGame();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Manager")
		APlayerCharacter * Player1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Manager")
		APlayerCharacter * Player2;
	
};
