#include "Player.h"

Player::Player() : Member()
{
	this->position = "unknown";
	this->shirtNr = 0;
}

Player::Player(string name, int memberNr, string position, int shirtNr) : Member(name, memberNr) // anropar Member konstruktorn
{
	this->position = position;
	this->shirtNr = shirtNr;
}

Player::Player(const Player &rhs) : Member(rhs) // Anrop av members copykonstruktor
{
	this->position = rhs.position;
	this->shirtNr = rhs.shirtNr;
}

Player::~Player()
{

}

string Player::getPosition() const
{
	return this->position;
}

int Player::getShirtNr() const
{
	return this->shirtNr;
}

void Player::setPosition(string position)
{
	this->position = position;
}


// Funktionen nedanför returnerar en string
string Player::toStringSpec() const
{
	stringstream ss;
	ss << endl << "Position: " << this->position << endl <<
		"Shirt number: " << this->shirtNr;
	return ss.str();
}

void Player::setShirtNr(int nr)
{
	this->shirtNr = nr;
}
