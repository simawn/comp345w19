#pragma once
#include "PlayerBot.h"
class PlayerBotAggressive : public PlayerBot
{
public:
	int auctionDecision(Marketplace* marketplace, int turn) override;
	int bidDecision(Cards* card, int currentBid, int turn) override;
	PlayerBotAggressive() : Player() {};
	PlayerBotAggressive(std::string colour) : Player(colour) {};
	~PlayerBotAggressive();
};

