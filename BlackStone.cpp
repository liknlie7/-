#include "BlackStone.h"
#include <iostream>
using namespace std;

BlackStone::BlackStone()
{
	m_player = 1;
}

int BlackStone::CountTurnOver(int board[BOARD][BOARD], int player, int p, int q, int d, int e)
{
	for (int i = 1; board[p + i * d][q + i * e] == 2; i++)
	{
		if (board[p + i * d][q + i * e] == player)
		{
			return i - 1;
		}
		else
		{
			return 0;
		}
	}
}

int BlackStone::IsLegalMove(int board[BOARD][BOARD], int player, int p, int q)
{
	if (p < 1 || p > 8 || q < 1 || q > 8)
		return 0;
	if (board[p][q] != 0)
		return 0;
	// 上
	if (CountTurnOver(board, player, p, q, -1, 0))
		return 1;
	// 下
	if (CountTurnOver(board, player, p, q, 1, 0))
		return 1;
	// 左
	if (CountTurnOver(board, player, p, q, 0, -1))
		return 1;
	// 右
	if (CountTurnOver(board, player, p, q, 0, 1))
		return 1;
	// 左上
	if (CountTurnOver(board, player, p, q, -1, -1))
		return 1;
	// 右上
	if (CountTurnOver(board, player, p, q, -1, 1))
		return 1;
	// 左下
	if (CountTurnOver(board, player, p, q, 1, -1))
		return 1;
	// 右下
	if (CountTurnOver(board, player, p, q, 1, 1))
		return 1;

	return 0;
}

int BlackStone::ExistLegalMove(int board[BOARD][BOARD], int player)
{
	for (int i = 1; i <= 8; i++) 
		for (int j = 1; j <= 8; j++) 
			if (IsLegalMove(board, player, i, j)) 
				return 1;
		
	return 0;
}

void BlackStone::GetMove(int board[BOARD][BOARD], int player, int *p, int *q)
{
	char str[100];

	cout << "Player " << player << " ";

	while (1) 
	{
		cout << "> ";
		fgets(str, sizeof(str), stdin);
		*q = str[0] - 'a' + 1;
		*p = str[1] - '1' + 1;
		if (IsLegalMove(board, player, *p, *q))
			return;
	}
}

void BlackStone::SetAndTurnOver(int board[BOARD][BOARD], int player, int p, int q)
{
	int count;

	for (int i = -1; i <= 1; i++) 
	{      // 上下方向 
		for (int j = -1; j <= 1; j++)
		{  // 左右方向 
			if (i == 0 && j == 0) 
				continue;

			count = CountTurnOver(board, player, p, q, i, j);
			for (int k = 1; k <= count; k++)
			{
				board[p + k * i][q + k * j] = player; // 裏返す
			}
		}
	}
	board[p][q] = player; // 石を置く
}