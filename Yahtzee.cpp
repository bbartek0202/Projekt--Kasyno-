#include "Yahtzee.h"
using namespace std;

Yahtzee::Yahtzee(User &A)
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
	A.konto-=kasa;
	pomoc++;
	wygrana=0;
	wygrane_partie=0;
}
}

void Yahtzee::new_game()
{
int pomoc=1, liczba=0;
ogrom zaklad=0;
while(pomoc==1)
{
	zaklad=0;
	liczba=0;
        cout<<"Jaka liczbe chcesz postawic z przedzialu 2-12"<<endl;
        while(liczba>12 || liczba<2)
        {
		while(!(cin>>liczba))
		{
			cout<<"Nie podales liczby, jeszcze raz"<<endl;
  			cin.clear();
  			cin.ignore(1000,'\n');
		}
            if(liczba>12 || liczba<2)
                cout<<"Podales niepoprawny liczbe"<<endl;
        }
        cout<<"Teraz podaj ile chcesz postawic"<<endl;
        while(zaklad>kasa || zaklad<1)
        {
		while(!(cin>>zaklad))
		{
			cout<<"Nie podales liczby jeszcze raz"<<endl;
  			cin.clear();
  			cin.ignore(1000,'\n');
		}
            if(zaklad>kasa || zaklad<1)
                cout<<"Podales zla kwote, jeszcze raz"<<endl;
        }
        kasa-=zaklad;
        int k1=0, k2=0, wynik=0;
        cout<<"Nastepuje rzut kostka"<<endl;
        k1= rand()%6+1;
        k2= rand()%6+1;
        cout<<"Wylosowane liczby to: "<<k1<<", "<<k2<<endl;
        wynik= k1+k2;
        cout<<"Suma oczek to: "<<wynik<<endl;
        if(wynik==liczba)
        {
            cout<<"Wygrales, brawo"<<endl;
            kasa+=2*zaklad;
			wygrane_partie++;
			if(2*zaklad>wygrana)
				wygrana=2*zaklad;
        }
        else
        {
            cout<<"Niestety nie udalo ci sie wygrac"<<endl;
        }
		pomoc=0;
	cout<<"Stan konta w grze to: "<<kasa<<endl;
        cout<<"Czy chcesz zagrac jeszcze raz?"<<endl;
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
            	cout<<"Podales zla opcje, jeszcze raz"<<endl;
            
        }

}
}
void Yahtzee::end_game(User &A)
{
	A.konto+=kasa;
	cout<<"Twoj stan konta po grze w kosci to: "<<A.konto<<endl;
}
void Yahtzee::check_achievements(User &A)
{
	A.O.check_win(wygrana, wygrane_partie);
}
