#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Money.h"
#include "House.h"
#include "Resources.h"
class Player{
private:
	Money* money;
	House* house;
	Resource* resource;
public:
	Player(const char* c);
	int getPlayersMoney();
	const char* getPlayerColour();
	void pay(int amount);
	void destroy();
	Resource * getResources();
	bool buyResources(Resource * res);

};
#endif // !PLAYER_H
