#ifndef FINDBOOK_H_
#define FINDBOOK_H_

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

#include "Book.h"


using namespace std;

class FindBook {
	fstream booksFile;
	vector<Book> books;
public:
	FindBook();
	vector<Book> getBooks();
};


#endif /* FINDBOOK_H_ */
