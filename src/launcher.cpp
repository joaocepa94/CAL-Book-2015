#include <iostream>
#include <vector>
#include <iomanip>

#include "Game.h"
#include "Book.h"
#include "Player.h"

using namespace std;

/*
 * Functions to print on console
 */

void clearConsole() {
	for (int i = 0; i < 50; i++) {
		cout << "\n" << endl;
	}
}

void printMenu() {
	cout << ".................................." << endl;
	cout << "	   Find The Book			" << endl;
	cout << ".................................." << endl;

	cout << endl;

	cout << "	1. New Game" << endl;
	cout << "	2. Top Scores" << endl;
	cout << "	3. My Top Score" << endl;

	cout << endl << "  Option (Press 0 to exit) -> ";
}

/*
 *
 */

void actionMenu(string input, Game *game) {

	if (input == "1") {

		clearConsole();

		cout << ".................................." << endl;
		cout << "	   Find The Book			" << endl;
		cout << ".................................." << endl;

		string name;

		cin.ignore();

		cout << endl << "	-> Please enter your name: ";
		getline(cin, name);

		vector<Player> players = game->getPlayers();

		bool exist = game->checkIfPlayerExist(name);

		if (!exist) {

			game->createPlayer(name);
			cout << endl << "	-> Player Created!" << endl << endl;

		} else {

			int scorePlayer = 0;

			for(int i = 0; i < players.size(); i++)
				if(players.at(i).getName() == name)
					scorePlayer = players.at(i).getScore();

			cout << endl << "	-> " << name
					<< " already exists! Try to beat your last score! -> " << scorePlayer << endl;
		}

		string start;
		while (start != "1") {
			cout << endl << "  Press 1 to start the game -> ";
			cin >> start;
		}

		string exit = "";
		int score = 0;

		cin.ignore();

		while (exit != "2") {

			srand(time(NULL));

			int positionBook = rand() % (game->getBooks().size() - 1);

			clearConsole();

			cout << endl << ".......... GAME ON .........." << endl;

			cout << endl << "Player: " << name << "		SCORE: " << score;

			cout << endl << endl << "  CLUE: "
					<< game->generateClue(positionBook) << endl;

			cout << endl << "  TITTLE (YOUR ANSWER): ";

			string answer = "";

			cin.clear();

			getline(cin, answer);

			vector<Book> books = game->getBooks();

			cout << endl << "  	Percentage of Matching -> "
					<< game->numApproximateStringMatching(answer,
							books.at(positionBook).getTitle()) << endl;

			if (game->numApproximateStringMatching(answer,
					books.at(positionBook).getTitle()) == 100.00) {
				score += 5;
				cout << endl << "	**YOU EARN 5 POINTS** ----- SCORE: " << score << endl;
			} else {
				cout << endl << "	**YOU LOST 1 POINT** ----- SCORE: "<< score  << endl;
				score--;
			}

			cout << endl << "............................................"
					<< endl;

			cout << endl << endl << " Continue - PRESS 1 || Give Up - PRESS 2"
					<< endl;
			cout << endl << "  Option -> ";

			cin.clear();
			getline(cin, exit);

		}

		game->setScorePlayer(name, score);

	} else if (input == "2") {

		string back;

		game->sortPlayers();

		vector<Player> players = game->getPlayers();

		clearConsole();

		cout << ".................................." << endl;
		cout << "	  TOP PLAYERS			" << endl;
		cout << ".................................." << endl;

		cout << endl << "	 NAME	" << "	 	SCORE	" << endl << endl;

		cout << "	1. " << players.at(players.size() - 1).getName() << "         	"  << players.at(players.size() - 1).getScore() << endl;
		cout << "	2. " << players.at(players.size() - 2).getName() << "         	" << players.at(players.size() - 2).getScore() <<endl;
		cout << "	3. " << players.at(players.size() - 3).getName() << "         	" <<  players.at(players.size() - 3).getScore() <<endl;

		while (back != "0") {
			cout << endl << "  Option (0 to go back) -> ";
			cin >> back;
		}

	} else if (input == "3") {

		clearConsole();

		cout << ".................................." << endl;
		cout << "	  MY TOP SCORE			" << endl;
		cout << ".................................." << endl;

		string name;

		cin.ignore();

		cout << endl << " Please, enter your name: ";
		getline(cin, name);

		vector<Player> players = game->getPlayers();

		bool exists = false;
		int position = 0;

		for (int i = 0; i < players.size(); i++) {
			if (players.at(i).getName() == name) {
				exists = true;
				position = i;
			}
		}

		if (exists)
			cout << endl << "	Your top score is "
					<< players.at(position).getScore() << "!" << endl;
		else
			cout << endl << "	Player does not exists!" << endl;

		string back;

		while (back != "0") {
			cout << endl << "  Option (0 to go back) -> ";
			cin >> back;
		}

	} else if (input == "0") {

		cout << endl << "	Quitting game!" << endl;

	} else {
		cout << endl << "	Invalid Input! Please Try Again!" << endl;
		cout << endl;
	}

}

int main() {
	string input;

	Game *game = new Game();

	do {

		clearConsole();

		printMenu();
		cin >> input;

		actionMenu(input, game);

	} while (input != "0");

	game->saveGame();

	return 0;
}

