// Fill out your copyright notice in the Description page of Project Settings.

#include "Block.h"
#include "Obstacles/Piece/Piece.h"


// Sets default values
ABlock::ABlock() : Super()
{	
	Entrances = { false, false, false, false, false, false, false };
	Exits = { false, false, false, false, false, false, false };
}

void ABlock::OnConstruction(const FTransform & Transform)
{
}

void ABlock::InitBlock_Implementation(int32 index, EnumPieceType Type)
{
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
}

