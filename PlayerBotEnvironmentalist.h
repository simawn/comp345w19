#pragma once
#include "PlayerBot.h"
class PlayerBotEnvironmentalist : public PlayerBot {
public:
	PlayerBotEnvironmentalist() : Player() {};
	PlayerBotEnvironmentalist(std::string colour) : Player(colour) {};
	~PlayerBotEnvironmentalist();
};

