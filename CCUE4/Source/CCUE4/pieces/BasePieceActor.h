// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "../core/ChessConstants.h"
#include "BasePieceActor.generated.h"

class AssetsLoader;

UCLASS()
class CCUE4_API ABasePieceActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	ABasePieceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Init(const cc::ChessConstants::Side& side, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {}

	virtual void OnChosen(bool chosen);

protected:
	void InitInternal(const cc::ChessConstants::Side& side, const cc::ChessConstants::Type& type, const FVector& pos, const std::shared_ptr<AssetsLoader>& assetsLoader);

protected:
	cc::ChessConstants::Side side_;
	cc::ChessConstants::Type type_;

private:
	FVector currentPos_;

};
