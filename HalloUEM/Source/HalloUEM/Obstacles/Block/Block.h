// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UtilsCommon.h"
#include "Block.generated.h"

class USceneComponent;

UCLASS()
class HALLOUEM_API ABlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Block")
		TArray<bool> Entrances;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Block")
		TArray<bool> Exits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		USceneComponent* MyRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")		// De 0 a 4
		int32 Difficulty;
};
