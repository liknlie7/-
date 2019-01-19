#pragma once
#include "Stone.h"

class WhiteStone : public Stone
{	
	public:
		WhiteStone();
		~WhiteStone();

		void SetBoard(int board) override;
		int CountStone() override;
};