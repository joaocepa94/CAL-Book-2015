#include "Game.h"

using namespace std;

Game::Game() {

	booksFile.open("books.txt");
	playersFile.open("players.txt");

	string line;

	if (booksFile.is_open()) {

		while (!booksFile.eof()) {

			string line;
			getline(booksFile, line);

			istringstream ss(line);
			vector<string> toRead;

			while (ss) {

				string s;

				if (!getline(ss, s, ','))
					break;

				toRead.push_back(s);

			}

			string title = toRead[0];
			string author = toRead[1];
			int year = atoi(toRead[2].c_str());

			vector<string> clues;

			for (unsigned int i = 3; i < toRead.size(); i++) {
				clues.push_back(toRead.at(i));
			}

			Book b = Book(title, author, year);
			b.setClues(clues);

			books.push_back(b);

		}

	} else {
		cout << "Error loading books.txt!" << endl;
	}

	if (playersFile.is_open()) {

		while (playersFile.eof()) {
			string name;
			getline(playersFile, name);

			string scoreS;
			getline(playersFile, scoreS);

			int score = atoi(scoreS.c_str());

			Player player = Player(name, score);

			players.push_back(player);
		}

	} else {
		cout << "Error loading players.txt!" << endl;
	}

}

bool Game::checkIfAnswerIsValid(string tittle, string answer) {
	if (tittle == answer)
		return true;
	return false;

}

bool Game::checkIfPlayerExist(string name) {

	for (int i = 0; i < players.size(); i++)
		if (players.at(i).getName() == name)
			return true;

	return false;
}

string Game::generateClue() {
	int positionBook = rand() % books.size() - 1;

	Book bookToSearch = books.at(positionBook);

	int positionClue = rand() % bookToSearch.getClues().size() - 1;

	return (bookToSearch.getClues()[positionClue]);

}

float Game::numApproximateStringMatching(string input, string tittle) {
	float result = 0;

	return result;
}

void Game::createPlayer(string name){

	Player p = Player(name,0);
	players.push_back(p);

}
