// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePieceManager.h"
#include "core/ChessConstants.h"

// Sets default values
ABasePieceManager::ABasePieceManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	scale_ = 1.0f;
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

void ABasePieceManager::SetPositionScale(float scale) {
	scale_ = scale;
}

TArray<FVector> ABasePieceManager::GetPieceInitPositions() {
	TArray<FIntPoint> intPos = cc::ChessConstants::PieceInitPositions();
	TArray<FVector> pos3D;
	for (int i = 0; i < intPos.Num(); i++) {
		pos3D.Add(FVector(intPos[i].X * scale_, intPos[i].Y * scale_, 0));
	}
	return pos3D;
}
