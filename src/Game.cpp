#include "Game.h"

using namespace std;

Game::Game() {

	loadInfoBooks();
	loadInfoPlayers();

}

void Game::loadInfoBooks() {

	booksFile.open("books.txt");

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

	} else
		cout << "Error loading books.txt!" << endl;

	booksFile.close();

}

void Game::loadInfoPlayers() {

	playersFile.open("players.txt");

	if (playersFile.is_open()) {

		while (!playersFile.eof()) {
			string line;
			getline(playersFile, line);

			if (line == "")
				break;

			istringstream ss(line);
			vector<string> toRead;

			while (ss) {

				string s;

				if (!getline(ss, s, ','))
					break;

				toRead.push_back(s);

			}

			Player player = Player(toRead[0], atoi(toRead[1].c_str()));

			players.push_back(player);
		}

	} else
		cout << "Error loading players.txt!" << endl;

	playersFile.close();

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

	srand(time(NULL));

	int positionBook = rand() % (books.size() - 1);

	Book bookToSearch = books.at(positionBook);

	srand(time(NULL));

	int positionClue = rand() % (bookToSearch.getClues().size() - 1);

	return (bookToSearch.getClues()[positionClue]);

}

float Game::numApproximateStringMatching(string input, string tittle) {

	int n = tittle.length();
	vector<int> d(n + 1);
	int old, neww;
	for (int j = 0; j <= n; j++)
		d[j] = j;
	int m = input.length();

	for (int i = 1; i <= m; i++) {
		old = d[0];
		d[0] = i;
		for (int j = 1; j <= n; j++) {
			if (tittle[i - 1] == tittle[j - 1])
				neww = old;
			else {
				neww = min(old, d[j]);
				neww = min(neww, d[j - 1]);
				neww = neww + 1;
			}
			old = d[j];
			d[j] = neww;
		}
	}

	return d[n];
}

void Game::createPlayer(string name) {

	Player p = Player(name, 0);
	players.push_back(p);

}

void Game::sortPlayers() {
	sort(players.begin(), players.end());
}

void Game::saveGame() {

	//	Put in players.txt the new information

	cout << "Size: " << players.size() << endl;

	playersFile.open("players.txt", std::ofstream::out | std::ofstream::trunc);

	if (playersFile.is_open())
		for (int i = 0; i < players.size(); i++)
			playersFile << players[i].getName() << "," << players[i].getScore()
					<< "," << endl;
	else
		cout << endl << "Error while saving scores!" << endl;

}

