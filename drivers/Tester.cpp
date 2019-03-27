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
#include "AuctionStepDriver.h"
#include "CityBuilding.h"

using namespace std;

//Below are global variables that are used for bureaucracy test--
int step = 1;	//should be declared in a game driver eventually
Marketplace market = setupMarketplace();
vector<Player*> currentPlayers_;
GameMap map_;
//--


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
	Deck * d = new Deck();
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
		p.getSummaryCard().print();
		cout << "After purchase Elektro: " << p.getPlayersMoney()<<endl;
	}
}

void testTurnOrder() {
	cout << "\n === TESTING TURN ORDER ===\n";
	TurnManagerDriver();
	cout << "\n === END TESTING TURN ORDER ===\n";
}

void testAuction() {
	cout << "\n === TESTING AUCTION ===\n";
	testAuctionStep();
	cout << "\n === END TESTING AUCTION ===\n";
}

void testBureaucracy() {
	cout << "\n === TESTING BUREAUCRACY ===\nCreating a mock game-state...";
	//generates mock gamestate to test bureaucracy
	Player* pa = new Player("(pa) RED");
	Player* pc = new Player("(pc) GREEN");
	Player* pd = new Player("(pd) YELLOW");
	currentPlayers_.push_back(pa);
	currentPlayers_.push_back(pc);
	currentPlayers_.push_back(pd);
	//Powerplants
	Gas* g = new Gas(1);
	Coal* c = new Coal(1);
	Garbage* ga = new Garbage(1);
	Uranium* u = new Uranium(1);
	Cards* PowerPlantCard3 = new PowerPlant(3, 1, 2, g);
	Cards* PowerPlantCard4 = new PowerPlant(4, 1, 2, c);
	Cards* PowerPlantCard5 = new PowerPlant(5, 1, 2, g, c);
	Cards* PowerPlantCard6 = new PowerPlant(6, 1, 1, ga);
	Cards* PowerPlantCard7 = new PowerPlant(7, 2, 3, g);
	Cards* PowerPlantCard8 = new PowerPlant(8, 2, 3, c);
	Cards* PowerPlantCard9 = new PowerPlant(9, 1, 1, g);
	Cards* PowerPlantCard10 = new PowerPlant(10, 2, 2, c);

	//Cities
	City* c1 = new City("Montreal");
	City* c2 = new City("Toronto");
	City* c3 = new City("Calgary");
	City* c4 = new City("Vancouver");

	//Game begins
	std::cout << "Player (pa) buys PP3 and City 1" << std::endl;
	//Player a
	pa->buyPowerPlant((PowerPlant*)PowerPlantCard3);
	pa->buyCity(c1);
	pa->buyResources(g);
	std::cout << "Player (pc) buys City 2" << std::endl;
	//Player c
	pc->buyCity(c2);

	std::cout << "Player (pc) buys PowerPlant8" << std::endl;
	//Same amount of city but different powerplants
	pc->buyPowerPlant((PowerPlant*)PowerPlantCard8);
	pc->buyPowerPlant((PowerPlant*)PowerPlantCard6);
	pc->buyResources(c);
	pc->buyResources(c);
	std::cout << "Player (pd) buys City 3 and City 4" << std::endl;
	//Player d
	pd->buyCity(c3);
	pd->buyCity(c4);
	pd->buyPowerPlant((PowerPlant*)PowerPlantCard5);
	pd->buyResources(c);
	pd->buyResources(g);
	pd->buyResources(g);

	market.print();
	//end of mock setup

	cout << "\n === BEGIN BUREAUCRACY===\n";
	doBureaucracy();
	cout << "\n === out of bureaucracy===\n";
	market.print();
	cout << "\n === END TESTING BUREAUCRACY ===\n";

	//Deletes mock state
	currentPlayers_.pop_back();
	currentPlayers_.pop_back();
	currentPlayers_.pop_back();
	delete pa;
	delete pc;
	delete pd;
	delete PowerPlantCard3;
	delete PowerPlantCard4;
	delete PowerPlantCard5;
	delete PowerPlantCard6;
	delete PowerPlantCard7;
	delete PowerPlantCard8;
	delete PowerPlantCard9;
	delete PowerPlantCard10;
	delete c1;
	delete c2;
	delete c3;
	delete c4;
}

void testResourceBuying() {
	Phase3();
}
void testCityBuilding() {
	Phase4();
}

int main() {

	/*A2*/

	/*Part 1: Game start*/
	//testGameSetup();

	/*Part 2: Game play: main game loop Phase 1 and 2*/
	//testTurnOrder();
	//testAuction();

	/*Part 3: Game play: main game loop Phase 3 and 4*/
	//testResourceBuying();
	testCityBuilding();
	/*Part 4: Game play: main game loop Phase 5*/
	//testBureaucracy();

	/*Other tests*/
	//testMarketplaceCreation();

	system("pause");
	return 0;
}
