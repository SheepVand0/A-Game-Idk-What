// Fill out your copyright notice in the Description page of Project Settings.


#include "World/codes/Structures/BLUE_GRASS_BIOME.h"

// Sets default values
ABLUE_GRASS_BIOME::ABLUE_GRASS_BIOME()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABLUE_GRASS_BIOME::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABLUE_GRASS_BIOME::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABLUE_GRASS_BIOME::Generate(float spacing, int HouseTypesNumber) {

	FActorSpawnParameters params;

	AActor* spawnedhouse = NULL;
	FVector lastpos = GetActorLocation();
	FRotator lastrot = GetActorRotation();

	for (int i = 0; i < HouseTypesNumber * 50; i++) {

		//define structure part location and rotation
		lastpos = FVector(lastpos.X + FMath::RandRange(-1.9f, -2.3f) *
		FMath::RandRange(spacing * -1, spacing), lastpos.Y + FMath::RandRange(-1.8f, -2.3f) * FMath::RandRange(spacing * -1, spacing), GetActorLocation().Y);
		lastrot = FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 0.0f);

		//spawn structure parts
		int RandomSelected = FMath::RandRange(0, HouseTypesNumber);
		if (ABLUE_GRASS_BIOME::HousesEnabled[RandomSelected] == 1) {
			spawnedhouse = GetWorld()->SpawnActor(ABLUE_GRASS_BIOME::HouseTypes[RandomSelected],
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