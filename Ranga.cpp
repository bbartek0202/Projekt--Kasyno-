#include "Ranga.h"
using namespace std;

Ranga::Ranga()
{
	poziom=1;
	punkty=0;
	nazwa="Amator";
}

void Ranga::sprawdz_punkty(Osiagniecia &A)
{
	punkty=A.najwieksza_wygrana+(ogrom(A.ilosc_wygranych));
}

void Ranga::sprawdz()
{
	poziom=punkty/1000+1;
	switch(poziom)
	{
	case 1:
		nazwa="Amator";
		break;
	case 2:
		nazwa="Poczatkujacy";
		break;
	case 3:
		nazwa="Doswiadczony gracz";
		break;
	case 4:
		nazwa="Zawodowiec";
		break;
	case 5:
		nazwa="Profesjonalista";
		break;
	case 6:
		nazwa="Klasa swiatowa";
		break;
	case 7:
		nazwa="Champion";
		break;
	default:
		nazwa="Legenda";
		break;
			
		
	}
}

void Ranga::pokaz()
{
	cout<<"Twoj poziom to: "<<poziom<<endl;
	cout<<"Masz range: "<<nazwa<<endl;
}
