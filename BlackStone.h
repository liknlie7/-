#pragma once
#include "Stone.h"

class BlackStone : public Stone
{
	private:
		int m_player;
	public:
		BlackStone();
		int CountTurnOver(int board[BOARD][BOARD], int player, int p, int q, int d, int e) override;
		int IsLegalMove(int board[BOARD][BOARD],int player, int p, int q)		override;
		int ExistLegalMove(int board[BOARD][BOARD], int player)					override;
		void GetMove(int board[BOARD][BOARD], int player, int *p, int *q)		override;
		void SetAndTurnOver(int board[BOARD][BOARD], int player, int p, int q)	override;
};