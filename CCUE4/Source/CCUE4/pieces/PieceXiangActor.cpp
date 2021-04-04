// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceXiangActor.h"

APieceXiangActor::APieceXiangActor()
	: ABasePieceActor() {
}

void APieceXiangActor::Init(const cc::ChessConstants::Side& side, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::XIANG, pos, assetsLoader);
}
