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
	/*Saves the resource the bot wants to buy*/
	std::string resourceTypeToBuy = "";
	/*Saves the grid number where the bot will buy the resource*/
	int resourcePriceToPay = 0;
	/*Saves the amount the bot wants to buy*/
	int resourceAmountToBuy = 0;
	/*Saves the city the bot wants to build*/
	std::string cityToBuild = "";
	/*Checks if the bot is done building cities*/
	bool doneBuyingCities = false;
public:
	/*Bot default constructor*/
	PlayerBot() : Player() {};
	/*Bot constructor taking a color as parameter*/
	PlayerBot(std::string colour) : Player(colour) {};
	/*Checks if the bot wants to participate in the auction or not
	@param marketplace A pointer to the current marketplace
	@param turn The current turn
	*/
	int auctionDecision(Marketplace* marketplace, int turn);
	/*Pass action*/
	int pass();
	/*Auction action*/
	int auction();
	/*Returns the amount the bot wishes to bid
	@param marketplace A pointer to the current marketplace
	@param card The current card in auction
	@param currentBid The current bid of the auction
	@param turn The current turn
	*/
	int bidDecision(Marketplace* marketplace, Cards* card, int currentBid, int turn);
	
	/*Checks if the bots would like to purchase a resource
	@param resourceMarket The current resourceMarket
	*/
	int resourceDecision(std::vector<std::vector<Resource*>> resourceMarket);
	/*Saves the resource the bot wishes to buy*/
	std::string resourceType();
	/*Saves the grid number to which the bot will buy the resource from*/
	int resourcePrice();
	/*Saves the amount of resources the bot wishes to buy*/
	int resourceAmount();
	
	/*Checks if the bots would like to build a city
	@param A map of all the cities in the map
	*/
	int buildCityDecision(std::unordered_map<std::string, City*> cities);
	/*Saves the city name the bot has selected*/
	std::string selectCity();

	/*Destructor for PlayerBot*/
	virtual ~PlayerBot() {};
};

