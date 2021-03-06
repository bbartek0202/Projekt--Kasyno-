#include "Game.h"
using namespace std;

Game::Game(User *A)
{
	double konto, wygrana;
	int nr=0, pomoc=1, iwygrane;
	string linia, tab[5];
    fstream plik;
	plik.open("gamers.txt", ios::in);
    while(getline(plik,linia))
    {
        switch(pomoc)
        {
        case 1:
            {
                tab[0]=linia;
                pomoc=2;
            }break;
        case 2:
			{	
				tab[1]=linia;
				pomoc=3;
        	}break;
		case 3:
			{
                tab[2]=linia;
                pomoc=4;
            }break;
		case 4:
			{
				tab[3]=linia;
                pomoc=5;
			}break;
		case 5:
			{
				tab[4]=linia;
                pomoc=1;
				konto=atof(tab[2].c_str());
				wygrana=atof(tab[3].c_str());
				iwygrane=atoi(tab[4].c_str());
				A[nr].record(tab[0],tab[1],konto,wygrana,iwygrane);
				nr++;
			}break;
		}	    
	}
    plik.close();
	Game::ilosc+=(nr-1);
}
void Game::record(User *A)
{
	fstream plik;
    plik.open("gamers.txt", ios::out);
    for(int i=0;i<=ilosc;i++)
    {
        plik<<A[i].nick<<endl;
        plik<<A[i].haslo<<endl;
		plik<<A[i].konto<<endl;
		plik<<A[i].O.najwieksza_wygrana<<endl;
		plik<<A[i].O.ilosc_wygranych<<endl;
    }
    plik.close();
}

int Game::login(User *A)
{
	int logowanie, numer_gracza, pomoc=1;
	bool sprawdzenie;
	string logo, wpr_haslo;
	cout<<"Jesli chcesz sie zalogowac wcisnij- 1"<<endl;
    cout<<"Jesli chcesz sie zarejastrowac wcisnij- 2"<<endl;
    while(logowanie!=1 && logowanie!=2)
    {
        
	while(!(cin>>logowanie))
	{
		cout<<"Nie podales liczby, jeszcze raz"<<endl;
  		cin.clear();
  		cin.ignore(1000,'\n');
	}
        if(logowanie!=1 && logowanie!=2)
            cout<<"Podales zla operacje, jeszcze raz"<<endl;
    }
    if(logowanie==1)
    {
        cout<<"Podaj nazwe gracza na ktora chcesz sie zalogowa"<<endl;
        while(sprawdzenie==false)
        {
            if(pomoc==0)
            {
                cout<<"Taka nazwa gracza nie istnieje, sproboj jeszcze raz"<<endl;
            }
            cin>>logo;
            for(int i=0; i<=ilosc; i++)
            {
                if(A[i].nick==logo)
                {
					for(int j=0;j<3;j++)
					{
						if(j>0)
						{
							cout<<"Podales zle haslo, masz jeszcze "<<3-j<<" prob"<<endl;
						}
						cout<<"Podaj haslo: ";
						cin>>wpr_haslo;
						if(wpr_haslo==A[i].haslo)
							break;
					}
                    numer_gracza=i;
					sprawdzenie=true;
                    break;
                }
                else
                {
                    sprawdzenie=false;
                    pomoc=0;
                }

            }
        }
    }
    else if(logowanie==2)
    {
        bool pomoc=true;
    	string nick1;
    	cout<<"Podaj nick jakim chcesz sie poslugiwac w grze"<<endl;
    	while(pomoc==true)
    	{
        	if(pomoc==false)
        	{
            	cout<<"Taki nick juz istnieje, podaj inny"<<endl;
        	}
		
			cin>>nick1;
        
			for(int i=0; i<=ilosc; i++)
        	{
            	if(A[i].nick==nick1)
            	{
                	pomoc=true;
                	break;

            	}
            	else
            	{
                	pomoc=false;
            	}
        	}

    	}
		ilosc++;
		numer_gracza=ilosc;
		A[numer_gracza].nick=nick1;
		cout<<"Podaj haslo: ";
		cin>>A[numer_gracza].haslo;
    	cout<<"Podaj ile chcesz wniesc do gry"<<endl;
    	cin>>A[numer_gracza].konto;
		A[numer_gracza].O.record(0,0);
		A[numer_gracza].R.check();
    }
	return numer_gracza;
}

void Game::menu(User *A, int numer)
{
	int opcja=0, zakoncz=0, rodzaj_gry=0;
	while(zakoncz!=2)
	{	
			opcja=0;
			zakoncz=0;
			rodzaj_gry=0;
			cout<<"Wybierz co chcesz zrobic"<<endl;
        	cout<<"Jesli chcesz zagrac wcisnij- 1"<<endl;
        	cout<<"Jesli chcesz obejrzec osiagniecia wcisnij- 2"<<endl;
        	while(opcja!=1 && opcja!=2)
        	{
			while(!(cin>>opcja))
			{
				cout<<"Nie podales liczby, jeszcze raz"<<endl;
  				cin.clear();
  				cin.ignore(1000,'\n');
			}
            		if(opcja!=1 && opcja!=2)
                		cout<<"Podales zla opcje, jeszcze raz"<<endl;
        	}
        	if(opcja==1)
        	{
				cout<<"Wybierz w jaka gre chcesz zagrac"<<endl;
            	cout<<"Jesli w ruletke wcisnij- 1"<<endl;
            	cout<<"Jesli w kosci wcisnij- 2"<<endl;
            	while(rodzaj_gry!=1 && rodzaj_gry!=2)
            	{
			while(!(cin>>rodzaj_gry))
			{
				cout<<"Nie podales liczby, jeszcze raz"<<endl;
  				cin.clear();
  				cin.ignore(1000,'\n');
			}
                	if(rodzaj_gry!=1 && rodzaj_gry!=2)
                    	cout<<"Podales zla opcje, jeszcze raz"<<endl;
            	}
				switch(rodzaj_gry)
				{
					case 1:
						{
							Roulette RR(A[numer]);
							RR.new_game();
							RR.check_achievements(A[numer]);
							RR.end_game(A[numer]);
						}break;
					case 2:
						{
							Yahtzee KK(A[numer]);
							KK.new_game();
							KK.check_achievements(A[numer]);
							KK.end_game(A[numer]);
						}break;
				}
				
			}
			else if(opcja==2)
        	{
				A[numer].O.show_achievements();
			}
			cout<<"Jesli chcesz zagrac w inna gre lub zobaczyc najlepsze wyniki wcisnij-1"<<endl;
        	cout<<"Jesli chcesz zakonczyc gre wcisnij- 2"<<endl;
        	while(zakoncz!=1 && zakoncz!=2)
        	{
		while(!(cin>>zakoncz))
		{
			cout<<"Nie podales liczby, jeszcze raz"<<endl;
  			cin.clear();
  			cin.ignore(1000,'\n');
		}
            	if(zakoncz!=1 && zakoncz!=2)
                	cout<<"Podales zla opcje, jeszcze raz"<<endl;
            	
		}
	}
}
