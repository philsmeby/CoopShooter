// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplodingBarrel.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASExplodingBarrel::ASExplodingBarrel()
{
	// Add the Mesh Component
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetCollisionObjectType(ECC_PhysicsBody);
	MeshComp->SetMobility(EComponentMobility::Movable);
	RootComponent = MeshComp;

	// Add the Health Component
	HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("HealthComp"));
	HealthComp->OnHealthChanged.AddDynamic(this, &ASExplodingBarrel::OnHealthChanged);

	// Add Radial Force Component
	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComp"));
	RadialForceComp->SetupAttachment(MeshComp);
	RadialForceComp->Radius = 250;
	RadialForceComp->bImpulseVelChange = true;
	RadialForceComp->bAutoActivate = false; // This prevents the component from ticking
	RadialForceComp->bIgnoreOwningActor = true;

	ExplosionImpulse = 300;
}

// Called when the game starts or when spawned
void ASExplodingBarrel::BeginPlay()
{
	Super::BeginPlay();	
}

void ASExplodingBarrel::OnHealthChanged(USHealthComponent* OwningHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (bExploded)
	{
		return;
	}

	if (Health <= 0.0f)
	{
		bExploded = true;

		// Add an shockwave impulse
		FVector BoostIntensity = FVector::UpVector * ExplosionImpulse;
		MeshComp->AddImpulse(BoostIntensity, NAME_None, true);

		// Play Explosion Effect, if one is configured
		if (ExplosionEffect)
		{
			UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, GetActorLocation());
		}

		RadialForceComp->FireImpulse();

		// Change to exploded material if configured
		if (ExplodedMaterial)
		{
			MeshComp->SetMaterial(0, ExplodedMaterial);
		}
	}
}


