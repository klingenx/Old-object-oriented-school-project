#include "Memberhandler.h"
#include <iostream>
#include <string>
#include <sstream>
#include <crtdbg.h>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MemberHandler a, b;

	a.addLeader("Lars ola", 821, "CEO");
	a.addPlayer("Tim Lindstrom", 850, "Middle back", 6);
	a.addLeader("Nisse", 823, "CEO and ownder");
	a.addPlayer("Simon", 822, "Front", 14);
	a.addLeader("Marksimon", 842, "Keep the water filled");
	a.addLeader("Ollee", 825, "CEOaa");
	a.addPlayer("Simoefen", 812, "Front", 142);
	a.addPlayer("Simasefon", 822, "Front", 143);
	a.addPlayer("Simoasefn", 832, "Front", 144);
	a.addPlayer("Simoern", 842, "Front", 145);
	a.addPlayer("Simoen", 852, "Front", 146);
	a.addPlayer("Simogen", 862, "Front", 147);
	a.addPlayer("Simhon", 872, "Front", 148);
	a.addPlayer("Simohgn", 882, "Front", 149);
	a.addPlayer("Simdgon", 892, "Front", 150);
	a.addPlayer("Simjon", 122, "Front", 114);
	a.addPlayer("Simefaon", 222, "Front", 124);
	a.addPlayer("Simdgon", 322, "Front", 134);
	a.addPlayer("Simjon", 422, "Front", 144);
	a.addPlayer("Simjon", 522, "Front", 164);
	a.addPlayer("Sijmon", 622, "Front", 154);

	//Kopierar nedanför
	b = a;

	// Kollar så kopieringen var framgångsrik nedanför
	b.showAll();


	getchar();
	return 0;
}