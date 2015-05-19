#ifndef BOOK_H_
#define BOOK_H_

#include <string>

using namespace std;

class Book {
	string title;
	string author;
	int year;
public:
	Book(string ttl, string ath, int y) : title(ttl), author(ath), year(y){};

	string getTitle();
	string getAuthor();
	int getYear();

};



#endif /* BOOK_H_ */
