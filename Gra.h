#pragma once
#include "Uzytkownik.h"
#include "Ruletka.h"
#include "Kosci.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
typedef unsigned long long int ogrom;

class Gra
{
private:
	static int ilosc;
public:
	Gra(Uzytkownik *A);
	void zapis(Uzytkownik *A);
	int logowanie(Uzytkownik *A);
	void menu(Uzytkownik *A, int);
};
