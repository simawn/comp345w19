#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Money.h"
#include "House.h"
class Player{
private:
	Money* money;
	House* house;
public:
	Player(const char* c);
	int getPlayersMoney();
	const char* getPlayerColour();
};
#endif // !PLAYER_H
