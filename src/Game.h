#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <time.h>

#include "Book.h"


using namespace std;

class Game {
	fstream booksFile;
	vector<Book> books;
private:
	Game();
	bool checkIfAnswerIsValid(string tittle, string answer);
	string generateClue();
	float numApproximateStringMatching(string input, string tittle);
};


#endif /* GAME_H_ */
