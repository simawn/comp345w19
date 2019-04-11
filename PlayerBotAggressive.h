#pragma once
#include "PlayerBot.h"
class PlayerBotAggressive : public PlayerBot
{
public:
	/*Auction decision for Aggressive bot. The bot has a 90% chance of putting a powerplant on sale*/
	int auctionDecision(Marketplace* marketplace, int turn) override;
	/*Bid decision for Aggressive bot. The bot has a 95% of bidding +1 on the current bid*/
	int bidDecision(Marketplace* marketplace, Cards* card, int currentBid, int turn) override;
	/*Default constructor*/
	PlayerBotAggressive() : Player() {};
	/*Constructor taking a colour as parameter
	@param colour The colour of the bot
	*/
	PlayerBotAggressive(std::string colour) : Player(colour) {};
	
	/*Destructor*/
	~PlayerBotAggressive();
};

