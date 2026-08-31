// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "TerremotoGameplayActorBase.generated.h"

class UAbilitySystemComponent;
class UTerremotoAttributeSet;
class UGameplayEffect;

UCLASS()
class TERREMOTO_API ATerremotoGameplayActorBase : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATerremotoGameplayActorBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	TObjectPtr<UTerremotoAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> InitialAttributeEffect;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
