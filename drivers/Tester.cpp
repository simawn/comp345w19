#include <iostream>
#include "GameDriver.h"
#include "GameMapDriver.h"
#include "GameMapLoaderDriver.h"
#include "CardCreationDriver.h"
#include "ResourcesLoaderDriver.h"
#include "../GameSetupDriver.h"
#include "MarketPlaceDriver.h"
#include "BureaucracyStepDriver.h"
#include "TurnManagerDriver.h"
#include "ResourceBuyingDriver.h"
#include "../Auction.h"

using namespace std;



void testPlayer(){
	cout << "\n === START TESTING PLAYER === \n";
	GameDriver();
	cout << "\n === END TESTING PLAYER === \n";
}

void testMap() {
	cout << "\n === START TESTING MAP  === \n";
	GameMapDriver();
	cout << "\n === END TESTING MAP  === \n";
}
void TestResourceLoader() {
	cout << "\n === TESTING RESOURCE LOADER === \n";
	resourceLoaderDriver();
	cout << "\n === END TESTING RESOURCE LOADER  === \n";
}
void testMapLoader() {
	cout << "\n === TESTING MAP LOADER === \n";
	GameMapLoaderDriver();
	cout << "\n === END MAP LOADER === \n";
}

void testCardCreation() {
	cout << "\n === TESTING CARD CREATION ===\n";
	//createDeckCards();
	//createDeckCardsSimple();
	cout << "\n === END TESTING CARD CREATION ===\n";
}

void testMarketplaceCreation() {
	cout << "\n === TESTING MARKETPLACE ===\n";
	initializeMarketPlace();
	cout << "\n === END TESTING MARKETPLACE ===\n";
}

// Have this part as a main game loop on a seperate file?
void testGameSetup() {
	vector<Player> players = setUpPlayers(); 
	GameMap gm =selectMap();
	setUpStartingArea();
	printResources();
	for (Player p :players) {
		cout <<"Current colour: "<< p.getPlayerColour() << endl;
		cout <<"Money: "<< p.getPlayersMoney() << endl;
		cout << "BUYS A SIMPLE GAS POWERPLANT" << endl;
		p.buyPowerPlant(new PowerPlant(1, 1, 1, &Gas(1)));
		p.getPowerPlants()[0]->print();
		p.buyResources(&Gas(1)); p.buyResources(&Coal(2));
		cout << "Owns resources: " << endl;
		for (Resource * r : p.getResources()) {
			cout <<"Type: "<<r->getName() << endl <<"Value: "<< r->getValue() << endl;
		}
		cout << "After purchase Elektro: " << p.getPlayersMoney()<<endl;
	}
}

void testTurnOrder() {
	TurnManagerDriver();
}

//Quick test
void testAuction() {
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

	//Deletes
	delete pa;
	delete pb;
	delete pc;
	delete pd;
	delete deck;
	delete market;
}

void testBureaucracy() {
	cout << "\n === TESTING BUREAUCRACY ===\n";
//	doBureaucracy();
	cout << "\n === out of bureaucracy===\n";
	market.print();
	cout << "\n === END TESTING BUREAUCRACY ===\n";
}
void testResourceBuying() {
	Phase3();
}

int step = 1; //should be moved into a game driver eventually.
Marketplace market = setupMarketplace(); //used for bureaucracy test

int main() {

	//step = 1;	//should be moved into a game driver eventually.


		//testMap(); //Part 1
		//testMapLoader(); //Part 2
		//TestResourceLoader(); //Part3
		//testPlayer(); //Part 4
		//testCardCreation(); //Part 5
	
	//testGameSetup();
	//testMarketplaceCreation();
	//testBureaucracy();
	//testTurnOrder();

	//testResourceBuying();
	testAuction();
	system("pause");
	return 0;
}
