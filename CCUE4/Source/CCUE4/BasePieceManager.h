// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePieceManager.generated.h"

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
		void SetPositionScale(float scale);

	UFUNCTION(BlueprintCallable, Category="PieceManager")
		TArray<FVector> GetPieceInitPositions(float posZ);

	UFUNCTION(BlueprintCallable, Category = "PieceManager")
		void OnBoardClicked(FVector pos);

	UFUNCTION(BlueprintCallable, Category = "PieceManager")
		void OnBoardOver(FVector pos);

	UFUNCTION(BlueprintNativeEvent, Category = "PieceManager")
		void PieceClicked(int32 index, bool clicked);

private:
	void updateChosenIdx(int chosenIdx);

private:
	float scale_;
	TArray<FVector> piecesPos_;

	int32 chosenIdx_;
	int32 destIdx_;
};
