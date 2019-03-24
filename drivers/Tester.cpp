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
	for (int i = 0; i < players.size(); ++i) {
		cout << players[i].getPlayerColour() << endl;
	}
	selectMap();
	setUpStartingArea();
	
}

void testTurnOrder() {
	TurnManagerDriver();
}

void testBureaucracy() {
	cout << "\n === TESTING BUREAUCRACY ===\n";
	//doBureaucracy(setupMarketplace());
	cout << "\n === END TESTING BUREAUCRACY ===\n";
}

int step = 1; //should be moved into a game driver eventually.

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
	testTurnOrder();
	system("pause");
	return 0;
}
