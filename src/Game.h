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
	Game();
	~Game(){};

	void loadInfoBooks();
	void loadInfoPlayers();

	vector<Player> getPlayers();
	vector<Book> getBooks();

	void saveGame();

	bool checkIfAnswerIsValid(string tittle, string answer);
	bool checkIfPlayerExist(string name);

	string generateClue(int positionBook);
	double numApproximateStringMatching(string input, string tittle);

	bool setScorePlayer(string name, int score);

	void createPlayer(string name);
	void sortPlayers();
};


#endif /* GAME_H_ */
