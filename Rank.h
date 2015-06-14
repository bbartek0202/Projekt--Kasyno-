#pragma once
#include "Achievements.h"
#include <iostream>
#include <string.h>
typedef unsigned long long int ogrom;

class Rank
{
private:
	int poziom;
	std::string nazwa;
	ogrom punkty;
	friend class User;
public:
	Rank();
	void check_points(Achievements &);
	void check();
	void show();
};
