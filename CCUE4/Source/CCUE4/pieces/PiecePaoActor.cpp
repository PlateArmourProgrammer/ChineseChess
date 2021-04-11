// Fill out your copyright notice in the Description page of Project Settings.


#include "PiecePaoActor.h"

APiecePaoActor::APiecePaoActor()
	: ABasePieceActor() {
}

void APiecePaoActor::Init(const cc::ChessConstants::Side& side, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::PAO, pos, assetsLoader);
}

bool APiecePaoActor::CheckMove(int32 posIdx, const TArray<ABasePieceActor*>* pieces) {
	FIntPoint destPos = cc::ChessConstants::PieceIndexToPosition(posIdx);
	int32 offsetX = destPos.X - currentPos_.X;
	int32 offsetY = destPos.Y - currentPos_.Y;
	if (offsetX == 0 && offsetY == 0) {
		return false;
	}

	if (offsetX != 0 && offsetY != 0) {
		return false;
	}

	bool eat = false;
	int32 crossCount = 0;
	if (offsetY == 0) {
		int left = currentPos_.X;
		int right = currentPos_.X;
		if (destPos.X < left) {
			left = destPos.X;
		} else {
			right = destPos.X;
		}
		for (int i = 0; i < pieces->Num(); i++) {
			ABasePieceActor* piece = (*pieces)[i];
			if (piece->GetPos() == destPos) {
				if (piece->GetSide() == side_) {
					return false;
				}
				eat = true;
			}
			if (piece->GetIdx() == idx_ || !piece->GetAlive()) {
				continue;
			}
			const FIntPoint& pos = piece->GetPos();
			if (pos.Y != currentPos_.Y) {
				continue;
			}
			if (pos.X > left && pos.X < right) {
				++crossCount;
			}
		}
	} else {
		int left = currentPos_.Y;
		int right = currentPos_.Y;
		if (destPos.Y < left) {
			left = destPos.Y;
		} else {
			right = destPos.Y;
		}
		for (int i = 0; i < pieces->Num(); i++) {
			ABasePieceActor* piece = (*pieces)[i];
			if (piece->GetPos() == destPos) {
				if (piece->GetSide() == side_) {
					return false;
				}
				eat = true;
			}
			if (piece->GetIdx() == idx_ || !piece->GetAlive()) {
				continue;
			}
			const FIntPoint& pos = piece->GetPos();
			if (pos.X != currentPos_.X) {
				continue;
			}
			if (pos.Y > left && pos.Y < right) {
				++crossCount;
			}
		}
	}
	
	if (eat) {
		return crossCount == 1;
	} else {
		return crossCount == 0;
	}
}
