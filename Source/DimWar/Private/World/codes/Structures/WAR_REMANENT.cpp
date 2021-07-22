// Fill out your copyright notice in the Description page of Project Settings.


#include "World/codes/Structures/WAR_REMANENT.h"

// Sets default values
AWAR_REMANENT::AWAR_REMANENT()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWAR_REMANENT::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWAR_REMANENT::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWAR_REMANENT::Generate(float spacing, int HouseTypesNumber) {

	FActorSpawnParameters params;

	AActor* spawnedhouse = NULL;
	FVector lastpos = GetActorLocation();
	FRotator lastrot = GetActorRotation();

	for (int i = 0; i < HouseTypesNumber * 3; i++) {

		//define structure part location and rotation
		lastpos = FVector(lastpos.X + FMath::RandRange(-1.9f, -2.3f) *
			FMath::RandRange(spacing * -1, spacing), lastpos.Y + FMath::RandRange(-1.8f, -2.3f) * FMath::RandRange(spacing * -1, spacing), GetActorLocation().Z);
		lastrot = FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 0.0f);

		//spawn structure parts
		int RandomSelected = FMath::RandRange(0, HouseTypesNumber);
		if (AWAR_REMANENT::HousesEnabled[RandomSelected] == 1) {
			spawnedhouse = GetWorld()->SpawnActor(AWAR_REMANENT::HouseTypes[RandomSelected],
				&lastpos,
				&lastrot,
				params);
		}

		if (spawnedhouse != NULL) {
			lastpos = spawnedhouse->GetActorLocation();
			lastrot = spawnedhouse->GetActorRotation();
		}

	}

}
