#include "Roulette.h"
using namespace std;

Roulette::Roulette(User &A)
{
	int pomoc=0;
	cout<<"Posiadasz: "<<A.konto<<endl;
	cout<<"Podaj ile chcesz wniesc do gry: ";
while((A.konto)<kasa)
{
	if(pomoc>0)
	{
		cout<<"Podales wiecej niz masz na koncie, jeszcze raz: ";
	}	
	while(!(cin>>kasa))
	{
		cout<<"Nie podales liczby, jeszcze raz"<<endl;
  		cin.clear();
  		cin.ignore(1000,'\n');
	}
	pomoc++;
	wygrana=0;
	wygrane_partie=0;
}
A.konto-=kasa;
}
void Roulette::new_game()
{
int pomoc=1, liczba;
ogrom zaklad;
while(pomoc==1)
    {
	zaklad=0;
	liczba=-1;
        cout<<"Najpierw wybierz liczbe na ktora chcesz postawic\nz przedzialu 0-34"<<endl;
        while(liczba>34 || liczba<0)
        {
		while(!(cin>>liczba))
		{
			cout<<"Nie podales liczby, jeszcze raz"<<endl;
  			cin.clear();
  			cin.ignore(1000,'\n');
		}
            if(liczba>34 || liczba<0)
                cout<<"Podales liczbe z poza planszy, jeszcze raz"<<endl;
        }
		cout<<"A teraz wprowadz stawke: "<<endl;
        while(zaklad>kasa || zaklad<=0)
        {
		while(!(cin>>zaklad))
		{
			cout<<"Nie podales liczby, jeszcze raz"<<endl;
  			cin.clear();
  			cin.ignore(1000,'\n');
		}
            if(zaklad>kasa || zaklad<0)
                cout<<"Podales nieprawidlowa stawke, sproboj jeszcze raz"<<endl;

        }
		kasa-=zaklad;
        srand(time(NULL));
        cout<<"Rozpoczyna sie losowanie liczby"<<endl;
        int wylosowana=0;
        wylosowana=rand()%35;
        cout<<"Wyslosowana liczba to: "<<wylosowana<<endl;
        	if(liczba==wylosowana)
            {
                cout<<"Brawo wygrales i zgarniasz pule"<<endl;
				kasa+=2*zaklad;
				wygrane_partie++;
				if(2*zaklad>wygrana)
					wygrana=2*zaklad;
            }
        	else
            {
                cout<<"Niestety nie udalo ci sie trafic, bedzie lepiej"<<endl;
            }
		pomoc=0;
	cout<<"Stan konta w grze to: "<<kasa<<endl;
        cout<<"Chcesz zagrac jeszcze raz?"<<endl;
        cout<<"Jesli tak- 1"<<endl;
        cout<<"Jesli nie- 2"<<endl;
        while(pomoc<1 || pomoc>2)
        {
		while(!(cin>>pomoc))
		{
			cout<<"Nie podales liczby, jeszcze raz"<<endl;
  			cin.clear();
  			cin.ignore(1000,'\n');
		}
            if(pomoc<1 || pomoc>2)
                cout<<"Wybrales zla opcje, jeszcze raz"<<endl;
        }
    }
}

void Roulette::end_game(User &A)
{
	A.konto+=kasa;
	cout<<"Twoj stan konta po grze w ruletke to: "<<A.konto<<endl;
}
void Roulette::check_achievements(User &A)
{
	A.O.check_win(wygrana, wygrane_partie);
}
