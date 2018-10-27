// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Piece.generated.h"

class UPaperSpriteComponent;

UCLASS()
class HALLOUEM_API APiece : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Piece")
		UPaperSpriteComponent* Sprite;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Piece")
		USceneComponent* MyRoot;
};
