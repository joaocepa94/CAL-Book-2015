#include <iostream>
#include <vector>

#include "Game.h"


using namespace std;


int main()
{

	Game *a = new Game();
	a->sortPlayers();
	a->saveGame();
	return 0;
}


