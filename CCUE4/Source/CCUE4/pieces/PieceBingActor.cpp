// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceBingActor.h"

APieceBingActor::APieceBingActor()
	: ABasePieceActor() {
}

void APieceBingActor::Init(const cc::ChessConstants::Side& side, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::BING, pos, assetsLoader);
}

bool APieceBingActor::CheckMove(int32 posIdx) {
	FIntPoint destPos = cc::ChessConstants::PieceIndexToPosition(posIdx);
	// UE_LOG(LogTemp, Log, TEXT(" APieceBingActor::CheckMove %d %d %d %d"), currentPos_.X, currentPos_.Y, destPos.X, destPos.Y);

	bool crossedRiver = false;
	if (side_ == cc::ChessConstants::Side::RED) {
		crossedRiver = (currentPos_.Y < 0);
	} else {
		crossedRiver = (currentPos_.Y > 0);
	}

	int32 offsetX = destPos.X - currentPos_.X;
	int32 offsetY = destPos.Y - currentPos_.Y;
	if (offsetX == 0) {
		if (offsetY == -2) {
			return side_ == cc::ChessConstants::Side::RED;
		} else if (offsetY == 2) {
			return side_ == cc::ChessConstants::Side::BLACK;
		}
	} else if (crossedRiver && offsetY == 0) {
		return offsetX == 2 || offsetX == -2;
	}

	return false;
}
