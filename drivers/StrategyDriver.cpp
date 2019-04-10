#include "StrategyDriver.h"
#include "../Player.h"
#include "../Marketplace.h"
#include "../Auction.h"
#include "../PlayerBotAggressive.h"
#include "../PlayerBotEnvironmentalist.h"
#include "../PlayerBotModerate.h"
#include "../PlayerHuman.h"
#include "../GameSetupDriver.h"

void StrategyDriver() {
	//Player setup

	Player* pa = new PlayerHuman("(pa) RED - HUMAN");
	Player* pb = new PlayerBotAggressive("(pb) BLUE - AGRESSIVE");
	Player* pc = new PlayerBotModerate("(pc) GREEN - MODERATE");
	Player* pd = new PlayerBotEnvironmentalist("(pd) YELLOW - ENVIRONMENTALIST");

	std::vector<Player*> pv = {pa,pb,pc,pd};

	//Map setup
	GameMap* gameMap = selectMap();

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