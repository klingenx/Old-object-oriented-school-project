#pragma once
#include "Member.h"

class MemberHandler
{
private:
	//Privata variabler
	Member** members; // Dubbelpekare
	int capacity;
	int nrOfMembers;
	void expandMembers(); // Expanderar arrayens kapacitet
	void clearMemory(); // Återlämnar minnet
public:
	MemberHandler(); // Default Konstruktor
	MemberHandler(int capacity, int nrOfMembers); // Konstruktor
	MemberHandler(const MemberHandler &rhs); // Copykonstruktor
	MemberHandler& operator=(const MemberHandler &rhs); // Tilldelnings operatoröverlagring
	virtual ~MemberHandler(); // Destruktor

	void addPlayer(string name, int memberNr, string position, int shirtNr);
	void addLeader(string name, int memberNr, string mainResponseArea);
	void showAll() const;
	void showAllPlayers() const;
	void showAllLeaders() const;
	void showMemberNr(string name);
	void changeShirtNr(string name, int nr);
	bool checkName(string name);
	void removeMember(string name);
	void sortAll();

};