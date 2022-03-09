// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SHealthComponent.generated.h"

// This declare statement creates a custom event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnHealthChangedSignature, USHealthComponent*, HealthComp, float, Health, float, HealthDelta, const class UDamageType*, DamageType, class AController*, InstigatedBy, AActor*, DamageCauser);


UCLASS( ClassGroup=(COOP), meta=(BlueprintSpawnableComponent) )
class COOPSHOOTER_API USHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = HealthComponent)
	float Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthComponent)
	float DefaultHealth;

	UFUNCTION()
	void HandleTakeAnyDamage(AActor* DamagedActor, float DamageEventHeader, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

public:
	// Expose the custom event in blueprints
	UPROPERTY(BlueprintAssignable, Category = Events)
	FOnHealthChangedSignature OnHealthChanged;
};
