#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Member
{
private:
	//Privata variabler
	string name;
	int memberNr;
public:
	Member(); // Default Konstruktor
	Member(string name, int memberNr); // Konstruktor
	Member(const Member &rhs); // Copykonstruktor
	virtual ~Member(); // Destruktor
	string getName() const;
	int getMemberNr() const;
	string toString() const;
	virtual string toStringSpec() const = 0; // Gör klassen absrakt
	
};