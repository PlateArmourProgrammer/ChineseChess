#ifndef CC_CHESS_CONSTANTS_H_
#define CC_CHESS_CONSTANTS_H_

#include <Containers/Array.h>
#include <Math/IntPoint.h>

namespace cc {

	/*
		bc -- bm -- bx -- bs -- bj -- bs -- bx -- bm -- bc
		 |     |     |     |     |     |     |     |     |
		[] -- [] -- [] -- [] -- [] -- [] -- [] -- [] -- []
		 |     |     |     |     |     |     |     |     |
		[] -- bp -- [] -- [] -- [] -- [] -- [] -- bp -- []
		 |     |     |     |     |     |     |     |     |
		bb -- [] -- bb -- [] -- bb -- [] -- bb -- [] -- bb
		 |     |     |     |     |     |     |     |     |
		[] -- [] -- [] -- [] -- [] -- [] -- [] -- [] -- []
		==================================================
		[] -- [] -- [] -- [] -- [] -- [] -- [] -- [] -- []
		 |     |     |     |     |     |     |     |     |
		rb -- [] -- rb -- [] -- rb -- [] -- rb -- [] -- rb
		 |     |     |     |     |     |     |     |     |
		[] -- rp -- [] -- [] -- [] -- [] -- [] -- rp -- []
		 |     |     |     |     |     |     |     |     |
		[] -- [] -- [] -- [] -- [] -- [] -- [] -- [] -- []
		 |     |     |     |     |     |     |     |     |
		rc -- rm -- rx -- rs -- rj -- rs -- rx -- rm -- rc

		00 -- 01 -- 02 -- 03 -- 04 -- 05 -- 06 -- 07 -- 08
		 |     |     |     |     |     |     |     |     |
		10 -- 11 -- 12 -- 13 -- 14 -- 15 -- 16 -- 17 -- 18
		 |     |     |     |     |     |     |     |     |
		20 -- 21 -- 22 -- 23 -- 24 -- 25 -- 26 -- 27 -- 28
		 |     |     |     |     |     |     |     |     |
		30 -- 31 -- 32 -- 33 -- 34 -- 35 -- 36 -- 37 -- 38
		 |     |     |     |     |     |     |     |     |
		40 -- 41 -- 42 -- 43 -- 44 -- 45 -- 46 -- 47 -- 48
		==================================================
		50 -- 51 -- 52 -- 53 -- 54 -- 55 -- 56 -- 57 -- 58
		 |     |     |     |     |     |     |     |     |
		60 -- 61 -- 62 -- 63 -- 64 -- 65 -- 66 -- 67 -- 68
		 |     |     |     |     |     |     |     |     |
		70 -- 71 -- 72 -- 73 -- 74 -- 75 -- 76 -- 77 -- 78
		 |     |     |     |     |     |     |     |     |
		80 -- 81 -- 82 -- 83 -- 84 -- 85 -- 86 -- 87 -- 88
		 |     |     |     |     |     |     |     |     |
		90 -- 91 -- 92 -- 93 -- 94 -- 95 -- 96 -- 97 -- 98

		0---1----2----3----4----5----6----7----8----9----10---11---12---13---14---15
		bj, bs1, bs2, bx1, bx2, bm1, bm2, bc1, bc2, bp1, bp2, bb1, bb2, bb3, bb4, bb5
		16--17---18---19---20---21---22---23---24---25---26---27---28---29---30---31
		rj, rs1, rs2, rx1, rx2, rm1, rm2, rc1, rc2, rp1, rp2, rb1, rb2, rb3, rb4, rb5

		0--1--2--3--4--5--6
		j, s, x, m, c, p, b
	*/

	class ChessConstants {

	public:
		enum Side {
			RED,
			BLACK,
		};

		enum Type {
			JIANG,
			SHI,
			XIANG,
			MA,
			CHE,
			PAO,
			BING,
		};

	public:
		static FIntPoint PieceIndexToPosition(int32 index);

		static int32 PiecePositionToIndex(const int32 x, const int32 y);

		static const TArray<FIntPoint>& PieceInitPositions();

		static float GetVectorLength2D(FVector vec);

		static int32 IndexFromVectorPosition(const FVector target, const float scale);

		static int32 Absi32(int32 val);

	public:
		static const float PosScale;
	};

}

#define CC_MATH_ABSI32(val) (cc::ChessConstants::Absi32(val))

#endif
