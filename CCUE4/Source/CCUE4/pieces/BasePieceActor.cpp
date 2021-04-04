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

void ABasePieceActor::InitInternal(const cc::ChessConstants::Side& side, const cc::ChessConstants::Type& type, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {
	side_ = side;
	type_ = type;
	currentPos_ = pos;

	UStaticMeshComponent* meshComp = GetStaticMeshComponent();
	meshComp->SetMaterial(0, assetsLoader->GetPieceMaterial());

	int meshIdx = (side_ == cc::ChessConstants::Side::RED) ? 0 : 7;
	switch (type_) {
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
	}
	meshComp->SetStaticMesh(assetsLoader->GetPieceStaticMesh(meshIdx));

	SetActorLocation(currentPos_ * cc::ChessConstants::PosScale);
	SetActorScale3D(PieceScale);
}

void ABasePieceActor::OnChosen(bool chosen) {
	if (!chosen) {
		SetActorLocation(currentPos_ * cc::ChessConstants::PosScale);
		return;
	}
	SetActorLocation((currentPos_ + HighLightPosOffset) * cc::ChessConstants::PosScale);
}

