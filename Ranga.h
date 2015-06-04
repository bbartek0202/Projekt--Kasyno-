#pragma once
#include "Osiagniecia.h"
#include <iostream>
#include <string.h>
typedef unsigned long long int ogrom;

class Ranga
{
private:
	int poziom;
	std::string nazwa;
	ogrom punkty;
	friend class Uzytkownik;
public:
	Ranga();
	void sprawdz_punkty(Osiagniecia &);
	void sprawdz();
	void pokaz();
};
