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
	virtual void Init(const cc::ChessConstants::Side& side, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader) {}

	virtual void OnChosen(bool chosen);

	virtual bool CheckMove(int32 posIdx) {
		return false;
	}

	virtual void MoveTo(const FIntPoint& pos);

	const FIntPoint& GetPos() {
		return currentPos_;
	}

	cc::ChessConstants::Side GetSide() {
		return side_;
	}

	cc::ChessConstants::Type GetType() {
		return type_;
	}

protected:
	void InitInternal(const cc::ChessConstants::Side& side, const cc::ChessConstants::Type& type, const FIntPoint& pos, const std::shared_ptr<AssetsLoader>& assetsLoader);

	int32 GetMeshIndex(const cc::ChessConstants::Side& side, const cc::ChessConstants::Type& type);

private:
	void SetLocationInternal(const FIntPoint& pos, const float scale, const FVector* offset = nullptr);

protected:
	cc::ChessConstants::Side side_;
	cc::ChessConstants::Type type_;

	FIntPoint currentPos_;

};
