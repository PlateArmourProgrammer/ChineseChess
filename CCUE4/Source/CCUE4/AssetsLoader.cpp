// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetsLoader.h"

AssetsLoader::AssetsLoader() : pieceMat_(nullptr) {
}

AssetsLoader::~AssetsLoader() {
	if (pieceMat_) {
		delete pieceMat_;
		pieceMat_ = nullptr;
	}
}

void AssetsLoader::Load() {
	pieceMat_ = new ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/models/tex_chess_Mat.tex_chess_Mat'"));
	destPieceMat_ = new ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/models/tex_chess_Mat_2.tex_chess_Mat_2'"));

	pieceMeshs_[0] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/r_j.r_j'"));
	pieceMeshs_[1] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/r_s.r_s'"));
	pieceMeshs_[2] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/r_x.r_x'"));
	pieceMeshs_[3] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/r_m.r_m'"));
	pieceMeshs_[4] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/r_c.r_c'"));
	pieceMeshs_[5] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/r_p.r_p'"));
	pieceMeshs_[6] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/r_b.r_b'"));

	pieceMeshs_[7] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/b_j.b_j'"));
	pieceMeshs_[8] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/b_s.b_s'"));
	pieceMeshs_[9] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/b_x.b_x'"));
	pieceMeshs_[10] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/b_m.b_m'"));
	pieceMeshs_[11] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/b_c.b_c'"));
	pieceMeshs_[12] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/b_p.b_p'"));
	pieceMeshs_[13] = new ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/models/b_b.b_b'"));
}

UMaterial* AssetsLoader::GetPieceMaterial() const {
	if (!pieceMat_) {
		return nullptr;
	}
	return pieceMat_->Object;
}

UMaterial* AssetsLoader::GetDestPieceMaterial() const {
	if (!destPieceMat_) {
		return nullptr;
	}
	return destPieceMat_->Object;
}

UStaticMesh* AssetsLoader::GetPieceStaticMesh(int32 idx) const {
	if (idx < 0 || idx > 13) {
		return nullptr;
	}
	if (!pieceMeshs_[idx]) {
		return nullptr;
	}
	return pieceMeshs_[idx]->Object;
}
