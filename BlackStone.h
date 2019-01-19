#pragma once
#include "Stone.h"

class BlackStone : public Stone
{
	public:
		BlackStone();
		~BlackStone();

		void SetBoard(int board) override;
		int CountStone() override;
};