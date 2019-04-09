#pragma once
#include "PlayerBot.h"
class PlayerBotModerate : public PlayerBot {
public:
	PlayerBotModerate() : Player() {};
	PlayerBotModerate(std::string colour) : Player(colour) {};
	~PlayerBotModerate();
};

