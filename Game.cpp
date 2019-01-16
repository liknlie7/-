#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{

	m_black_stone = new BlackStone();
	m_white_stone = new WhiteStone();
}

Game::~Game()
{
	delete  m_black_stone, m_white_stone;
}

void Game::GameStart()
{
	while (1)
	{
		m_board->DrawBoard();





	//	if (m_black_stone->ExistLegalMove(m_board, m_black_stone))
	//	{
	//		printf("Player %d has no legal moves > pass\n", player);
	//		player = aite(player);
	//		if (!exist_legal_move(board, player)) {
	//			printf("Player %d has no legal moves > pass\n", player);
	//			break;
	//		}
	//	}
	//	get_move(board, player, &p, &q);
	//	set_and_turn_over(board, player, p, q);
	//	player = aite(player);
	//}
	//count_stone(board, &c1, &c2);
	//printf("Game Over\nPlayer 1 : %d\nPlayer 2 : %d\n", c1, c2);
	//return c1 - c2;
}


void Game::CountStone(int board[BOARD][BOARD], int *c1, int *c2)
{
	*c1 = 0;
	*c2 = 0;

	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			switch (board[i][j])
			{
			case 1:
				(*c1)++;
				break;
			case 2:
				(*c2)++;
				break;
			}
		}
	}
}