// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SHealthComponent.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "SExplodingBarrel.generated.h"

UCLASS()
class COOPSHOOTER_API ASExplodingBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplodingBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Component Properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = Components)
	USHealthComponent* HealthComp;

	UPROPERTY(VisibleAnywhere, Category = Components)
	URadialForceComponent* RadialForceComp;

	// FX Properties
	UPROPERTY(EditDefaultsOnly, Category = FX)
	float ExplosionImpulse;

	UPROPERTY(EditDefaultsOnly, Category = FX)
	UParticleSystem* ExplosionEffect;

	UPROPERTY(EditDefaultsOnly, Category = FX)
	UMaterialInterface* ExplodedMaterial;

	bool bExploded;

	// Functions and Events
	UFUNCTION()
	void OnHealthChanged(USHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType,
		class AController* InstigatedBy, AActor* DamageCauser);
};
