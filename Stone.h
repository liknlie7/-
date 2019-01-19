#pragma once
#include "Board.h"

class Stone
{
	protected:
		Board* m_board;
		int m_player;
		int m_num_stones;

	public:

		virtual void SetBoard(int board) = 0;
		virtual int CountStone() = 0;
};