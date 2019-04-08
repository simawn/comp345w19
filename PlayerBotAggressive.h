#pragma once
#include "Player.h"
class PlayerBotAggressive :
	public Player
{
public:
	PlayerBotAggressive();
	PlayerBotAggressive(std::string colour);
	~PlayerBotAggressive();
	void pass();
	void auction();
	void buyResource();
	void buildCity();
};

