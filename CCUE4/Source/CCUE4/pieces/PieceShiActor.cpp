// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceShiActor.h"

APieceShiActor::APieceShiActor()
	: ABasePieceActor() {
}

void APieceShiActor::Init(const cc::ChessConstants::Side& side, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::SHI, pos, assetsLoader);
}
