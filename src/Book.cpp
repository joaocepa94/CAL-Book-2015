#include "Book.h"

using namespace std;

string Book::getTitle(){
	return title;
}

string Book::getAuthor(){
	return author;
}

int Book::getYear(){
	return year;
}

void Book::setTitle(string title){
	this->title = title;
}

void Book::setAuthor(string author){
	this->author=author;
}

void Book::setYear(int year){
	this->year=year;
}


