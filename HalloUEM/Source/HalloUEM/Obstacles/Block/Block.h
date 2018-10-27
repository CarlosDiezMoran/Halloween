// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

class UPiece;

UCLASS()
class HALLOUEM_API ABlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Block")
		TArray<bool> Entrances;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Block")
		TArray<bool> Exits;
	UPROPERTY(EditAnywhere, Instanced, Category = "Block")
		TArray<UPiece*> Pieces;
};
