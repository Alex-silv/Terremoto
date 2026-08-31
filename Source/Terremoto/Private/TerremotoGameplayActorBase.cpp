// Fill out your copyright notice in the Description page of Project Settings.


#include "TerremotoGameplayActorBase.h"

// Sets default values
ATerremotoGameplayActorBase::ATerremotoGameplayActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

UAbilitySystemComponent* ATerremotoGameplayActorBase::GetAbilitySystemComponent() const
{
	return nullptr;
}

// Called when the game starts or when spawned
void ATerremotoGameplayActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATerremotoGameplayActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

