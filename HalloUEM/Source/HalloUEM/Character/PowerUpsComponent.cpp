// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerUpsComponent.h"
#include "PlayerCharacter.h"

// Sets default values for this component's properties
UPowerUpsComponent::UPowerUpsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPowerUpsComponent::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharacter = Cast<APlayerCharacter>(GetOwner());
	// ...
	
}


// Called every frame
void UPowerUpsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


