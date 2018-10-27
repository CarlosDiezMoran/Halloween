// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Piece.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HALLOUEM_API UPiece : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPiece();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;	
	
};
