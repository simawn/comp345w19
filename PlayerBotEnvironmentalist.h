#pragma once
#include "PlayerBot.h"
class PlayerBotEnvironmentalist : public PlayerBot {
public:
	/**Only buy powerplants that are renewable otherwise don't buy*/
	int auctionDecision(Marketplace* marketplace) override;
	int bidDecision(Cards* card, int currentBid) override;
	PlayerBotEnvironmentalist() : Player() {};
	PlayerBotEnvironmentalist(std::string colour) : Player(colour) {};
	~PlayerBotEnvironmentalist();
};

