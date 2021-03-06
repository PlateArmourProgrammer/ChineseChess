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

	playingSide_ = cc::ChessConstants::Side::RED;
}

// Called when the game starts or when spawned
void ABasePieceManager::BeginPlay()
{
	Super::BeginPlay();

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
	int newChosen = -1;
	for (int i = 0; i < pieces_.Num(); i++) {
		const FIntPoint& pos = pieces_[i]->GetPos();
		if (cc::ChessConstants::GetVectorLength2D(normalizedPos - FVector(pos.X, pos.Y, 0)) < temp) {
			if (i != chosenIdx_) {
				newChosen = i;
			}
			break;
		}
	}

	// UE_LOG(LogTemp, Log, TEXT("OnBoardClicked chosenIdx_ %d %d %ld"), chosenIdx_, newChosen, newChosen != -1 ? pieces_[newChosen]->GetSide() : -1);
	bool validMove = false;
	if (chosenIdx_ >= 0) {
		validMove = pieces_[chosenIdx_]->CheckMove(destPosIdx_, &pieces_);
		// UE_LOG(LogTemp, Log, TEXT("OnBoardClicked validMove %d"), validMove);
		if (validMove) {
			FIntPoint destPos = cc::ChessConstants::PieceIndexToPosition(destPosIdx_);
			pieces_[chosenIdx_]->MoveTo(destPos);

			if (newChosen != -1) {
				if (pieces_[newChosen]->GetPos() == destPos) {
					pieces_[newChosen]->BeEaten();
					if (newChosen == 0 || newChosen == 16) {
						UE_LOG(LogTemp, Log, TEXT("Win: %ld"), playingSide_);
					}
					newChosen = -1;
				}
			}
		}
	}

	OnPieceClicked(chosenIdx_, false);
	if (newChosen != -1 && pieces_[newChosen]->GetSide() == playingSide_) {
		UpdateChosenIdx(newChosen);
		OnPieceClicked(chosenIdx_, true);
		// UE_LOG(LogTemp, Log, TEXT("OnBoardClicked up %d"), chosenIdx_);
	} else {
		UpdateChosenIdx(-1);
	}

	if (validMove) {
		if (playingSide_ == cc::ChessConstants::Side::RED) {
			playingSide_ = cc::ChessConstants::Side::BLACK;
		} else {
			playingSide_ = cc::ChessConstants::Side::RED;
		}
	}
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
	const TArray<FIntPoint>& piecesPos = cc::ChessConstants::PieceInitPositions();

	CreateOnePiece(0, APieceJiangActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(1, APieceShiActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(2, APieceShiActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(3, APieceXiangActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(4, APieceXiangActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(5, APieceMaActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(6, APieceMaActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(7, APieceCheActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(8, APieceCheActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(9, APiecePaoActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(10, APiecePaoActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(11, APieceBingActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(12, APieceBingActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(13, APieceBingActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(14, APieceBingActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);
	CreateOnePiece(15, APieceBingActor::StaticClass(), cc::ChessConstants::Side::BLACK, piecesPos);

	CreateOnePiece(16, APieceJiangActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(17, APieceShiActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(18, APieceShiActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(19, APieceXiangActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(20, APieceXiangActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(21, APieceMaActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(22, APieceMaActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(23, APieceCheActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(24, APieceCheActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(25, APiecePaoActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(26, APiecePaoActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(27, APieceBingActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(28, APieceBingActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(29, APieceBingActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(30, APieceBingActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);
	CreateOnePiece(31, APieceBingActor::StaticClass(), cc::ChessConstants::Side::RED, piecesPos);

	UWorld* world = GetWorld();
	destPiece_ = world->SpawnActor<ADestPieceActor>(ADestPieceActor::StaticClass());
	destPiece_->Init(cc::ChessConstants::Side::BLACK, piecesPos[0], assetsLoader_);
	destPiece_->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABasePieceManager::CreateOnePiece(const int32 idx, UClass* clazz, const cc::ChessConstants::Side& side, const TArray<FIntPoint>& posArr) {
	UWorld* world = GetWorld();
	ABasePieceActor* actor = world->SpawnActor<ABasePieceActor>(clazz);
	actor->Init(side, posArr[idx], assetsLoader_);
	actor->SetIdx(idx);
	actor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	pieces_.Add(actor);
}
