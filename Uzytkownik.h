#pragma once
#include "Ranga.h"
#include "Osiagniecia.h"
#include <string.h>
#include <iostream>
typedef unsigned long long int ogrom;

class Uzytkownik
{
private:
	std::string nick;
	std::string haslo;
	ogrom konto;
	Ranga R;
	Osiagniecia O;
	friend class Kosci;
	friend class Ruletka;
	friend class Gra;
public:
	Uzytkownik();
	void zapis(std::string, std::string, ogrom, ogrom, int);
	void zmien_haslo();
	ogrom sprawdz_stan_konta();
	void sprawdz_range();
	void sprawdz_osiagniecia();
	void zagraj(int);
};
