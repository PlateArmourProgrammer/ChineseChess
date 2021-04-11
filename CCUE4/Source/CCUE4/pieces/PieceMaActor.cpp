// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceMaActor.h"

APieceMaActor::APieceMaActor()
	: ABasePieceActor() {
}

void APieceMaActor::Init(const cc::ChessConstants::Side& side, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::MA, pos, assetsLoader);
}

bool APieceMaActor::CheckMove(int32 posIdx, const TArray<ABasePieceActor*>* pieces) {
	FIntPoint destPos = cc::ChessConstants::PieceIndexToPosition(posIdx);
	int32 offsetX = destPos.X - currentPos_.X;
	int32 offsetY = destPos.Y - currentPos_.Y;

	for (int i = 0; i < pieces->Num(); i++) {
		ABasePieceActor* piece = (*pieces)[i];
		if (piece->GetPos() == destPos && piece->GetSide() == side_) {
			return false;
		}
	}

	int32 absOX = CC_MATH_ABSI32(offsetX);
	int32 absOY = CC_MATH_ABSI32(offsetY);
	if (!((absOX == 2 && absOY == 4) || (absOX == 4 && absOY == 2))) {
		return false;
	}

	FIntPoint eyePos;
	if (offsetX == -4) {
		eyePos = FIntPoint(currentPos_.X - 2, currentPos_.Y);
	} else if (offsetX == 4) {
		eyePos = FIntPoint(currentPos_.X + 2, currentPos_.Y);
	} else if (offsetY == 4) {
		eyePos = FIntPoint(currentPos_.X, currentPos_.Y + 2);
	} else {
		eyePos = FIntPoint(currentPos_.X, currentPos_.Y - 2);
	}

	for (int i = 0; i < pieces->Num(); i++) {
		ABasePieceActor* actor = (*pieces)[i];
		if (actor->GetIdx() == idx_ || !actor->GetAlive()) {
			continue;
		}
		const FIntPoint& pos = actor->GetPos();
		if (pos == eyePos) {
			return false;
		}
	}

	return true;
}
