#include "Osiagniecia.h"
using namespace std;

Osiagniecia::Osiagniecia()
{
	ilosc_wygranych=0;
	najwieksza_wygrana=0;
}

void Osiagniecia::zapis(ogrom ww, int ii)
{
	ilosc_wygranych=ii;
	najwieksza_wygrana=ww;
}

void Osiagniecia::sprawdz_wygrana(ogrom kk, int wygrane)
{
	ilosc_wygranych+=wygrane;
	if(najwieksza_wygrana<kk)
		najwieksza_wygrana=kk;
}

void Osiagniecia::pokaz_osiagniecia()
{
	cout<<"Do tej pory wygrales "<<ilosc_wygranych<<" razy"<<endl;
	cout<<"Twoja najwieksza wygrana to: "<<najwieksza_wygrana<<endl;
}
