// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UtilsCommon.h"
#include "Block.generated.h"

class APiece;

UCLASS()
class HALLOUEM_API ABlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock();
	virtual void OnConstruction(const FTransform& Transform) override;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Block")
		void InitBlock(int32 index, EnumPieceType Type);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Block")
		TArray<bool> Entrances;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Block")
		TArray<bool> Exits;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Block")
		//TArray<TSubclassOf<APiece>> PiecesTypes;
		TMap<EnumPieceType, TSubclassOf<APiece>> PiecesTypeMap;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Block")
		TArray<FTransform> PiecesTransform;
	/*
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Block")
		TArray<TSubclassOf<UPiece>> PiecesTypes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		TArray<UPiece*> SpawnedPieces;
		*/
};
