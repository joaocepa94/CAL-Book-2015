#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <vector>

using namespace std;

class Book {
	string title;
	string author;
	int year;
	vector<string> clues;
public:
	Book(string ttl, string ath, int y) : title(ttl), author(ath), year(y){};
	string getTitle();
	string getAuthor();
	int getYear();
	vector<string> getClues();
	void setTitle(string title1);
	void setAuthor(string author1);
	void setYear(int year1);
	void setClues(vector<string> clues);

};



#endif /* BOOK_H_ */
