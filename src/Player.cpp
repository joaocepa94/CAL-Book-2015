
#include "Player.h"

Player::Player(string name) {
	this->name = name;
	this->score = 0;
}

string Player::getName(){
	return name;
}

int Player::getScore(){
	return score;
}

void Player::incrementScore(){
	score = score + 5;
}

void Player::decrementScore(){
	score = score - 1;
}
