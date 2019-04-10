#pragma once
#include "Player.h"
#include <string>

/*
This class contains the default behaviour of a bot, since not all of the behaviours have
been defined in the requirements.
By default all their choices will be random.
This is the parent class for other bot strategies.
The other bots may override some of the default behaviours
*/

class PlayerBot : virtual public Player {
public:
	PlayerBot() : Player() {};
	PlayerBot(std::string colour) : Player(colour) {};
	int auctionDecision(Marketplace* marketplace, int turn);
	int pass();
	int auction();
	int bidDecision(Cards* card, int currentBid, int turn);
	
	int resourceDecision();
	std::string resourceType();
	int resourcePrice();
	int resourceAmount();
	
	void buildCity();
	virtual ~PlayerBot();
};

