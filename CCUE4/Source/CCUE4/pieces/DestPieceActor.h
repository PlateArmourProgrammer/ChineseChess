// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePieceActor.h"
#include "DestPieceActor.generated.h"

/**
 * 
 */
UCLASS()
class CCUE4_API ADestPieceActor : public ABasePieceActor
{
	GENERATED_BODY()

public:
	ADestPieceActor();

	void Init(const cc::ChessConstants::Side& side, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) override;

	void UpdatePos(int32 posIdx);

	void UpdateMesh(const cc::ChessConstants::Side& side, const cc::ChessConstants::Type& type, const std::shared_ptr<AssetsLoader>& assetsLoader);

	void Hide();

private:
	int32 meshIdx_;
	
};
