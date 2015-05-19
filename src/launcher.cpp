#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

void printMenu(){

	cout << endl << "--------- " << " Find the book" << " ---------" << endl << endl;
	cout << "	1. Play" << endl;
	cout << "	2. Top scores" << endl;
	cout << endl << "  Option (0 to exit) -> ";

}



int main()
{
	string input;

	do
	{

		printMenu();

		cin >> input;

	} while(input != "0");


	cout << endl << endl << "  Quitting program!" << endl;

	return 0;
}


