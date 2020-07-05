#pragma once
#include "Member.h"

class Player : public Member // Ärver av member
{
private:
	//Privata variabler
	string position;
	int shirtNr;
public:
	Player(); // Default Konstruktor
	Player(string name, int memberNr, string position, int shirtNr); // Konstruktor
	Player(const Player &rhs); // Copykonstruktor
	virtual ~Player(); // Destruktor
	string getPosition() const;
	int getShirtNr() const;
	void setPosition(string position);
	string toStringSpec() const;
	void setShirtNr(int nr);

};