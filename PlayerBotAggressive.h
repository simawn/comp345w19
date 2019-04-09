#pragma once
#include "PlayerBot.h"
class PlayerBotAggressive : public PlayerBot
{
public:
	int auctionDecision(Marketplace* marketplace) override;
	int bidDecision(Cards* card, int currentBid) override;
	PlayerBotAggressive() : Player() {};
	PlayerBotAggressive(std::string colour) : Player(colour) {};
	~PlayerBotAggressive();
};

