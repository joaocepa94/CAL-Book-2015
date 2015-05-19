#include <iostream>
#include <vector>
#include "Book.h"
#include "Library.h"

using namespace std;

void printMenu(){

	cout << "--------- " << " Find the book" << " ---------" << endl << endl;
	cout << "	1. Play" << endl;
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


