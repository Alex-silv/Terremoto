// Fill out your copyright notice in the Description page of Project Settings.


#include "TerremotoGameplayActorBase.h"
#include "AbilitySystemComponent.h"
#include "TerremotoAttributeSet.h"
#include "GameplayEffect.h"

// Sets default values
ATerremotoGameplayActorBase::ATerremotoGameplayActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	AttributeSet = CreateDefaultSubobject<UTerremotoAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* ATerremotoGameplayActorBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ATerremotoGameplayActorBase::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		// Initialize the ability system component
		AbilitySystemComponent->InitAbilityActorInfo(this, this);

		if (InitialAttributeEffect)
		{
			FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
			FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(InitialAttributeEffect, 1, EffectContext);
			if (SpecHandle.IsValid())
			{
				AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
			}
		}
	}
	
}

// Called every frame
void ATerremotoGameplayActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

