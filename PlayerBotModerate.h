#pragma once
#include "PlayerBot.h"
#include <string>

class PlayerBotModerate : public PlayerBot {
public:
	int resourceDecision(std::vector<std::vector<Resource*>> resourceMarket);
	std::string resourceType();
	int resourcePrice();
	int resourceAmount();

	PlayerBotModerate() : Player() {};
	PlayerBotModerate(std::string colour) : Player(colour) {};
	~PlayerBotModerate() {};
};

