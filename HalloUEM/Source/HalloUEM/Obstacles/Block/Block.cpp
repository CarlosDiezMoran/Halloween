// Fill out your copyright notice in the Description page of Project Settings.

#include "Block.h"


// Sets default values
ABlock::ABlock() : Super()
{	
	Entrances = { false, false, false, false, false, false, false };
	Exits = { false, false, false, false, false, false, false };
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
}

