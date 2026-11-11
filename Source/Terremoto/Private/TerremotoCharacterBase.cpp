// Fill out your copyright notice in the Description page of Project Settings.


#include "TerremotoCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "TerremotoAttributeSet.h"
#include "GameplayEffect.h"
#include "GameFramework/CharacterMovementComponent.h"

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

	if (!AbilitySystemComponent)
	{
		return;
	}

	const FGameplayAttribute SpeedAttribute = UTerremotoAttributeSet::GetMovementSpeedAttribute();

	// listen for changes to the movement speed attribute
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SpeedAttribute).AddUObject(this, &ATerremotoCharacterBase::OnMovementSpeedChanged);
	//sync the initial movement speed value
	const float InitialSpeed = AbilitySystemComponent->GetNumericAttribute(SpeedAttribute);

	if(InitialSpeed > 0.f)
	{
		GetCharacterMovement()->MaxWalkSpeed = InitialSpeed;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Initial movement speed is zero or negative."));
	}
}

void ATerremotoCharacterBase::OnMovementSpeedChanged(
	const FOnAttributeChangeData& Data)
{
	const float NewSpeed = Data.NewValue;

	GetCharacterMovement()->MaxWalkSpeed =
		FMath::Max(0.0f, NewSpeed); // Ensure speed is not negative
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

