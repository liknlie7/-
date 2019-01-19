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

		// �Ֆʂ̕\��
		m_board->DrawBoard(m_board);

		// �u����ꏊ�����邩���ׂ�
		if (!ExistLegalMove(player1))
		{
			cout << "Player" << player1 << " �u����ꏊ������܂��� > pass" << endl;
		}
		if (!ExistLegalMove(player2))
		{
			cout << "Player" << player2 << " �u����ꏊ������܂��� > pass" << endl;
		}
		if (!ExistLegalMove(player1) && !ExistLegalMove(player2))
			break;

		if (ExistLegalMove(player1))
		{
			// Player1:����------------------------------
			// �΂�u���ꏊ�����߂�
			GetMove(player1, &row, &column);
			// �΂�u���āA���񂾐΂𗠕Ԃ�
			SetAndTurnOver(player1, row, column);

			// �Ֆʂ̕\��
			m_board->DrawBoard(m_board);
		}
		if (ExistLegalMove(player2))
		{
			// Player2:����------------------------------
			// �΂�u���ꏊ�����߂�
			GetMove(player2, &row, &column);
			// �΂�u���āA���񂾐΂𗠕Ԃ�
			SetAndTurnOver(player2, row, column);
		}
	}

	// �Ֆʏ�񋤗L
	for (int i = 0; i < BOARD; i++)
		for (int j = 0; j < BOARD; j++)
		{
			m_black_stone->SetBoard(m_board->m_board[i][j]);
			m_white_stone->SetBoard(m_board->m_board[i][j]);
		}

	// �΂̐��𐔂���
	player1 = m_black_stone->CountStone();
	player2 = m_white_stone->CountStone();

	// ���s����
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
	// ��
	if (CountTurnOver(player, row, column, -1, 0))
		return 1;
	// ��
	if (CountTurnOver(player, row, column, 1, 0))
		return 1;
	// ��
	if (CountTurnOver(player, row, column, 0, -1))
		return 1;
	// �E
	if (CountTurnOver(player, row, column, 0, 1))
		return 1;
	// ����
	if (CountTurnOver(player, row, column, -1, -1))
		return 1;
	// �E��
	if (CountTurnOver(player, row, column, -1, 1))
		return 1;
	// ����
	if (CountTurnOver(player, row, column, 1, -1))
		return 1;
	// �E��
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
		cout << "Player 1 ����" << endl;

	if (player == 2)
		cout << "Player 2 ����" << endl;

	cout << "�s��̏��œ��́@��Fc4" << endl;

	// �u���Ȃ��ꏊ��I�����ꂽ�烋�[�v
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

	// �㉺����
	for (int i = -1; i <= 1; i++)
	{
		// ���E����
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
				continue;

			count = CountTurnOver(player, row, column, i, j);
			for (int k = 1; k <= count; k++)
			{
				// ���Ԃ�
				m_board->m_board[row + k * i][column + k * j] = player;
			}
		}
	}
	// �΂�u��
	m_board->m_board[row][column] = player;
}

void Game::Judge(int p1, int p2)
{
	if (p1 > p2)
		cout << "Player1:���΂̏����I�I" << endl;

	if (p1 < p2)
		cout << "Player2:���΂̏����I�I" << endl;

	if (p1 == p2)
		cout << "���������ł�" << endl;
}