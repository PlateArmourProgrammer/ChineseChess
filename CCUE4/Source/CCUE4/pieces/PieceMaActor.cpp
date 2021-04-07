// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceMaActor.h"

APieceMaActor::APieceMaActor()
	: ABasePieceActor() {
}

void APieceMaActor::Init(const cc::ChessConstants::Side& side, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::MA, pos, assetsLoader);
}
