// Fill out your copyright notice in the Description page of Project Settings.


#include "codes/SphereTEst258.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASphereTEst258::ASphereTEst258()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ASphereTEst258::MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));

}

// Called when the game starts or when spawned
void ASphereTEst258::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASphereTEst258::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ASphereTEst258::MeshComponent->SetWorldLocation(FVector(MeshComponent->GetRelativeLocation().X + 1.0f, 0.0f, 0.0f));
}

