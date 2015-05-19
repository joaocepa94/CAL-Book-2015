#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Book.h"
#include "Library.h"


using namespace std;

class Game {
	Library library;
	vector<Book> books;
private:
	Game();
	bool checkIfAnswerIsValid(string tittle, string answer);
	string generateClue();
};


#endif /* GAME_H_ */
