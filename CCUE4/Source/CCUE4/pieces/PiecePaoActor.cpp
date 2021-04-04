// Fill out your copyright notice in the Description page of Project Settings.


#include "PiecePaoActor.h"

APiecePaoActor::APiecePaoActor()
	: ABasePieceActor() {
}

void APiecePaoActor::Init(const cc::ChessConstants::Side& side, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::PAO, pos, assetsLoader);
}
