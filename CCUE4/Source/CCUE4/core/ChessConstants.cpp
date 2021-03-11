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

	FIntPoint ChessConstants::PieceIndexToPosition(int32 index) {
		if (index < 0 || index >= 100) {
			return IndexToPositionMap[99];
		}
		return IndexToPositionMap[index];
	}

	TArray<FIntPoint> ChessConstants::PieceInitPositions() {
		TArray<FIntPoint> ret;
		
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

		return ret;
	}

}
