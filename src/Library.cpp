#include "Library.h"

using namespace std;

Library::Library() {
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

			/*vector<string> clues;

			for(int i = 3, j = 0; i < toRead.size(); i++,j++)
			{
				clues.at(j) = toRead.at(i);
			}*/

			Book b = Book(title, author, year);
			//b.setClues(clues);

			books.push_back(b);

		}

	} else {

		cout << "Error loading books.txt!" << endl;

	}
}


vector<Book> Library::getBooks(){
	return books;
}
