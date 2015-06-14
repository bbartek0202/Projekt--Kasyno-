#include "Rank.h"
using namespace std;

Rank::Rank()
{
	poziom=1;
	punkty=0;
	nazwa="Amator";
}

void Rank::check_points(Achievements &A)
{
	punkty=A.najwieksza_wygrana+(ogrom(A.ilosc_wygranych));
}

void Rank::check()
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

void Rank::show()
{
	cout<<"Twoj poziom to: "<<poziom<<endl;
	cout<<"Masz range: "<<nazwa<<endl;
}
