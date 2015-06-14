#include "User.h"
using namespace std;

User::User()
{
	nick="brak";
	haslo="brak";
	konto=0;
}

void User::record(string nn, string hh, ogrom kon, ogrom najwyg, int ilwyg)
{
	nick=nn;
	haslo=hh;
	konto=kon;
	O.record(najwyg, ilwyg);
	R.check_points(O);
	
}

void User::change_password()
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

ogrom User::check_account()
{
	return konto;
}

void User::check_rank()
{
	R.show();
}

void User::check_achievements()
{
	O.show_achievements();
}
