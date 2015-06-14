#include "Achievements.h"
using namespace std;

Achievements::Achievements()
{
	ilosc_wygranych=0;
	najwieksza_wygrana=0;
}

void Achievements::record(ogrom ww, int ii)
{
	ilosc_wygranych=ii;
	najwieksza_wygrana=ww;
}

void Achievements::check_win(ogrom kk, int wygrane)
{
	ilosc_wygranych+=wygrane;
	if(najwieksza_wygrana<kk)
		najwieksza_wygrana=kk;
}

void Achievements::show_achievements()
{
	cout<<"Do tej pory wygrales "<<ilosc_wygranych<<" razy"<<endl;
	cout<<"Twoja najwieksza wygrana to: "<<najwieksza_wygrana<<endl;
}
