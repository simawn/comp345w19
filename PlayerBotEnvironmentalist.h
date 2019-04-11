#pragma once
#include "PlayerBot.h"
#include <vector>

class PlayerBotEnvironmentalist : public PlayerBot {
	/*The array containing the ecological powerplants. PowerPlant 5 has been converted to green powerplant for testing purposes*/
	std::vector<int> cleanPP = { 5, 13, 18, 22, 27, 33, 37, 44, 50 };
	//std::vector<int> cleanPP = { 5, 8, 13, 18, 22, 27, 33, 37, 44, 50 }; //Powerplant 5, 8 added for testing purposes
public:
	/*Default ctor*/
	PlayerBotEnvironmentalist() : Player() {};
	/*ctor taking colour
	@param colour The colour of the bot
	*/
	PlayerBotEnvironmentalist(std::string colour) : Player(colour) {};
	
	/*Auction behaviour of environmentalist bot. It will always try to put a ecological powerplant in auction.
	If no ecological powerplant is in the current market. It reverts back to the PlayerBot behaviour
	*/
	int auctionDecision(Marketplace* marketplace, int turn) override;
	/* The bid behaviour of environmentalist bot. It will bid +1 with a 95% chance if the current auction is a clean powerplant.
	If the current bid is not a clean powerplant but there's a clean powerplant in the current market, it will always skip on the bid, hoping to bid on the environmental one later.
	If the current bid is not a clean powerplant and there are no clean powerplant in the current market, it will revert to the PlayerBot behaviour
	*/
	int bidDecision(Marketplace* marketplace, Cards* card, int currentBid, int turn) override;
	/*dtor*/
	~PlayerBotEnvironmentalist();
};

