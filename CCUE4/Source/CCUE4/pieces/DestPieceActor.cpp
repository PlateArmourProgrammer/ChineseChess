// Fill out your copyright notice in the Description page of Project Settings.


#include "DestPieceActor.h"
#include "../AssetsLoader.h"

ADestPieceActor::ADestPieceActor()
	: ABasePieceActor(), meshIdx_(-1) {
}

void ADestPieceActor::Init(const cc::ChessConstants::Side& side, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	InitInternal(side, cc::ChessConstants::Type::BING, pos, assetsLoader);

	UStaticMeshComponent* comp = GetStaticMeshComponent();
	comp->SetMaterial(0, assetsLoader->GetDestPieceMaterial());
	comp->SetVisibility(false, true);

	SetActorScale3D(FVector(5.5f, 5.5f, 5.5f));
}

void ADestPieceActor::UpdatePos(int32 posIdx) {
	UStaticMeshComponent* comp = GetStaticMeshComponent();
	if (posIdx < 0) {
		comp->SetVisibility(false, true);
		return;
	}
	comp->SetVisibility(true, true);

	FIntPoint pos = cc::ChessConstants::PieceIndexToPosition(posIdx);
	SetActorRelativeLocation(FVector(pos.X, pos.Y, 0) * cc::ChessConstants::PosScale);
	UE_LOG(LogTemp, Log, TEXT("OnBoardOver %d %d %d"), meshIdx_, pos.X, pos.Y);
}

void ADestPieceActor::UpdateMesh(const cc::ChessConstants::Side& side, const cc::ChessConstants::Type& type, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	UStaticMeshComponent* comp = GetStaticMeshComponent();

	int32 meshIdx = GetMeshIndex(side, type);
	if (meshIdx != meshIdx_) {
		meshIdx_ = meshIdx;
		UStaticMeshComponent* meshComp = GetStaticMeshComponent();
		meshComp->SetStaticMesh(assetsLoader->GetPieceStaticMesh(meshIdx_));
	}
}

void ADestPieceActor::Hide() {
	UStaticMeshComponent* comp = GetStaticMeshComponent();
	comp->SetVisibility(false, true);
}
