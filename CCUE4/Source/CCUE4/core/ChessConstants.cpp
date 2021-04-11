#include "ChessConstants.h"

namespace cc {

	static FIntPoint IndexToPositionMap[100] = {
		{-8, -9}, {-6, -9}, {-4, -9}, {-2, -9}, { 0, -9}, { 2, -9}, { 4, -9}, { 6, -9}, { 8, -9}, { 0,  0},
		{-8, -7}, {-6, -7}, {-4, -7}, {-2, -7}, { 0, -7}, { 2, -7}, { 4, -7}, { 6, -7}, { 8, -7}, { 0,  0},
		{-8, -5}, {-6, -5}, {-4, -5}, {-2, -5}, { 0, -5}, { 2, -5}, { 4, -5}, { 6, -5}, { 8, -5}, { 0,  0},
		{-8, -3}, {-6, -3}, {-4, -3}, {-2, -3}, { 0, -3}, { 2, -3}, { 4, -3}, { 6, -3}, { 8, -3}, { 0,  0},
		{-8, -1}, {-6, -1}, {-4, -1}, {-2, -1}, { 0, -1}, { 2, -1}, { 4, -1}, { 6, -1}, { 8, -1}, { 0,  0},
		{-8,  1}, {-6,  1}, {-4,  1}, {-2,  1}, { 0,  1}, { 2,  1}, { 4,  1}, { 6,  1}, { 8,  1}, { 0,  0},
		{-8,  3}, {-6,  3}, {-4,  3}, {-2,  3}, { 0,  3}, { 2,  3}, { 4,  3}, { 6,  3}, { 8,  3}, { 0,  0},
		{-8,  5}, {-6,  5}, {-4,  5}, {-2,  5}, { 0,  5}, { 2,  5}, { 4,  5}, { 6,  5}, { 8,  5}, { 0,  0},
		{-8,  7}, {-6,  7}, {-4,  7}, {-2,  7}, { 0,  7}, { 2,  7}, { 4,  7}, { 6,  7}, { 8,  7}, { 0,  0},
		{-8,  9}, {-6,  9}, {-4,  9}, {-2,  9}, { 0,  9}, { 2,  9}, { 4,  9}, { 6,  9}, { 8,  9}, { 0,  0},
	};

	static const int32 InvalidIdx = 99;

	const float ChessConstants::PosScale = 24.0f;

	FIntPoint ChessConstants::PieceIndexToPosition(int32 index) {
		if (index < 0 || index >= 100) {
			return IndexToPositionMap[InvalidIdx];
		}
		return IndexToPositionMap[index];
	}

	int32 ChessConstants::PiecePositionToIndex(const int32 x, const int32 y) {
		if (x < -9 || x > 9 || y < -10 || y > 10) {
			return InvalidIdx;
		}
		if ((x + 10) % 2 == 1 || (y + 20) % 2 == 0) {
			return InvalidIdx;
		}
		return ((y - (-9)) / 2 * 10) + (x - (-8)) / 2;
	}

	const TArray<FIntPoint>& ChessConstants::PieceInitPositions() {
		static TArray<FIntPoint> ret;
		if (ret.Num() > 0) {
			return ret;
		}
		
		// 0 bj
		ret.Add(IndexToPositionMap[4]);
		// 1 bs1
		ret.Add(IndexToPositionMap[3]);
		// 2 bs2
		ret.Add(IndexToPositionMap[5]);
		// 3 bx1
		ret.Add(IndexToPositionMap[2]);
		// 4 bx2
		ret.Add(IndexToPositionMap[6]);
		// 5 bm1
		ret.Add(IndexToPositionMap[1]);
		// 6 bm2
		ret.Add(IndexToPositionMap[7]);
		// 7 bc1
		ret.Add(IndexToPositionMap[0]);
		// 8 bc2
		ret.Add(IndexToPositionMap[8]);
		// 9 bp1
		ret.Add(IndexToPositionMap[21]);
		// 10 bp2
		ret.Add(IndexToPositionMap[27]);
		// 11 bb1
		ret.Add(IndexToPositionMap[30]);
		// 12 bb2
		ret.Add(IndexToPositionMap[32]);
		// 13 bb3
		ret.Add(IndexToPositionMap[34]);
		// 14 bb4
		ret.Add(IndexToPositionMap[36]);
		// 15 bb5
		ret.Add(IndexToPositionMap[38]);

		// 16 rj
		ret.Add(IndexToPositionMap[94]);
		// 17 rs1
		ret.Add(IndexToPositionMap[93]);
		// 18 rs2
		ret.Add(IndexToPositionMap[95]);
		// 19 rx1
		ret.Add(IndexToPositionMap[92]);
		// 20 rx2
		ret.Add(IndexToPositionMap[96]);
		// 21 rm1
		ret.Add(IndexToPositionMap[91]);
		// 22 rm2
		ret.Add(IndexToPositionMap[97]);
		// 23 rc1
		ret.Add(IndexToPositionMap[90]);
		// 24 rc2
		ret.Add(IndexToPositionMap[98]);
		// 25 rp1
		ret.Add(IndexToPositionMap[71]);
		// 26 rp2
		ret.Add(IndexToPositionMap[77]);
		// 27 rb1
		ret.Add(IndexToPositionMap[60]);
		// 28 rb2
		ret.Add(IndexToPositionMap[62]);
		// 29 rb3
		ret.Add(IndexToPositionMap[64]);
		// 30 rb4
		ret.Add(IndexToPositionMap[66]);
		// 31 rb5
		ret.Add(IndexToPositionMap[68]);

		return ret;
	}

	float ChessConstants::GetVectorLength2D(FVector vec) {
		return sqrt(vec.X * vec.X + vec.Y * vec.Y);
	}

	int32 ChessConstants::IndexFromVectorPosition(const FVector target, const float scale) {
		const float fx = target.X / scale;
		const float fy = target.Y / scale;
		int ix = roundf(fx);
		int iy = roundf(fy);
		// UE_LOG(LogTemp, Log, TEXT("OnBoardOver %d %d"), ix, iy);
		if (ix < -9 || ix > 9 || iy < -10 || iy > 10) {
			return InvalidIdx;
		}

		if (ix == -9) {
			ix = -8;
		} else if (ix == 9) {
			ix = 8;
		} else if ((ix + 20) % 2 == 1) {
			ix = (fx > ix) ? (ix + 1) : (ix - 1);
		}

		if (iy == -10) {
			iy = -9;
		} else if (iy == 10) {
			iy = 9;
		} else if ((iy + 20) % 2 == 0) {
			iy = (fy > iy) ? (iy + 1) : (iy - 1);
		}

		return PiecePositionToIndex(ix, iy);
	}

	int32 ChessConstants::Absi32(int32 val) {
		if (val < 0) {
			return -val;
		}
		return val;
	}

}
