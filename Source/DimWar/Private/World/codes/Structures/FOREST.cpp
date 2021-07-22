// Fill out your copyright notice in the Description page of Project Settings.


#include "World/codes/Structures/FOREST.h"

// Sets default values
AFOREST::AFOREST()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFOREST::BeginPlay()
{
	Super::BeginPlay();
	
	generateForest(30, 10000);
}

// Called every frame
void AFOREST::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFOREST::generateForest(float NumTrees, float Size) {
	
	FActorSpawnParameters params;
	FVector loc = GetActorLocation();
	FRotator rot = GetActorRotation();
	AActor* SpawnedTree;

	for (int i = 0; i < NumTrees; i++) {
		loc = FVector(GetActorLocation().X + FMath::RandRange(Size * -1, Size), GetActorLocation().Y + FMath::RandRange(Size * -1, Size), GetActorLocation().Z);
		SpawnedTree = GetWorld()->SpawnActor(AFOREST::Tree, &loc, &rot, params);
	}
}
