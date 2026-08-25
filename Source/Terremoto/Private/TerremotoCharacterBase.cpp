// Fill out your copyright notice in the Description page of Project Settings.


#include "TerremotoCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "TerremotoAttributeSet.h"
#include "GameplayEffect.h"

// Sets default values
ATerremotoCharacterBase::ATerremotoCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UTerremotoAttributeSet>(TEXT("AttributeSet"));

}

UAbilitySystemComponent* ATerremotoCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ATerremotoCharacterBase::BeginPlay()
{
	

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);

		if (InitialAttributesEffect)
		{
			FGameplayEffectContextHandle EffectContext =
				AbilitySystemComponent->MakeEffectContext();

			FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
				InitialAttributesEffect,
				1,
				EffectContext
			);

			if (SpecHandle.IsValid())
			{
				AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(
					*SpecHandle.Data.Get()
				);

			}
		}
	}

	Super::BeginPlay();
}

// Called every frame
void ATerremotoCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATerremotoCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

