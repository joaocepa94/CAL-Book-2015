#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <time.h>
#include <algorithm>

#include "Book.h"
#include "Player.h"


using namespace std;

class Game {
	fstream booksFile;
	fstream playersFile;
	vector<Player> players;
	vector<Book> books;
public:
	~Game(){};
	Game();
	bool checkIfAnswerIsValid(string tittle, string answer);
	bool checkIfPlayerExist(string name);
	string generateClue();
	float numApproximateStringMatching(string input, string tittle);
	bool createPlayer(string name);
	void sortPlayers();
	void saveGame();
};


#endif /* GAME_H_ */
