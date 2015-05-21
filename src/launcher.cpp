#include <iostream>
#include <vector>

#include "Game.h"

using namespace std;

void printMenu() {
	cout << "------- GAME -------" << endl;
	cout << endl << "	1. play" << endl;
	cout << endl << " Option (0 to exit) -> " << endl;
}

int main() {
	string input;

	printMenu();

	do {
		cin >> input;
	} while (input != "1");

	Game *a = new Game();

	cout << endl << "Enter player: " << endl;
	string name;
	cin >> name;

	if(a->createPlayer(name)){
		cout << "Player created!" << endl;
	}


	string clue = a->generateClue();

	cout << clue << endl;

	a->sortPlayers();

	a->saveGame();

	return 0;
}

