// Fill out your copyright notice in the Description page of Project Settings.


#include "World/codes/Structures/NETH_PART.h"

// Sets default values
ANETH_PART::ANETH_PART()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANETH_PART::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANETH_PART::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANETH_PART::Generate(float size, int HouseTypesNumber) {

	FActorSpawnParameters params;
	params.bNoFail = true;

	AActor* spawnedhouse = NULL;
	FVector lastpos = GetActorLocation();
	FRotator lastrot = GetActorRotation();

	for (int i = 0; i < HouseTypesNumber * 70; i++) {

		//define structure part location and rotation
		lastpos = FVector(FMath::RandRange(size * -1, size), FMath::RandRange(size * -1, size), GetActorLocation().Z);
		lastrot = FRotator(0.0f, FMath::RandRange(0.0f, 360.0f) * 90, 0.0f);

		//spawn structure parts
		int RandomSelected = FMath::RandRange(0, HouseTypesNumber);
		if (ANETH_PART::HousesEnabled[RandomSelected] == 1) {
			spawnedhouse = GetWorld()->SpawnActor(ANETH_PART::HouseTypes[RandomSelected],
				&lastpos,
				&lastrot,
				params);
			//FVector newloc = FVector(GetActorLocation().X, GetActorLocation().Y, -50000.0f);
		}

	}

}