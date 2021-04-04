// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceBingActor.h"

APieceBingActor::APieceBingActor()
	: ABasePieceActor() {
}

void APieceBingActor::Init(const cc::ChessConstants::Side& side, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::BING, pos, assetsLoader);
}
