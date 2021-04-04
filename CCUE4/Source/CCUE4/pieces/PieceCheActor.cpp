// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceCheActor.h"

APieceCheActor::APieceCheActor()
	: ABasePieceActor() {
}

void APieceCheActor::Init(const cc::ChessConstants::Side& side, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::CHE, pos, assetsLoader);
}
