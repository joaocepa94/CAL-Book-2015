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
	void setTitle(string title1);
	void setAuthor(string author1);
	void setYear(int year1);

};



#endif /* BOOK_H_ */
