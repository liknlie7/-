#pragma once

static const int BOARD_SIZE = 10;
static const int NONE = 0;
static const int BOARD_SURFACE = -1;
static const int BLACK_STONE = 1;
static const int WHITE_STONE = 2;

class Board
{
	private:
		int m_board[BOARD_SIZE][BOARD_SIZE];

	public:
		Board();
		~Board();
		void DrawBoard();
};