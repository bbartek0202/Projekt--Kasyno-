#include "Kosci.h"
using namespace std;

Kosci::Kosci(Uzytkownik &A)
{
	int pomoc=0;
	cout<<"Podaj ile chcesz wniesc do gry: ";
while((A.konto)<kasa)
{
	if(pomoc>0)
	{
		cout<<"Podales wiecej niz masz na koncie, jeszcze raz: ";
	}	
	cin>>kasa;
	A.konto-=kasa;
	pomoc++;
	wygrana=0;
	wygrane_partie=0;
}
}

void Kosci::nowa_partia()
{
int pomoc=1, liczba=0;
ogrom zaklad=0;
while(pomoc==1)
{
	zaklad=0;
        cout<<"Jaka liczbe chcesz postawic z przedzialu 2-12"<<endl;
        while(liczba>12 || liczba<2)
        {
            cin>>liczba;
            if(liczba>12 || liczba<2)
                cout<<"Podales niepoprawny liczbe"<<endl;
        }
        cout<<"Teraz podaj ile chcesz postawic"<<endl;
        while(zaklad>kasa || zaklad<1)
        {
            cin>>zaklad;
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
        cout<<"Czy chcesz zagrac jeszcze raz?"<<endl;
        cout<<"Jesli tak- 1"<<endl;
        cout<<"Jesli nie- 2"<<endl;
        while(pomoc<1 || pomoc>2)
        {
            cin>>pomoc;
         	if(pomoc<1 || pomoc>2)
            	cout<<"Podales zla opcje, jeszcze raz"<<endl;
            
        }

}
}
void Kosci::zakoncz_gre(Uzytkownik &A)
{
	A.konto+=kasa;
	cout<<"Twoj stan konta po grze w kosci to: "<<A.konto<<endl;
}
void Kosci::sprawdz_osiagniecia(Uzytkownik &A)
{
	A.O.sprawdz_wygrana(wygrana, wygrane_partie);
}
