#include "Player.h"


Player::Player(string name, int score)
{
	this->name = name;
	this->score = score;
}

string Player::getName()
{
	return name;
}

int Player::getScore()
{
	return score;
}

void Player::incrementScore()
{
	score = score + 5;
}

void Player::decrementScore()
{
	score = score - 1;
}
