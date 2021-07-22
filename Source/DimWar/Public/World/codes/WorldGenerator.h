// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "World/codes/Structures/StructuresMain.h"
#include "WorldGenerator.generated.h"

USTRUCT(BlueprintType)
struct FStructureSettings {

	GENERATED_BODY()

public:
		

		UPROPERTY(EditAnywhere, BlueprintType, BlueprintReadWrite)
		FVector Location;

		UPROPERTY(EditAnywhere, BlueprintType, BlueprintReadWrite)
		FRotator Rotation;

		UPROPERTY(EditAnywhere, BlueprintType, BlueprintReadWrite)
		FString StructType;


		UPROPERTY(EditAnywhere, BlueprintType, BlueprintReadWrite)
		float structureSize;
};


UCLASS()
class DIMWAR_API AWorldGenerator : public AActor
{
	GENERATED_BODY()

public:


	// Sets default values for this actor's properties
	AWorldGenerator();


	UFUNCTION(BlueprintCallable)
	void generateStructure(FStructureSettings settings);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
