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

	if(!a->checkIfPlayerExist(name))
		a->createPlayer(name);

	string clue = a->generateClue();

	cout << clue << endl;

	cout << endl << "Give an answer: " << endl;

	string answer;

	cin >> answer;

	cout << a->numApproximateStringMatching(answer,"felizmente ha luar");

	a->saveGame();

	return 0;
}

