#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Uzytkownik.h"
typedef unsigned long long int ogrom;

class Kosci
{
private:
	ogrom kasa;
	ogrom wygrana;
	int wygrane_partie;
public:
	Kosci(Uzytkownik &);
	void nowa_partia();
	void sprawdz_osiagniecia(Uzytkownik &);
	void zakoncz_gre(Uzytkownik &);
};
