#include "BlackStone.h"
#include <iostream>
using namespace std;

BlackStone::BlackStone()
{
	m_board = new Board();
	m_player = 1;
	m_num_stones = 0;
}

BlackStone::~BlackStone()
{
	delete m_board;
}

void BlackStone::SetBoard(int board)
{
	for (int i = 0; i < BOARD; i++)
		for (int j = 0; j < BOARD; j++)
			m_board->m_board[i][j] = board;
}

int BlackStone::CountStone()
{
	int count = 0;

	for (int i = 0; i < BOARD; i++)
		for (int j = 0; j < BOARD; j++)
		{
			if (m_board->m_board[i][j] == 1)
				count++;
		}

	return count;

}