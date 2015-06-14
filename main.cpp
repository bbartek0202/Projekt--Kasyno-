#include "User.h"
#include "Game.h"
#include "Roulette.h"
#include "Yahtzee.h"
using namespace std;

int Game::ilosc=0;

int main()
{
	int numer=0;
	User Wszyscy[1000], *Pomoc;
	Pomoc=Wszyscy;
	Game G(Pomoc);
	cout<<"Witamy w kasynie"<<endl;
	numer = G.login(Pomoc);
	G.menu(Pomoc, numer);
	G.record(Pomoc);
	
	return 0;
}
