// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UtilsCommon.h"

#include "PowerUpsComponent.generated.h"

class APlayerCharacter;
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HALLOUEM_API UPowerUpsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPowerUpsComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void UsePowerUp();
	UFUNCTION(BlueprintCallable)
	void UseFuckedUp();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void PlaySoundUsePowerUp();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void PlaySoundUseFuckedUp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PowerUp")
		EnumPowerUpType CurrentPowerUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PowerUp")
		EnumFuckUpType	CurrentFuckerUp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PowerUp")
		APlayerCharacter* PlayerCharacter;
};
