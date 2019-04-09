#pragma once
#include "Player.h"
class PlayerHuman :
	public Player
{
public:
	PlayerHuman();
	PlayerHuman(std::string);
	~PlayerHuman();
	void pass();
	void auction();
	void buyResource();
	void buildCity();
};

