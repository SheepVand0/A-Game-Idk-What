// Fill out your copyright notice in the Description page of Project Settings.


#include "World/codes/Structures/StructuresMain.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AStructuresMain::AStructuresMain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStructuresMain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStructuresMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStructuresMain::spawnStructure(FStructureSettings setting) {

	FActorSpawnParameters params;
	
	if (setting.StructType == FString("VILLAGE")) {
		
	}

}

