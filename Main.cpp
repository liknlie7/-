#include <iostream>
#include "Game.h"
#include "Board.h"

#include <crtdbg.h>

using namespace std;

int main()
{
	//���������[�N�̌��o
	::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	Board* board = new Board();

	// �Ֆʂ̕\��
	board->DrawBoard();

	delete board;

	return 0;
}