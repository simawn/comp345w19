#pragma once
#include "PlayerBot.h"
class PlayerBotAggressive : public PlayerBot
{
public:
	PlayerBotAggressive() : Player() {};
	PlayerBotAggressive(std::string colour) : Player(colour) {};
	~PlayerBotAggressive();
};

