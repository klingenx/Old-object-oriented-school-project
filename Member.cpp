#include "Member.h"

Member::Member()
{
	this->name = "unknown";
	this->memberNr = 0;
}

Member::Member(string name, int memberNr)
{
	this->name = name;
	this->memberNr = memberNr;
}

Member::Member(const Member &rhs)
{
	this->name = rhs.name;
	this->memberNr = rhs.memberNr;
}

Member::~Member()
{

}

string Member::getName() const
{
	return this->name;
}

int Member::getMemberNr() const
{
	return this->memberNr;
}

//Funktionen nedanför returnerar en string
string Member::toString() const
{
	stringstream ss;
	ss << "Name: " << this->name << "\nMember Number: " <<
		this->memberNr << toStringSpec() << endl;
	return ss.str();
}