#pragma once
#include "Player.h"
class PlayerBotEnvironmentalist :
	public Player
{
public:
	PlayerBotEnvironmentalist();
	PlayerBotEnvironmentalist(std::string colour);
	~PlayerBotEnvironmentalist();
	void pass();
	void auction();
	void buyResource();
	void buildCity();
};

