#pragma once
#include "Player.h"
#include "Marketplace.h"
#include <vector>

class Auction {
	/**An array of the current players in the game*/
	std::vector<Player*> currentPlayers;
	/**An array of the current auctioneers. Updates as auction goes on*/
	std::vector<Player*> auctioneers;
	/**An array of the current bidders. Updates as auction goes on*/
	std::vector<Player*> bidders;
	/**An array that keeps track of the next set of bidders, if one of them decides to pass, they cannot participate in the current round of bid*/
	std::vector<Player*> nextBidders;
	/**An array tracking bid winners*/
	std::vector<Player*> bidWinners;
	/**A pointer to the current marketplace*/
	Marketplace* marketplace;
	/**A map of the current market. Maps the PowerPlant cost to the Card*/
	std::map<int, Cards*> currentMarket;
	/**Maps an integer [0-3] to a Powerplant Card. Helps with user selection*/
	std::map<int, Cards*> choiceMapping;
	/**Start the auction*/
	void startAuction();
	/**Prints the current market with user choice*/
	void displayCurrentMarketPowerPlants();
	/**Updates the current market information*/
	void updateCurrentMarket();
	/**Prints the list of potential bidders in the current round*/
	void printPotentialBidders();
	/**Prints the list of potential auctioneers in the current auction*/
	void printPotentialAuctioneers();
	/**Tracks the current turn #*/
	int turn;
public:
	/**Auction Constructor
	@param players An array of the current players participating in the auction
	@param marketplace A pointer to the current marketplace
	*/
	Auction(std::vector<Player*> players, Marketplace* marketplace, int turn);
};