#include "Memberhandler.h"
#include <iostream>
#include <string>
#include <sstream>
#include <crtdbg.h>

using namespace std;

//Prototyper av funktionerna:
int menu();
void addPlayer(MemberHandler &a);
void addLeader(MemberHandler &a);
void showMemberNr(MemberHandler &a);
void changeShirtNr(MemberHandler &a);
void remove(MemberHandler &a);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int menuChoice = -1;
	MemberHandler a; // Skapar ett objekt

	//Menyn:
	while (menuChoice != 0)
	{
		menuChoice = menu();
		cin.ignore();
		system("cls");
		switch (menuChoice)
		{
		case 1:
			a.showAll();
			break;
		case 2:
			showMemberNr(a);
			break;
		case 3:
			changeShirtNr(a);
			break;
		case 4:
			a.showAllPlayers();
			break;
		case 5:
			a.showAllLeaders();
			break;
		case 6:
			addPlayer(a);
			break;
		case 7:
			addLeader(a);
			break;
		case 8:
			remove(a);
			break;
		case 0:
			break;
		default:
			cout << "Wrong input, try again\n";
			break;
		}
	}
	getchar();
	return 0;
}

int menu()
{
	int choice;
	cout << "1. Present all members\n";
	cout << "2. Present a member number of a member given its name\n";
	cout << "3. Change shirt number for a Player given its name\n";
	cout << "4. Present all Players with all related information\n";
	cout << "5. Present all Leaders with all related information\n";
	cout << "6. Add a Player\n";
	cout << "7. Add a Leader\n";
	cout << "8. Remoive a member given its name\n";
	cout << "0. Exit\n";
	cin >> choice;
	return choice;
}

void addPlayer(MemberHandler &a)
{
	string name, position;
	int memberNr, shirtNr;

	cout << "Name: ";
	getline(cin, name);
	cout << "Member number: ";
	cin >> memberNr;
	cin.ignore();
	cout << "Position: ";
	getline(cin, position);
	cout << "Shirt number: ";
	cin >> shirtNr;

	a.addPlayer(name, memberNr, position, shirtNr); // anropar MediaHandlers funktion för pekaren a och lägger till parametrarna
}

void addLeader(MemberHandler &a)
{
	string name, mainResponseArea;
	int memberNr;

	cout << "Name: ";
	getline(cin, name);
	cout << "Member number: ";
	cin >> memberNr;
	cin.ignore();
	cout << "Main response area: ";
	getline(cin, mainResponseArea);

	a.addLeader(name, memberNr, mainResponseArea); // anropar MediaHandlers funktion för pekaren a och lägger till parametrarna
}

void showMemberNr(MemberHandler &a)
{
	string name;
	cout << "Name: ";
	getline(cin, name);
	a.showMemberNr(name); // Anropar mediahandlers funktion för show
}

void changeShirtNr(MemberHandler &a)
{
	string name;
	int nr;
	bool check;
	cout << "Name: ";
	getline(cin, name);
	check = a.checkName(name); // kollar om namnet finns
	if (check == true)
	{
		cout << "Enter new shirt number: ";
		cin >> nr;
		a.changeShirtNr(name, nr);
		cout << "\nShirt number changed\n";
	}
	else
	{
		cout << "Could not the find name\n";
	}
}

void remove(MemberHandler &a)
{
	string name;
	bool check;
	cout << "Name: ";
	getline(cin, name);
	check = a.checkName(name); // Kollar om namnet finns
	if (check == true)
	{
		a.removeMember(name); // Anropar borttagningsfunktionen
		cout << name << " is now removed\n";
	}
	else
	{
		cout << "Could not the find name\n";
	}
}