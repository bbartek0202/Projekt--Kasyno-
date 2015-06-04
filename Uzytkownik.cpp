#include "Uzytkownik.h"
using namespace std;

Uzytkownik::Uzytkownik()
{
	nick="brak";
	haslo="brak";
	konto=0;
}

void Uzytkownik::zapis(string nn, string hh, ogrom kon, ogrom najwyg, int ilwyg)
{
	nick=nn;
	haslo=hh;
	konto=kon;
	O.zapis(najwyg, ilwyg);
	R.sprawdz_punkty(O);
	
}

void Uzytkownik::zmien_haslo()
{
for(int i=0;i<3;i++)
{
	string pomoc;
	cout<<"Podaj stare haslo: ";
	cin>>pomoc;
	if(pomoc==haslo)
	{
		string nhaslo, nhaslo2;
		cout<<"Podaj nowe haslo: ";
		cin>>nhaslo;
		cout<<"Potwierdz nowe haslo: ";
		cin>>nhaslo2;
		if(nhaslo==nhaslo2)
		{
			cout<<"Haslo zostalo zmienione"<<endl;
			haslo=nhaslo;
		}
	}
	else
		cout<<"Podales zle haslo, sproboj jeszcze raz"<<endl;
}	
}

ogrom Uzytkownik::sprawdz_stan_konta()
{
	return konto;
}

void Uzytkownik::sprawdz_range()
{
	R.pokaz();
}

void Uzytkownik::sprawdz_osiagniecia()
{
	O.pokaz_osiagniecia();
}
