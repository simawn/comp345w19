#include "../TurnManager.h"
#include "../Player.h"
#include "../GameMap.h"
#include "../drivers/ResourceBuyingDriver.h"

void Phase3() {
	Gas* g = new Gas(1);
	Coal* c = new Coal(1);
	Garbage* ga = new Garbage(1);
	Uranium* u = new Uranium(1);
	static GameMap map;
	std::vector<Coal*> TotalCoal(24);
	std::vector<Garbage*> TotalGarbage(24);
	std::vector<Gas*> TotalGas(24);
	std::vector<Uranium*> TotalUranium(12);
	for (int i = 0; i < 8; i++) {
		map.addResource(i, 3, TotalCoal);
	}
	for (int i = 2; i < 8; i++) {
		map.addResource(i, 3, TotalGas);
	}
	map.addResource(6, 3, TotalGarbage);
	map.addResource(7, 3, TotalGarbage);
	map.addResource(13, 1, TotalUranium);
	map.addResource(15, 1, TotalUranium);
	map.printResourceMarket();


	Player* pa = new Player("(pa) RED");
	Player* pb = new Player("(pb) BLUE");
	Player* pc = new Player("(pc) GREEN");
	Player* pd = new Player("(pd) YELLOW");
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
	
	std::cout << "Game begins..." << std::endl;

	

	//Player a
	pa->buyPowerPlant((PowerPlant*)PowerPlantCard5);
	pa->buyPowerPlant((PowerPlant*)PowerPlantCard7);
	pa->buyPowerPlant((PowerPlant*)PowerPlantCard9);
	pa->buyPowerPlant((PowerPlant*)PowerPlantCard3);
	pa->buyCity(c1);
	//Player vector
	std::vector<Player*> pv = { pa,pb,pc,pd };	
	std::cout << "Entering Phase 3 of the game" << std::endl;
	int choice = -1;
	int price = -1;
	int amount = -1;
	std::string resource;
	for (int i = 0; i < pv.size(); i++) {
		int coal = 0;
		int garbage = 0;
		int uranium = 0;
		int gas = 0;
		std::vector<PowerPlant*> powerPlants = pv[i]->getPowerPlants();

		for (int i = 0; i < powerPlants.size(); i++) {
			for (Resource * r : powerPlants[i]->getResourceType()
				) {
				if (r->getName() == "Coal")
					coal++;
				if (r->getName() == "Gas")
					gas++;
				if (r->getName() == "Garbage")
					garbage++;
				if (r->getName() == "Uranium")
					uranium++;
			}
		}
		std::cout << "Starting turn of player " << i + 1 << "can buy maximum of " << coal << " coal " << "can buy maximum of " << gas << " gas " << " can buy maximum of " << uranium << "uranium " << " can buy maximum of " << garbage << "garbage " << "\n";
		while (true) {
			std::cout << "Player " << i + 1 << "can buy maximum of " << coal << " coal " << "can buy maximum of " << gas << " gas " << " can buy maximum of " << uranium << "uranium " << " can buy maximum of " << garbage << "garbage " << "\n";

			std::cout << "Please select your choice \n 1-Buy resources \n 2-Stop buying resources \n";
			std::cin >> choice;
			if (choice == 2)
				break;
			if (choice != 1)
				continue;
			std::cout << "Input resource to buy \n";
			std::cin >> resource;
			if (resource != "Coal" && resource != "Gas" &&resource != "Uranium" &&resource != "Garbage") {
				std::cout << "Invalid resource \n";
				continue;
			}
			std::cout << "Input price to buy \n";
			std::cin >> price;
			if (price < 1 || price > 16) {
				std::cout << "Invalid price \n";
				continue;
			}
			price = price - 1;
			std::cout << "Input amount to buy \n";
			std::cin >> amount;
			if (resource == "Coal") {
				if (coal >= amount && pv[i]->getPlayersMoney() >= price * amount)
					coal = coal -map.buyResource(resource, price, amount, pv[i]);

				else {
					std::cout << "Invalid amount \n";
					continue;
				}
			}
			else if (resource == "Gas") {
				if (gas >= amount && pv[i]->getPlayersMoney() >= price * amount)
					gas = gas -map.buyResource(resource, price, amount,pv[i]);
				else {
					std::cout << "Invalid amount \n";
					continue;
				}
			}
			else if (resource == "Uranium \n") {
				if (uranium >= amount && pv[i]->getPlayersMoney() >= price * amount)
			uranium = uranium -map.buyResource(resource, price, amount, pv[i]);
				else {
					std::cout << "Invalid amount \n";
					continue;
				}
			}
			else if (resource == "Garbage") {
				if (garbage >= amount && pv[i]->getPlayersMoney() >= price * amount)
				garbage =garbage -map.buyResource(resource, price, amount, pv[i]);
				else {
					std::cout << "Invalid amount \n";
					continue;
				}

			}
			
		}
		map.printResourceMarket();
		
	}

}