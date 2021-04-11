// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePieceActor.h"
#include "../AssetsLoader.h"

static const FVector HighLightPosOffset = FVector(0, 0, 2);
static const FVector PieceScale = FVector(5, 5, 5);

ABasePieceActor::ABasePieceActor() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void ABasePieceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePieceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePieceActor::BeEaten() {
	MoveTo(99);

	UStaticMeshComponent* meshComp = GetStaticMeshComponent();
	if (meshComp) {
		meshComp->SetVisibility(false);
	}
}

void ABasePieceActor::InitInternal(const cc::ChessConstants::Side& side, const cc::ChessConstants::Type& type, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	side_ = side;
	type_ = type;
	currentPos_ = pos;

	UStaticMeshComponent* meshComp = GetStaticMeshComponent();
	meshComp->SetMaterial(0, assetsLoader->GetPieceMaterial());
	meshComp->SetStaticMesh(assetsLoader->GetPieceStaticMesh(GetMeshIndex(side, type)));

	SetLocationInternal(currentPos_, cc::ChessConstants::PosScale);
	SetActorScale3D(PieceScale);
}

int32 ABasePieceActor::GetMeshIndex(const cc::ChessConstants::Side& side, const cc::ChessConstants::Type& type) {
	int meshIdx = (side == cc::ChessConstants::Side::RED) ? 0 : 7;
	switch (type) {
	case cc::ChessConstants::Type::SHI:
		meshIdx += 1;
		break;

	case cc::ChessConstants::Type::XIANG:
		meshIdx += 2;
		break;

	case cc::ChessConstants::Type::MA:
		meshIdx += 3;
		break;

	case cc::ChessConstants::Type::CHE:
		meshIdx += 4;
		break;

	case cc::ChessConstants::Type::PAO:
		meshIdx += 5;
		break;

	case cc::ChessConstants::Type::BING:
		meshIdx += 6;
		break;

	default:
		break;
	}

	return meshIdx;
}

void ABasePieceActor::SetLocationInternal(const FIntPoint& pos, const float scale, const FVector* offset) {
	FVector temp(pos.X, pos.Y, 0);
	if (offset) {
		temp += *offset;
	}
	SetActorRelativeLocation(temp * scale);
}

void ABasePieceActor::OnChosen(bool chosen) {
	if (!chosen) {
		SetLocationInternal(currentPos_, cc::ChessConstants::PosScale);
		return;
	}
	SetLocationInternal(currentPos_, cc::ChessConstants::PosScale, &HighLightPosOffset);
}

void ABasePieceActor::MoveTo(const FIntPoint& pos) {
	currentPos_ = pos;
	SetLocationInternal(currentPos_, cc::ChessConstants::PosScale);
}

