#pragma once
#include "Board.h"

class Stone
{
	protected:
		int m_player;
	public:
		virtual int CountTurnOver(int board[BOARD][BOARD], int player, int p, int q, int d, int e) = 0;
		virtual int IsLegalMove(int board[BOARD][BOARD],int player, int p, int q) = 0;
		virtual int ExistLegalMove(int board[BOARD][BOARD],int player) = 0;
		virtual void GetMove(int board[BOARD][BOARD], int player, int *p, int *q) = 0;
		virtual void SetAndTurnOver(int board[BOARD][BOARD], int player, int p, int q) = 0;
};