#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Uzytkownik.h"
typedef unsigned long long int ogrom;

class Ruletka
{
private:
	ogrom kasa;
	ogrom wygrana;
	int wygrane_partie;
public:
	Ruletka(Uzytkownik &);
	void nowa_partia();
	void sprawdz_osiagniecia(Uzytkownik &);
	void zakoncz_gre(Uzytkownik &);
};
