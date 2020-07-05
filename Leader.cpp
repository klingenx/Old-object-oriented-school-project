#include "Leader.h"

Leader::Leader() : Member()
{
	this->mainResponseArea = "unknown";
}

Leader::Leader(string name, int memberNr, string mainResponseArea) : Member(name, memberNr) // anropa Member konstruktor
{
	this->mainResponseArea = mainResponseArea;
}

Leader::Leader(const Leader &rhs) : Member(rhs)
{
	this->mainResponseArea = rhs.mainResponseArea;
}

Leader::~Leader()
{

}

string Leader::getMainResponseArea() const
{
	return this->mainResponseArea;
}

string Leader::toStringSpec() const
{
	return "\nMain response area: " + this->mainResponseArea;
}

void Leader::setMainResponseArea(string mainResponseArea)
{
	this->mainResponseArea = mainResponseArea;
}