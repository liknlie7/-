#pragma once

#include "Board.h"
#include "BlackStone.h"
#include "WhiteStone.h"

class Game
{
	Board* m_board;
	BlackStone* m_black_stone;
	WhiteStone* m_white_stone;
	int player1;
	int player2;
	int row;
	int column;

	public:
		Game();
		~Game();
	void GameStart();
	int CountTurnOver(int player, int row, int column, int updown, int rightleft);
	int IsLegalMove(int player, int row, int column);
	int ExistLegalMove(int player);
	void GetMove(int plyaer, int *row, int *column);
	void SetAndTurnOver(int player, int row, int column);
	void Judge(int p1, int p2);

};