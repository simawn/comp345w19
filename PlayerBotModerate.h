#pragma once
#include "Player.h"
class PlayerBotModerate :
	public Player
{
public:
	PlayerBotModerate();
	PlayerBotModerate(std::string colour);
	~PlayerBotModerate();
	void pass();
	void auction();
	void buyResource();
	void buildCity();
};

