#pragma once
#include "User.h"
#include "Roulette.h"
#include "Yahtzee.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
typedef unsigned long long int ogrom;

class Game
{
private:
	static int ilosc;
public:
	Game(User *A);
	void record(User *A);
	int login(User *A);
	void menu(User *A, int);
};
