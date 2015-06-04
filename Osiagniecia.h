#pragma once
#include <iostream>
typedef unsigned long long int ogrom;

class Osiagniecia
{
private:
	int ilosc_wygranych;
	ogrom najwieksza_wygrana;
	friend class Ranga;
	friend class Uzytkownik;
	friend class Gra;
public:
	Osiagniecia();
	void zapis(ogrom, int);
	void sprawdz_wygrana(ogrom, int);
	void pokaz_osiagniecia();
};
