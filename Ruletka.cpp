#include "Ruletka.h"
using namespace std;

Ruletka::Ruletka(Uzytkownik &A)
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
void Ruletka::nowa_partia()
{
int pomoc=1, liczba;
ogrom zaklad;
while(pomoc==1)
    {
	zaklad=0;
	liczba=0;
        cout<<"Najpierw wybierz liczbe na ktora chcesz postawic\nz przedzialu 0-34"<<endl;
        while(liczba>34 || liczba<0)
        {
            cin>>liczba;
            if(liczba>34 || liczba<0)
                cout<<"Podales liczbe z poza planszy, jeszcze raz"<<endl;
        }
		cout<<"A teraz wprowadz stawke: "<<endl;
        while(zaklad>kasa || zaklad<=0)
        {
            cin>>zaklad;
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
        cout<<"Chcesz zagrac jeszcze raz?"<<endl;
        cout<<"Jesli tak- 1"<<endl;
        cout<<"Jesli nie- 2"<<endl;
        while(pomoc<1 || pomoc>2)
        {
            cin>>pomoc;
            if(pomoc<1 || pomoc>2)
                cout<<"Wybrales zla opcje, jeszcze raz"<<endl;
        }
    }
}

void Ruletka::zakoncz_gre(Uzytkownik &A)
{
	A.konto+=kasa;
	cout<<"Twoj stan konta po grze w ruletke to: "<<A.konto<<endl;
}
void Ruletka::sprawdz_osiagniecia(Uzytkownik &A)
{
	A.O.sprawdz_wygrana(wygrana, wygrane_partie);
}
