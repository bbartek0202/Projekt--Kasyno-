#include "Uzytkownik.h"
#include "Gra.h"
#include "Ruletka.h"
#include "Kosci.h"
using namespace std;

int Gra::ilosc=0;

int main()
{
	int numer=0;
	Uzytkownik Wszyscy[1000], *Pomoc;
	Pomoc=Wszyscy;
	Gra G(Pomoc);
	cout<<"Witamy w kasynie"<<endl;
	numer = G.logowanie(Pomoc);
	G.menu(Pomoc, numer);
	G.zapis(Pomoc);
	
	return 0;
}
