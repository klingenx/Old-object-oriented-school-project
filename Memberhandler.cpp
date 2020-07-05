#include "Memberhandler.h"
#include "Player.h"
#include "Leader.h"

MemberHandler::MemberHandler()
{
	this->capacity = 10;
	this->nrOfMembers = 0;
	this->members = new Member*[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		this->members[i] = nullptr;
	}
}

MemberHandler::MemberHandler(int capacity, int nrOfMembers)
{
	this->capacity = capacity;
	this->nrOfMembers = nrOfMembers;
	this->members = new Member*[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		this->members[i] = nullptr;
	}
}

//copyconstructor
MemberHandler::MemberHandler(const MemberHandler &rhs)
{
	this->nrOfMembers = rhs.nrOfMembers;
	this->capacity = rhs.capacity;
	this->members = new Member*[rhs.capacity];

	for (int i = 0; i < this->capacity; i++)
	{
		this->members[i] = nullptr;
	}

	for (int i = 0; i < this->nrOfMembers; i++)
	{
		if (typeid(Player) == typeid(rhs.members[i])) // Typeid för att identifiera objektet som pekaren har
		{
			this->members[i] = new Player(*(Player*)rhs.members[i]);
		}
		else
		{
			this->members[i] = new Leader(*(Leader*)rhs.members[i]);
		}
	}
}

// tilldelningsoperator
MemberHandler& MemberHandler::operator=(const MemberHandler &rhs)
{
	this->clearMemory();
	this->nrOfMembers = rhs.nrOfMembers;
	this->capacity = rhs.capacity;
	this->members = new Member*[rhs.capacity];

	for (int i = 0; i < this->capacity; i++)
	{
		this->members[i] = nullptr;
	}

	for (int i = 0; i < this->nrOfMembers; i++)
	{
		if (typeid(Player) == typeid(rhs.members[i]))  // Typeid för att identifiera objektet som pekaren har
		{
			this->members[i] = new Player(*(Player*)rhs.members[i]);
		}
		else
		{
			this->members[i] = new Leader(*(Leader*)rhs.members[i]);
		}
	}
	return *this;
}

//Destruktor
MemberHandler::~MemberHandler()
{
	//Avallokera alla players o leaders
	for (int i = 0; i < this->capacity; i++)
	{
		delete this->members[i];
	}
	//Avallokera hela arrayen
	delete[] this->members;
}



// Lägger till en Player
void MemberHandler::addPlayer(string name, int memberNr, string position, int shirtNr)
{
	if (this->nrOfMembers == this->capacity) //om de är fullt så expanderas arrayen
	{
		this->expandMembers();
	}

	this->members[this->nrOfMembers++] = new Player(name, memberNr, position, shirtNr);

	this->sortAll(); // Sorterar allt
}

// Lägger till en Leader
void MemberHandler::addLeader(string name, int memberNr, string mainResponseArea)
{
	if (this->nrOfMembers == this->capacity)  //om de är fullt så expanderas arrayen
	{
		this->expandMembers();
	}
	this->members[this->nrOfMembers++] = new Leader(name, memberNr, mainResponseArea);

	this->sortAll();  // Sorterar allt
}

void MemberHandler::showAll() const
{
	for (int i = 0; i < this->nrOfMembers; i++)
	{
		cout << this->members[i]->toString() << endl;
	}
}

//Funktionen visar alla Spelare
void MemberHandler::showAllPlayers() const
{
	for (int i = 0; i < nrOfMembers; i++)
	{
		if (dynamic_cast<Player*>(this->members[i]) != nullptr) //det är en player
		{
			cout << this->members[i]->toString() << endl;
		}
	}
}

//Funktionen visar alla Ledare
void MemberHandler::showAllLeaders() const
{
	for (int i = 0; i < nrOfMembers; i++)
	{
		if (dynamic_cast<Leader*>(this->members[i]) != nullptr)
		{
			cout << this->members[i]->toString() << endl;
		}
	}
}

//Expanderar arrayen
void MemberHandler::expandMembers()
{
	Member** temp = new Member*[this->capacity + this->capacity];

	for (int i = 0; i < this->nrOfMembers; i++) // kopierar de gamla
	{
		temp[i] = this->members[i];
	}

	for (int i = this->capacity; i < this->capacity * 2; i++)
	{
		temp[i] = nullptr;
	}

	this->capacity += this->capacity;

	delete[] this->members;
	this->members = temp;
}

//Funktionen hanterar hämtning och visning av tröjjnummer av ett specifikt namn
void MemberHandler::showMemberNr(string name)
{
	bool check;

	check = checkName(name);

	if (check == true)
	{
		for (int i = 0; i < nrOfMembers; i++)
		{
			if (this->members[i]->getName() == name)
			{
				cout << "Member number for " << name << " is " << this->members[i]->getMemberNr() << endl;
			}
		}
	}
	else
	{
		cout << "could not find name\n";
	}
}

// Funktioner hanterar ändring av tröjjnummer
void MemberHandler::changeShirtNr(string name, int nr)
{
	for (int i = 0; i < nrOfMembers; i++)
	{
		if (this->members[i]->getName() == name)
		{
			Player * pointer = nullptr; // gör en pekare
			pointer = dynamic_cast<Player *>(members[i]);

			if (pointer != nullptr)
			{
				pointer->setShirtNr(nr);
			}
		}
	}
}

// Funktion som kollar om angivet namn finns i arrayen
bool MemberHandler::checkName(string name)
{
	bool check = false;
	for (int i = 0; i < nrOfMembers; i++)
	{
		if (this->members[i]->getName() == name)
		{
			check = true;
		}
	}
	return check;
}

void MemberHandler::removeMember(string name)
{
	for (int i = 0; i < this->nrOfMembers; i++)
	{
		if (this->members[i]->getName() == name)
		{
			this->members[i] = this->members[--nrOfMembers];
		}
	}
}

// Funktionen sorterar alla objekt i members efter bokstavsordning
void MemberHandler::sortAll()
{
	Member * temp;
	int biggestValue;
	for (int i = this->nrOfMembers - 1; i > 0; i--)
	{
		biggestValue = 0;
		for (int k = 1; k <= i; k++)
		{
			if (members[k]->getName() > members[biggestValue]->getName())
			{
				biggestValue = k;
			}
		}
		temp = members[biggestValue];
		members[biggestValue] = members[i];
		members[i] = temp;
	}
}

void MemberHandler::clearMemory()
{
	//Avallokera alla players o leaders
	for (int i = 0; i < this->capacity; i++)
	{
		delete this->members[i];
	}
	//Avallokera hela arrayen
	delete[] this->members;
}