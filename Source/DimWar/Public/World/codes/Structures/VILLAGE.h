// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VILLAGE.generated.h"

UCLASS()
class DIMWAR_API AVILLAGE : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVILLAGE();

	UPROPERTY(EditAnywhere)
	float Size;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> HouseTypes[4] = {NULL, NULL, NULL, NULL};

	UPROPERTY(EditAnywhere)
	int HousesEnabled[4] = {1, 1, 1, 1};


	UFUNCTION(BlueprintCallable)
	void Generate(float spacing, int HouseTypesNumber);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
