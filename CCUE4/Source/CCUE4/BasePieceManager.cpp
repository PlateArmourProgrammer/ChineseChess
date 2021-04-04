// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePieceManager.h"
#include "AssetsLoader.h"
#include "pieces/PieceBingActor.h"
#include "pieces/PieceCheActor.h"
#include "pieces/PieceJiangActor.h"
#include "pieces/PieceMaActor.h"
#include "pieces/PiecePaoActor.h"
#include "pieces/PieceShiActor.h"
#include "pieces/PieceXiangActor.h"
#include "pieces/DestPieceActor.h"

// Sets default values
ABasePieceManager::ABasePieceManager()
	: chosenIdx_(-1), destPosIdx_(-1) {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	assetsLoader_.reset(new AssetsLoader);
	assetsLoader_->Load();
}

// Called when the game starts or when spawned
void ABasePieceManager::BeginPlay()
{
	Super::BeginPlay();

	piecesPos_ = cc::ChessConstants::PieceInitPositions();
	CreatePieces();
}

// Called every frame
void ABasePieceManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePieceManager::OnBoardClicked(FVector pos) {
	// UE_LOG(LogTemp, Log, TEXT("OnBoardClicked %f %f %d"), pos.X, pos.Y, chosenIdx_);
	float temp = 0.9f;
	FVector normalizedPos = pos / cc::ChessConstants::PosScale;
	UE_LOG(LogTemp, Log, TEXT("OnBoardClicked %f %f %d"), normalizedPos.X, normalizedPos.Y, chosenIdx_);
	// UE_LOG(LogTemp, Log, TEXT("OnBoardClicked down %d"), chosenIdx_);
	OnPieceClicked(chosenIdx_, false);
	for (int i = 0; i < piecesPos_.Num(); i++) {
		if (cc::ChessConstants::GetVectorLength2D(normalizedPos - FVector(piecesPos_[i].X, piecesPos_[i].Y, 0)) < temp) {
			if (i != chosenIdx_) {
				UpdateChosenIdx(i);
				OnPieceClicked(chosenIdx_, true);
				// UE_LOG(LogTemp, Log, TEXT("OnBoardClicked up %d"), chosenIdx_);
			} else {
				UpdateChosenIdx(-1);
			}
			return;
		}
	}
	UpdateChosenIdx(-1);
}

void ABasePieceManager::OnBoardOver(FVector pos) {
	if (chosenIdx_ == -1) {
		destPiece_->Hide();
		return;
	}
	int32 destIdx = cc::ChessConstants::IndexFromVectorPosition(pos, cc::ChessConstants::PosScale);
	if (destPosIdx_ == destIdx) {
		return;
	}
	destPosIdx_ = destIdx;

	destPiece_->UpdatePos(destPosIdx_);
}

void ABasePieceManager::OnPieceClicked(int32 index, bool clicked) {
	// UE_LOG(LogTemp, Log, TEXT("PieceClicked %d %d"), index, clicked);
	if (index < 0) {
		destPiece_->Hide();
		return;
	}
	pieces_[index]->OnChosen(clicked);
	if (clicked) {
		destPiece_->UpdateMesh(pieces_[index]->GetSide(), pieces_[index]->GetType(), assetsLoader_);
	} else {
		destPiece_->Hide();
	}
}

void ABasePieceManager::UpdateChosenIdx(int chosenIdx) {
	chosenIdx_ = chosenIdx;
	destPosIdx_ = -1;
}

void ABasePieceManager::CreatePieces() {
	CreateOnePiece(0, APieceJiangActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(1, APieceShiActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(2, APieceShiActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(3, APieceXiangActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(4, APieceXiangActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(5, APieceMaActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(6, APieceMaActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(7, APieceCheActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(8, APieceCheActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(9, APiecePaoActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(10, APiecePaoActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(11, APieceBingActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(12, APieceBingActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(13, APieceBingActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(14, APieceBingActor::StaticClass(), cc::ChessConstants::Side::BLACK);
	CreateOnePiece(15, APieceBingActor::StaticClass(), cc::ChessConstants::Side::BLACK);

	CreateOnePiece(16, APieceJiangActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(17, APieceShiActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(18, APieceShiActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(19, APieceXiangActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(20, APieceXiangActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(21, APieceMaActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(22, APieceMaActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(23, APieceCheActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(24, APieceCheActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(25, APiecePaoActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(26, APiecePaoActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(27, APieceBingActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(28, APieceBingActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(29, APieceBingActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(30, APieceBingActor::StaticClass(), cc::ChessConstants::Side::RED);
	CreateOnePiece(31, APieceBingActor::StaticClass(), cc::ChessConstants::Side::RED);

	UWorld* world = GetWorld();
	destPiece_ = world->SpawnActor<ADestPieceActor>(ADestPieceActor::StaticClass());
	FIntPoint pos = piecesPos_[0];
	destPiece_->Init(cc::ChessConstants::Side::BLACK, FVector(pos.X, pos.Y, 0), assetsLoader_);
	destPiece_->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABasePieceManager::CreateOnePiece(const int32 idx, UClass* clazz, const cc::ChessConstants::Side& side) {
	UWorld* world = GetWorld();
	ABasePieceActor* actor = world->SpawnActor<ABasePieceActor>(clazz);
	FIntPoint pos = piecesPos_[idx];
	actor->Init(side, FVector(pos.X, pos.Y, 0), assetsLoader_);
	actor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	pieces_.Add(actor);
}
