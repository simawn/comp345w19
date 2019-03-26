#pragma once
#include "Player.h"
#include "Marketplace.h"
#include <vector>

class Auction {
	/*An array of the current players*/
	std::vector<Player*> currentPlayers;
	/*An array of the current auctioneers. Changes as auction goes on*/
	std::vector<Player*> auctioneers;
	/*An array of the current bidders. Changes as auction goes on*/
	std::vector<Player*> bidders;
	/*An array that keeps track of the next set of bidders, if one of them decides to pass*/
	std::vector<Player*> nextBidders;
	/*An array tracking bid winners*/
	std::vector<Player*> bidWinners;
	/*A pointer to the current marketplace*/
	Marketplace* marketplace;
	/*A map of the current market. Maps the PowerPlant cost to the Card*/
	std::map<int, Cards*> currentMarket;
	/*Maps an integer [0-3] to a Powerplant Card. Helps with user selection*/
	std::map<int, Cards*> choiceMapping;
	/*Start the auction*/
	void startAuction();
	/*cout the current market with user choice*/
	void displayCurrentMarketPowerPlants();
	/*updates the current market information*/
	void updateCurrentMarket();
	void printPotentialBidders();
	void printPotentialAuctioneers();
public:
	/*Auction ctor*/
	Auction(std::vector<Player*> players, Marketplace* marketplace);
};