// Fill out your copyright notice in the Description page of Project Settings.


#include "World/codes/WorldGenerator.h"
#include "World/codes/Structures/StructuresMain.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWorldGenerator::AWorldGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWorldGenerator::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AWorldGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
}

void AWorldGenerator::generateStructure(FStructureSettings settings) {

	//spawnStructure(settings);

}
