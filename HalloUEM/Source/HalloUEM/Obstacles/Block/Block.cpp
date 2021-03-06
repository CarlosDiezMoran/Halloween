// Fill out your copyright notice in the Description page of Project Settings.

#include "Block.h"
#include "UtilsCommon.h"


// Sets default values
ABlock::ABlock() : Super()
{	
	Entrances = { false, false, false, false, false, false, false };
	Exits = { false, false, false, false, false, false, false };

	MyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
	MyRoot->SetVisibility(true);
	SetRootComponent(MyRoot);
}

void ABlock::OnConstruction(const FTransform & Transform)
{
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
}

