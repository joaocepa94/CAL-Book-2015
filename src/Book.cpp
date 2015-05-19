#include "Book.h"

using namespace std;

string Book::getTitle()
{
	return title;
}

string Book::getAuthor()
{
	return author;
}

int Book::getYear()
{
	return year;
}

vector<string> Book::getClues()
{
	return clues;
}

void Book::setTitle(string title)
{
	this->title = title;
}

void Book::setAuthor(string author)
{
	this->author=author;
}

void Book::setYear(int year)
{
	this->year=year;
}

void Book::setClues(vector<string> clues)
{
	this->clues = clues;
}


