// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePieceActor.h"
#include "PieceBingActor.generated.h"

/**
 * 
 */
UCLASS()
class CCUE4_API APieceBingActor : public ABasePieceActor
{
	GENERATED_BODY()

public:
	APieceBingActor();

	void Init(const cc::ChessConstants::Side& side, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) override;
	
};