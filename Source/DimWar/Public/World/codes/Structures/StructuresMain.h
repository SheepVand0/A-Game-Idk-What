// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "World/codes/Structures/StructureClasses.h"
#include "Components/StaticMeshComponent.h"
#include "World/codes/WorldGenerator.h"
#include "Engine/UserDefinedEnum.h"
#include "StructuresMain.generated.h"

UCLASS()
class DIMWAR_API AStructuresMain : public AActor
{

	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStructuresMain();

	//PROPERTIES
	UPROPERTY()
	float StructureRadius;

	//UFUNCTIONS
	UFUNCTION(BlueprintCallable)
	void spawnStructure(FStructureSettings settings);

	//define structures classes
	UPROPERTY(EditDefaultsOnly, category = "Structures Classes")
	TSubclassOf<AActor> StructClasses[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

	UPROPERTY(EditDefaultsOnly, category = "Structures Classes")
	FString Test[2] = {TEXT("1"), TEXT("2")};
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
