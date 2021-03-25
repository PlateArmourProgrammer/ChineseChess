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

TArray<FVector> ABasePieceManager::GetPieceInitPositions(float posZ) {
	TArray<FIntPoint> intPos = cc::ChessConstants::PieceInitPositions();
	for (int i = 0; i < intPos.Num(); i++) {
		piecesPos_.Add(FVector(intPos[i].X * scale_, intPos[i].Y * scale_, posZ));
	}
	return piecesPos_;
}

void ABasePieceManager::OnBoardClicked(FVector pos) {
	// UE_LOG(LogTemp, Log, TEXT("OnBoardClicked %f %f %f"), pos.X, pos.Y, pos.Z);
	float temp = scale_ * 0.9f;
	for (int i = 0; i < piecesPos_.Num(); i++) {
		if (cc::ChessConstants::GetVectorLength2D(pos - piecesPos_[i]) < temp) {
			PieceClicked(i);
			return;
		}
	}
	PieceClicked_Implementation(-1);
}

void ABasePieceManager::OnBoardOver(FVector pos) {
	UE_LOG(LogTemp, Log, TEXT("OnBoardOver %f %f %f"), pos.X, pos.Y, pos.Z);
}

void ABasePieceManager::PieceClicked_Implementation(int32 index) {
	UE_LOG(LogTemp, Log, TEXT("PieceClicked %d"), index);
}
