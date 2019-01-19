#pragma once

static const int BOARD = 10;
static const int NONE = 0;
static const int BOARD_SURFACE = -1;
static const int BLACK_STONE = 1;
static const int WHITE_STONE = 2;

class Board
{
	public:
		int m_board[BOARD][BOARD];
	public:
		Board();
		void DrawBoard(Board* board);
};