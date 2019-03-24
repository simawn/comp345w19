#include "../TurnManager.h"
#include "../Player.h"
#include "../PowerPlant.h"
#include "../Gas.h"
#include "../Coal.h"
#include "../Garbage.h"
#include "../Uranium.h"
#include <vector>

void printPlayerArray(std::vector<Player*> a) {
	std::cout << "\n=== START PLAYER ORDER ===" << std::endl;
	for (Player* player : a) {
		std::cout << player->getPlayerColour() << " has: " << player->getCities().size() << " cities; " << player->getNbPowerPlants() << " powerplants; Largest power plant is: " << player->getLargestNbPowerPlant() << std::endl;
	}
	std::cout << "=== END PLAYER ORDER ===\n" << std::endl;
}

void TurnManagerDriver() {
	//Create test players
	Player* pa = new Player("(pa) RED");
	Player* pb = new Player("(pb) BLUE");
	Player* pc = new Player("(pc) GREEN");
	Player* pd = new Player("(pd) YELLOW");

	//Player vector
	std::vector<Player*> pv = {pa,pb,pc,pd};

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
	printPlayerArray(pv);
	std::cout << "Game begins..." << std::endl;
	determineOrder(&pv, true); //All randomized
	printPlayerArray(pv);

	std::cout << "Player (pa) buys PP3 and City 1" << std::endl;
	//Player a
	pa->buyPowerPlant((PowerPlant*) PowerPlantCard3);
	pa->buyCity(c1);
	std::cout << "Player (pc) buys City 2" << std::endl;
	//Player c
	pc->buyCity(c2);
	//Determine order
	determineOrder(&pv);
	printPlayerArray(pv);

	std::cout << "Player (pc) buys PowerPlant8" << std::endl;
	//Same amount of city but different powerplants
	pc->buyPowerPlant((PowerPlant*) PowerPlantCard8);
	//Determine order
	determineOrder(&pv);
	printPlayerArray(pv);

	std::cout << "Player (pd) buys City 3 and City 4" << std::endl;
	//Player d
	pd->buyCity(c3);
	pd->buyCity(c4);
	//Determine order
	determineOrder(&pv);
	printPlayerArray(pv);

	//Deletes
	delete pa;
	delete pb;
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

