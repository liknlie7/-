#include "WhiteStone.h"
#include <iostream>
using namespace std;

WhiteStone::WhiteStone()
{
	m_board = new Board();
	m_player = 2;
	m_num_stones = 0;
}

WhiteStone::~WhiteStone()
{
	delete m_board;
}

void WhiteStone::SetBoard(int board)
{
	for (int i = 0; i < BOARD; i++)
		for (int j = 0; j < BOARD; j++)
			m_board->m_board[i][j] = board;
}

int WhiteStone::CountStone()
{
	int count = 0;

	for (int i = 0; i < BOARD; i++)
		for (int j = 0; j < BOARD; j++)
		{
			if (m_board->m_board[i][j] == 2)
				count++;
		}

	return count;

}