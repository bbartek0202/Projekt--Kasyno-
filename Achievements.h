#pragma once
#include <iostream>
typedef unsigned long long int ogrom;

class Achievements
{
private:
	int ilosc_wygranych;
	ogrom najwieksza_wygrana;
	friend class Rank;
	friend class User;
	friend class Game;
public:
	Achievements();
	void record(ogrom, int);
	void check_win(ogrom, int);
	void show_achievements();
};
