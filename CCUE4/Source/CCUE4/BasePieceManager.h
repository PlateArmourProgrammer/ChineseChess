// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "core/ChessConstants.h"
#include "BasePieceManager.generated.h"

class AssetsLoader;
class ABasePieceActor;
class ADestPieceActor;

UCLASS()
class CCUE4_API ABasePieceManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePieceManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category = "PieceManager")
		void OnBoardClicked(FVector pos);

	UFUNCTION(BlueprintCallable, Category = "PieceManager")
		void OnBoardOver(FVector pos);

private:
	void UpdateChosenIdx(int chosenIdx);

	void CreatePieces();

	void CreateOnePiece(const int32 idx, UClass *clazz, const cc::ChessConstants::Side &side, const TArray<FIntPoint>& posArr);

	void OnPieceClicked(int32 index, bool clicked);

private:
	TArray<ABasePieceActor*> pieces_;
	ADestPieceActor* destPiece_;
	std::shared_ptr<AssetsLoader> assetsLoader_;

	int32 chosenIdx_;
	int32 destPosIdx_;
	cc::ChessConstants::Side playingSide_;
};
