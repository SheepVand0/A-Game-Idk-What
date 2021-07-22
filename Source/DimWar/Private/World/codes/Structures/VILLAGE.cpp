// Fill out your copyright notice in the Description page of Project Settings.


#include "World/codes/Structures/VILLAGE.h"

// Sets default values
AVILLAGE::AVILLAGE()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVILLAGE::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void AVILLAGE::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVILLAGE::Generate(float spacing, int HouseTypesNumber) {
	
	FActorSpawnParameters params;
	params.bNoFail = true;


	AActor* spawnedhouse= NULL;
	FVector lastpos = GetActorLocation();
	FRotator lastrot = GetActorRotation();

	for (int i = 0; i < HouseTypesNumber * 3; i++) {
		
		//define structure part location and rotation
		lastpos = FVector(lastpos.X + FMath::RandRange(-1.9f, -2.3f) * 
			FMath::RandRange(spacing * -1,spacing), lastpos.Y + FMath::RandRange(-1.8f, -2.3f) * FMath::RandRange(spacing * -1, spacing), GetActorLocation().Z);
		lastrot = FRotator(0.0f, FMath::RandRange(0, 4) * 90, 0.0f);

		//spawn structure parts
		int RandomSelected = FMath::RandRange(1, HouseTypesNumber);
		if (AVILLAGE::HousesEnabled[RandomSelected] == 1) {
			spawnedhouse = GetWorld()->SpawnActor(AVILLAGE::HouseTypes[RandomSelected], 
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

