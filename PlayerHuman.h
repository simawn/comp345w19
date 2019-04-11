#pragma once
#include "Player.h"
#include "GameMap.h"

class PlayerHuman :
	public Player
{
public:
	/*Default constructor for PlayerHuman*/
	PlayerHuman() : Player() {};

	/*Constructor taking a colour parameter for PlayerHuman
	@colour The colour of the player
	*/
	PlayerHuman(std::string colour) : Player(colour) {};

	/*Allows user console input. Parameters are ignored.*/
	int auctionDecision(Marketplace* marketplace, int turn);

	/*Pass action*/
	int pass();

	/*Auction action*/
	int auction();

	/*Allows user console input. Parameters are ignored*/
	int bidDecision(Marketplace* marketplace, Cards* card, int currentBid, int turn);
	
	/*Allows user console input. Parameters are ignored*/
	int resourceDecision(std::vector<std::vector<Resource*>> resourceMarket);
	
	/*Allows user console input. Parameters are ignored*/
	std::string resourceType();
	
	/*Allows user console input. Parameters are ignored*/
	int resourcePrice();
	
	/*Allows user console input. Parameters are ignored*/
	int resourceAmount();

	/*Allows user console input. Parameters are ignored*/
	int buildCityDecision(std::unordered_map<std::string, City*> cities);
	
	/*Allows user console input. Parameters are ignored*/
	std::string selectCity();

	/*Destructor for PlayerHuman*/
	~PlayerHuman() {};
};

