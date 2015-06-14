#pragma once
#include "Rank.h"
#include "Achievements.h"
#include <string.h>
#include <iostream>
typedef unsigned long long int ogrom;

class User
{
private:
	std::string nick;
	std::string haslo;
	ogrom konto;
	Rank R;
	Achievements O;
	friend class Yahtzee;
	friend class Roulette;
	friend class Game;
public:
	User();
	void record(std::string, std::string, ogrom, ogrom, int);
	void change_password();
	ogrom check_account();
	void check_rank();
	void check_achievements();
	void play(int);
};
