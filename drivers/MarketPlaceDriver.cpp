#include "../PowerPlant.h"
#include "../Marketplace.h"

/*
* Set up marketplace when the game board is initialized
* Due to the uniqueness of the set up
*/
void initializeMarketPlace(){
	Deck* deck = new Deck();
	Marketplace market(deck);
	market.print();
	market.remove(3);
	market.remove(4);
	market.remove(5);
	market.remove(6);
	market.print();
	delete deck;
}

Marketplace setupMarketplace() {
	Deck* deck = new Deck();
	Marketplace market(deck);
	//market.print();
	return market;
}
