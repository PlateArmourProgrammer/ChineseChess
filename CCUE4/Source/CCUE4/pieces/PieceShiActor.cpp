// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceShiActor.h"

APieceShiActor::APieceShiActor()
	: ABasePieceActor() {
}

void APieceShiActor::Init(const cc::ChessConstants::Side& side, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::SHI, pos, assetsLoader);
}

bool APieceShiActor::CheckMove(int32 posIdx, const TArray<ABasePieceActor*>* pieces) {
	FIntPoint destPos = cc::ChessConstants::PieceIndexToPosition(posIdx);
	int32 offsetX = destPos.X - currentPos_.X;
	int32 offsetY = destPos.Y - currentPos_.Y;
	int32 absOX = CC_MATH_ABSI32(offsetX);
	int32 absOY = CC_MATH_ABSI32(offsetY);
	if (absOX != 2 || absOY != 2) {
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

	return true;
}
