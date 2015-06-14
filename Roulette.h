#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "User.h"
typedef unsigned long long int ogrom;

class Roulette
{
private:
	ogrom kasa;
	ogrom wygrana;
	int wygrane_partie;
public:
	Roulette(User &);
	void new_game();
	void check_achievements(User &);
	void end_game(User &);
};
