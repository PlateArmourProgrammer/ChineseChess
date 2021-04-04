// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePieceActor.h"
#include "PieceJiangActor.generated.h"

/**
 * 
 */
UCLASS()
class CCUE4_API APieceJiangActor : public ABasePieceActor
{
	GENERATED_BODY()

public:
	APieceJiangActor();

	void Init(const cc::ChessConstants::Side& side, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) override;
	
};
