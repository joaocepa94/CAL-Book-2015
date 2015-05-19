#include "Game.h"

using namespace std;


Game::Game()
{

	library = Library();
	books = library.getBooks();

}



bool Game::checkIfAnswerIsValid(string tittle, string answer)
{
	if(tittle == answer)
		return true;
	return false;

}


string Game::generateClue()
{
	int position = rand() % books.size() - 1;

	Book bookToSearch = books.at(position);


}
