// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePieceManager.h"
#include "core/ChessConstants.h"

// Sets default values
ABasePieceManager::ABasePieceManager()
	: scale_(1.0f), chosenIdx_(-1) {
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
	// UE_LOG(LogTemp, Log, TEXT("OnBoardClicked down %d"), chosenIdx_);
	PieceClicked(chosenIdx_, false);
	for (int i = 0; i < piecesPos_.Num(); i++) {
		if (cc::ChessConstants::GetVectorLength2D(pos - piecesPos_[i]) < temp) {
			if (i != chosenIdx_) {
				updateChosenIdx(i);
				PieceClicked(chosenIdx_, true);
				// UE_LOG(LogTemp, Log, TEXT("OnBoardClicked up %d"), chosenIdx_);
			} else {
				updateChosenIdx(-1);
			}
			return;
		}
	}
}

void ABasePieceManager::OnBoardOver(FVector pos) {
	if (chosenIdx_ == -1) {
		return;
	}
	int32 destIdx = cc::ChessConstants::IndexFromVectorPosition(pos, scale_);
	if (destIdx_ == destIdx) {
		return;
	}
	destIdx_ = destIdx;

	FIntPoint debugPos = cc::ChessConstants::PieceIndexToPosition(destIdx);
	UE_LOG(LogTemp, Log, TEXT("OnBoardOver %d %d %d"), destIdx, debugPos.X, debugPos.Y);
}

void ABasePieceManager::PieceClicked_Implementation(int32 index, bool clicked) {
	UE_LOG(LogTemp, Log, TEXT("PieceClicked %d"), index);
}

void ABasePieceManager::updateChosenIdx(int chosenIdx) {
	chosenIdx_ = chosenIdx;
	destIdx_ = -1;
}
