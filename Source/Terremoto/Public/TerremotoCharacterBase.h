// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "TerremotoCharacterBase.generated.h"

class UAbilitySystemComponent;

UCLASS()
class TERREMOTO_API ATerremotoCharacterBase :
	public ACharacter,
	public IAbilitySystemInterface
	
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATerremotoCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
