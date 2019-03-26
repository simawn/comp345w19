#include "AuctionStepDriver.h"
#include "../Player.h"
#include "../Marketplace.h"
#include "../Auction.h"

void testAuctionStep() {
	//Player setup
	Player* pa = new Player("(pa) RED");
	Player* pb = new Player("(pb) BLUE");
	Player* pc = new Player("(pc) GREEN");
	Player* pd = new Player("(pd) YELLOW");
	std::vector<Player*> pv = {pa,pb,pc,pd};

	//Marketplace setup
	Deck* deck = new Deck();
	Marketplace* market = new Marketplace(deck);

	//Auction
	Auction auction(pv, market);

	//Show players possessions
	for (Player* player : pv) {
		std::cout << std::endl;
		player->printPlayerInfo();
		std::cout << std::endl;
	}

	//Deletes
	delete pa;
	delete pb;
	delete pc;
	delete pd;
	delete deck;
	delete market;
}