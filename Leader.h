#pragma once
#include "Member.h"

class Leader : public Member // Ärver av member
{
private:
	//Privat variabel
	string mainResponseArea;
public:
	Leader(); // Default Konstruktor
	Leader(string name, int memberNr, string mainResponseArea); // Konstruktor
	Leader(const Leader &rhs); // Copykonstruktor
	virtual ~Leader(); // Destruktor
	string getMainResponseArea() const;
	string toStringSpec() const;
	void setMainResponseArea(string mainResponseArea);
};