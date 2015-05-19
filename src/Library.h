#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdlib.h>

#include "Book.h"

using namespace std;

class Library {
	fstream booksFile;
	vector<Book> books;
public:
	Library();
	vector<Book> getBooks();

};

#endif /* LIBRARY_H_ */
