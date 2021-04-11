// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceJiangActor.h"

APieceJiangActor::APieceJiangActor()
	: ABasePieceActor() {
}

void APieceJiangActor::Init(const cc::ChessConstants::Side& side, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::JIANG, pos, assetsLoader);
}

bool APieceJiangActor::CheckMove(int32 posIdx, const TArray<ABasePieceActor*>* pieces) {
	FIntPoint destPos = cc::ChessConstants::PieceIndexToPosition(posIdx);
	int32 offsetX = destPos.X - currentPos_.X;
	int32 offsetY = destPos.Y - currentPos_.Y;
	if (offsetX != 0 && offsetY != 0) {
		return false;
	}
	if (destPos.X < -2 || destPos.X > 2) {
		return false;
	}
	if (side_ == cc::ChessConstants::Side::RED) {
		if (destPos.Y < 5) {
			return false;
		}
	} else {
		if (destPos.Y > -5) {
			return false;
		}
	}
	if (offsetX == 0) {
		if (offsetY == 2 || offsetY == -2) {
			return true;
		}
	} else {
		if (offsetX == 2 || offsetX == -2) {
			return true;
		}
	}

	return false;
}
