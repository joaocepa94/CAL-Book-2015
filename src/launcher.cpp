#include <iostream>
#include <vector>
#include "Book.h"
#include "FindBook.h"

using namespace std;

void printMenu(){

	cout << "--------- " << " Find the book" << " ---------" << endl << endl;
	cout << "	1. Play" << endl;
	cout << endl << "  Option (0 to exit) -> ";
}



int main()
{
	/*string input;

	do
	{

		printMenu();

		cin >> input;

	} while(input != "0");


	cout << endl << endl << "  Quitting program!" << endl;*/

	FindBook f = FindBook();

	vector<Book> books = f.getBooks();

	for(int i = 0; i < books.size(); i++){
		cout << books.at(i).getAuthor() << endl;
	}

	return 0;
}


