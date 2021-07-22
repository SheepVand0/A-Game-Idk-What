// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CPP_Player.h"
#include "Engine/World.h"


// Sets default values
ACPP_Player::ACPP_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_Player::calculLifeShield(float life, float shield, float value, float OUT& ret_life, float OUT& ret_shield) {

	shield = shield - value / 2;
	if (shield < 0) {
		ret_shield = 0;
		ret_life = life + shield;
	}
	else {
		ret_shield = shield;
		ret_life = life;
	}

	if (life < 0) {
		ret_life = 0;
	}

}

void ACPP_Player::notreplic_fire(USceneComponent* camera, float distance, struct FHitResult& OutHit) {
	//set line collision params
	FCollisionQueryParams params;

	//Execute line trace
	GetWorld()->LineTraceSingleByChannel(OutHit, camera->GetComponentLocation(), (camera->GetForwardVector() * distance) + camera->GetComponentLocation(), ECC_WorldDynamic, params);
}

void ACPP_Player::calcul_line_start_and_end(USceneComponent* line_start_component, float distance, FVector& Line_Start, FVector& Line_End) {
	//Line start
	Line_Start = line_start_component->GetComponentLocation();
	//Line End
	Line_End = (line_start_component->GetForwardVector() * distance) + line_start_component->GetComponentLocation();
}

