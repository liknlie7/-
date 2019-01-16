#include "Board.h"
#include <iostream>
using namespace std;

Board::Board()
{
	for (int i = 0; i < BOARD; i++)
		for (int j = 0; j < BOARD; j++)
			m_board[i][j] = BOARD_SURFACE;

	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			m_board[i][j] = NONE;

	m_board[4][5] = m_board[5][4] = BLACK_STONE;
	m_board[4][4] = m_board[5][5] = WHITE_STONE;
}

void Board::DrawBoard(int* m_board)
{
	cout << "    A     B     C     D     E     F     G     H   " << endl;
	cout << "  ----------------------------------------------- " << endl;

	for (int i = 1; i <= 8; i++)
	{
		cout << i << "|";
		for (int j = 1; j <= 8; j++)
		{
			switch (m_board[i][j])
			{
			case 1:
				cout << "  " << "œ" << " |";
				break;
			case 2:
				cout << "  " << "Z" << " |";
				break;
			default:
				cout << "   " << " " << " |";
				break;
			}
		}
			cout << "|" << endl;
		cout << "  ----------------------------------------------- " << endl;
	}
}

