#include <iostream>
#include "Game.h"
#include "Board.h"

#include <crtdbg.h>

using namespace std;

int main()
{
	//メモリリークの検出
	::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	Board* board = new Board();

	// 盤面の表示
	board->DrawBoard();

	delete board;

	return 0;
}