#pragma once
#include "Player.h"
#include "GameMap.h"
#include <string>

/*
This class contains the default behaviour of a bot, since not all of the behaviours have
been defined in the requirements.
By default all their choices will be random.
This is the parent class for other bot strategies.
The other bots may override some of the default behaviours
*/

class PlayerBot : virtual public Player {
protected:
	/*Checks if the bot is done buying resources*/
	bool doneBuyingResource = false;
	std::string resourceTypeToBuy = "";
	int resourcePriceToPay = 0;
	int resourceAmountToBuy = 0;
	std::string cityToBuild = "";
	bool doneBuyingCities = false;
public:
	PlayerBot() : Player() {};
	PlayerBot(std::string colour) : Player(colour) {};
	int auctionDecision(Marketplace* marketplace, int turn);
	int pass();
	int auction();
	int bidDecision(Marketplace* marketplace, Cards* card, int currentBid, int turn);
	
	int resourceDecision(std::vector<std::vector<Resource*>> resourceMarket);
	std::string resourceType();
	int resourcePrice();
	int resourceAmount();
	
	int buildCityDecision(std::unordered_map<std::string, City*> cities);
	std::string selectCity();

	virtual ~PlayerBot() {};
};

