// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePieceActor.h"
#include "PiecePaoActor.generated.h"

/**
 * 
 */
UCLASS()
class CCUE4_API APiecePaoActor : public ABasePieceActor
{
	GENERATED_BODY()

public:
	APiecePaoActor();

	void Init(const cc::ChessConstants::Side& side, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) override;
	
};
