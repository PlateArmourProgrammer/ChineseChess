// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceJiangActor.h"

APieceJiangActor::APieceJiangActor()
	: ABasePieceActor() {
}

void APieceJiangActor::Init(const cc::ChessConstants::Side& side, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::JIANG, pos, assetsLoader);
}
