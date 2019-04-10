#pragma once
#include "PlayerBot.h"
#include <vector>

class PlayerBotEnvironmentalist : public PlayerBot {
	//std::vector<int> cleanPP = { 13, 18, 22, 27, 33, 37, 44, 50 };
	std::vector<int> cleanPP = { 5, 8, 13, 18, 22, 27, 33, 37, 44, 50 }; //Powerplant 5, 8 added for testing purposes
public:
	PlayerBotEnvironmentalist() : Player() {};
	PlayerBotEnvironmentalist(std::string colour) : Player(colour) {};
	int auctionDecision(Marketplace* marketplace, int turn) override;
	int bidDecision(Cards* card, int currentBid, int turn) override;
	~PlayerBotEnvironmentalist();
};

