#include <iostream>
#include "Game.h"
#include "Board.h"

#include <crtdbg.h>

using namespace std;

int main()
{
	//メモリリークの検出
	::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);


	Game* othello;

	othello = new Game();

	othello->GameStart();


	return 0;
}