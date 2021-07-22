// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Map_Blueprints.generated.h"

UCLASS()
class DIMWAR_API AMap_Blueprints : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMap_Blueprints();

	UPROPERTY(EditAnywhere, category = "Rounds settings")
	int32 RoundsForWin = 10;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
