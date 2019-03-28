#pragma once
#include <map>
#include "Cards.h"
#include "Deck.h"
#include "PowerPlant.h"

class Marketplace {
	/**A map containing the cards in the market. Key: PowerPlant cost, Value: A pointer to the card. Using a map will ensure that the cards are ordered according to its cost. */
	std::map<int, Cards*> market;

	/**A pointer to the deck that is used*/
	Deck* deck;

public:
	/**Contructor for marketplace
	@param deck A pointer to the deck that is used
	*/
	Marketplace(Deck* deck);

	/**Inserts a new card to the market
	@param card A card from the deck
	*/
	void insert(Cards* card);

	/**Removes the card from the marketplace. In this function, the insert() function is immediatelty called after removing the card
	@param cost The cost of the PowerPlant that is being removed
	*/
	void remove(int cost);

	/**Prints the information about the marketplace*/
	void print();

	/**Returns a map containing all the cards in the marketplace*/
	std::map<int, Cards*> getMarket();

	/**Returns a map containing all the cards in the current market*/
	std::map<int, Cards*> getCurrentMarket();

	/**Returns a map containing all the cards in the future market*/
	std::map<int, Cards*> getFutureMarket();

	/**Prints the current market*/
	void printCurrentMarket();

	/**Prints the future market*/
	void printFutureMarket();

	/**Searches the marketplace for a PowerPlant cost and returns the specified card if found
	@param cost The cost of the PowerPlant
	*/
	Cards* getCard(int cost);
};