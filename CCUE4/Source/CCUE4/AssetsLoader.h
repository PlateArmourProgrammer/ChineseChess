// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class CCUE4_API AssetsLoader {
public:
	AssetsLoader();
	~AssetsLoader();

	void Load();

	UMaterial* GetPieceMaterial() const;

	UStaticMesh* GetPieceStaticMesh(int32 idx) const;

private:
	ConstructorHelpers::FObjectFinder<UMaterial>* pieceMat_;

	ConstructorHelpers::FObjectFinder<UStaticMesh>* pieceMeshs_[14];
};
