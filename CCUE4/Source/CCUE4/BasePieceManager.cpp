// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePieceManager.h"

// Sets default values
ABasePieceManager::ABasePieceManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABasePieceManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePieceManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ABasePieceManager::TestCallback() {
	return 2;
}
