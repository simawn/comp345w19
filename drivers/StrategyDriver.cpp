#include "StrategyDriver.h"
#include "../Player.h"
#include "../Marketplace.h"
#include "../Auction.h"
#include "../PlayerBotAggressive.h"
#include "../PlayerBotEnvironmentalist.h"
#include "../PlayerBotModerate.h"
#include "../PlayerHuman.h"
#include "../GameSetupDriver.h"
#include "../ResourceBuying.h"
#include "../CityBuilding.h"
#include "../TurnManager.h"

void StrategyDriver() {
	//Turn tracker
	int turn = 1;

	//Player setup - All aggressive for fun

	//Player* pa = new PlayerHuman("(pa) RED - HUMAN");
	Player* pa = new PlayerBot("(pa) RED - DEFAULT"); //for fun
	Player* pb = new PlayerBotAggressive("(pb) BLUE - AGRESSIVE");
	Player* pc = new PlayerBotModerate("(pc) GREEN - MODERATE");
	Player* pd = new PlayerBotEnvironmentalist("(pd) YELLOW - ENVIRONMENTALIST");

	std::vector<Player*> pv = { pa,pb,pc,pd };

	//Map + resource setup
	GameMap* gameMap = selectMap();

	//Marketplace setup
	Deck* deck = new Deck();
	Marketplace* market = new Marketplace(deck);

	//Game starts
	//while (true) {
		//if (turn == 17) break; //Game ends on turn 17?

		//Determine Turn Order - Phase 1
		determineOrder(&pv, turn == 1 ? true : false);

		//Auction - Phase 2
		Auction auction(pv, market, turn);
		showPlayersPossessions(pv);

		//Buy resources - Phase 3
		ResourceBuying(pv, gameMap, turn);
		showPlayersPossessions(pv);

		//Build cities - Phase 4
		CityBuilding(pv, gameMap, turn);
		showPlayersPossessions(pv);

		//Need to reset all flags for resourceBuying and cityBuilding
		//Increase turn
		//turn++;
	//}

	//Deletes
	delete pa;
	delete pb;
	delete pc;
	delete pd;
	delete deck;
	delete market;
	delete gameMap;
}

void showPlayersPossessions(std::vector<Player*> pv) {
	for (Player* player : pv) {
		std::cout << std::endl;
		player->printPlayerInfo();
		std::cout << std::endl;
	}
}