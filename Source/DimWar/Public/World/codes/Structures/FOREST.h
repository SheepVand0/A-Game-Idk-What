// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FOREST.generated.h"

UCLASS()
class DIMWAR_API AFOREST : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFOREST();

	UFUNCTION(BlueprintCallable)
	void generateForest(float NumTrees, float Size);

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> Tree;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
