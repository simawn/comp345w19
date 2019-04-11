#pragma once
#include "Player.h"
#include "GameMap.h"

class PlayerHuman :
	public Player
{
public:
	PlayerHuman() : Player() {};
	PlayerHuman(std::string colour) : Player(colour) {};
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

	~PlayerHuman() {};
};

