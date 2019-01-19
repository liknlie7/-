#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	m_board = new Board();
	m_black_stone = new BlackStone();
	m_white_stone = new WhiteStone();
	player1 = 1;
	player2 = 2;
	row = 0;
	column = 0;
}

Game::~Game()
{
	delete   m_board, m_black_stone, m_white_stone;
}

void Game::GameStart()
{
	while (1)
	{

		// 盤面の表示
		m_board->DrawBoard(m_board);

		// 置ける場所があるか調べる
		if (!ExistLegalMove(player1))
		{
			cout << "Player" << player1 << " 置ける場所がありません > pass" << endl;
		}
		if (!ExistLegalMove(player2))
		{
			cout << "Player" << player2 << " 置ける場所がありません > pass" << endl;
		}
		if (!ExistLegalMove(player1) && !ExistLegalMove(player2))
			break;

		if (ExistLegalMove(player1))
		{
			// Player1:黒石------------------------------
			// 石を置く場所を決める
			GetMove(player1, &row, &column);
			// 石を置いて、挟んだ石を裏返す
			SetAndTurnOver(player1, row, column);

			// 盤面の表示
			m_board->DrawBoard(m_board);
		}
		if (ExistLegalMove(player2))
		{
			// Player2:白石------------------------------
			// 石を置く場所を決める
			GetMove(player2, &row, &column);
			// 石を置いて、挟んだ石を裏返す
			SetAndTurnOver(player2, row, column);
		}
	}

	// 盤面情報共有
	for (int i = 0; i < BOARD; i++)
		for (int j = 0; j < BOARD; j++)
		{
			m_black_stone->SetBoard(m_board->m_board[i][j]);
			m_white_stone->SetBoard(m_board->m_board[i][j]);
		}

	// 石の数を数える
	player1 = m_black_stone->CountStone();
	player2 = m_white_stone->CountStone();

	// 勝敗判定
	Judge(player1, player2);

}


int Game::CountTurnOver(int player, int row, int column, int updown, int rightleft)
{
	int i;

	for (i = 1; m_board->m_board[row + i * updown][column + i * rightleft] == 3 - player; i++)
	{
	};

	if (m_board->m_board[row + i * updown][column + i * rightleft] == player)
	{
		return i - 1;
	}
	else
	{
		return 0;
	}
}

int Game::IsLegalMove(int player, int row, int column)
{
	if (row < 1 || row > 8 || column < 1 || column > 8)
		return 0;
	if (m_board->m_board[row][column] != 0)
		return 0;
	// 上
	if (CountTurnOver(player, row, column, -1, 0))
		return 1;
	// 下
	if (CountTurnOver(player, row, column, 1, 0))
		return 1;
	// 左
	if (CountTurnOver(player, row, column, 0, -1))
		return 1;
	// 右
	if (CountTurnOver(player, row, column, 0, 1))
		return 1;
	// 左上
	if (CountTurnOver(player, row, column, -1, -1))
		return 1;
	// 右上
	if (CountTurnOver(player, row, column, -1, 1))
		return 1;
	// 左下
	if (CountTurnOver(player, row, column, 1, -1))
		return 1;
	// 右下
	if (CountTurnOver(player, row, column, 1, 1))
		return 1;

	return 0;
}

int Game::ExistLegalMove(int player)
{
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			if (IsLegalMove(player, i, j))
				return 1;

	return 0;
}

void Game::GetMove(int player, int *row, int *column)
{
	char str[100];

	if (player == 1)
		cout << "Player 1 黒石" << endl;

	if (player == 2)
		cout << "Player 2 白石" << endl;

	cout << "行列の順で入力　例：c4" << endl;

	// 置けない場所を選択されたらループ
	while (1)
	{
		cout << "> ";
		fgets(str, sizeof(str), stdin);
		*column = str[0] - 'a' + 1;
		*row = str[1] - '1' + 1;
		if (IsLegalMove(player, *row, *column))
			return;
	}
}

void Game::SetAndTurnOver(int player, int row, int column)
{
	int count;

	// 上下方向
	for (int i = -1; i <= 1; i++)
	{
		// 左右方向
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
				continue;

			count = CountTurnOver(player, row, column, i, j);
			for (int k = 1; k <= count; k++)
			{
				// 裏返す
				m_board->m_board[row + k * i][column + k * j] = player;
			}
		}
	}
	// 石を置く
	m_board->m_board[row][column] = player;
}

void Game::Judge(int p1, int p2)
{
	if (p1 > p2)
		cout << "Player1:黒石の勝ち！！" << endl;

	if (p1 < p2)
		cout << "Player2:白石の勝ち！！" << endl;

	if (p1 == p2)
		cout << "引き分けです" << endl;
}