#include "ResourceBuying.h"
#include "Player.h"
#include "Resources.h"
#include "Gas.h"
#include "Coal.h"
#include "Garbage.h"
#include "Uranium.h"
#include "GameMap.h"
#include <vector>

ResourceBuying::ResourceBuying(std::vector<Player*> pv, GameMap* map, int turn) {
	std::cout << "Entering Phase 3 of the game" << std::endl;
	int choice = -1;
	int price = -1;
	int amount = -1;
	std::string resource;
	for (int i = pv.size() - 1; i >= 0; i--) {
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
		uranium = uranium * 2;
		coal = coal * 2;
		garbage = garbage * 2;
		gas = gas * 2;


		std::cout << "Starting turn of player " << pv[i]->getPlayerColour() << "\n";
		while (true) {

			std::cout << "\n";
			map->printResourceMarket();
			std::cout << "\n";

			std::cout << "Player " << pv[i]->getPlayerColour() << " maximum of " << coal << " coal " << " maximum of " << gas << " gas " << " maximum of " << uranium << " uranium " << " maximum of " << garbage << " garbage " << "\n";

			std::cout << "Please select your choice \n 1-Buy resources \n 2-Stop buying resources \n";
//CIN resourceDecision()
//std::cin >> choice;
			choice = pv[i]->resourceDecision();
			if (choice == 2)
				break;
			if (choice != 1)
				continue;
			std::cout << "Input resource to buy \n";
//CIN resourceType()
//std::cin >> resource;
			resource = pv[i]->resourceType();
			if (resource != "Coal" && resource != "Gas" &&resource != "Uranium" &&resource != "Garbage") {
				std::cout << "Invalid resource \n";
				continue;
			}
			std::cout << "Input price to buy \n";
//CIN resourcePrice()
//std::cin >> price;
			price = pv[i]->resourcePrice();
			if (price < 1 || price > 16) {
				std::cout << "Invalid price \n";
				continue;
			}
			price = price - 1;
			std::cout << "Input amount to buy \n";
//CIN resourceAmount()
//std::cin >> amount;
			amount = pv[i]->resourceAmount();
			if (resource == "Coal") {
				if (coal >= amount && pv[i]->getPlayersMoney() >= price * amount)
					coal = coal - map->buyResource(resource, price, amount, pv[i]);

				else {
					std::cout << "Invalid amount \n";
					continue;
				}
			}
			else if (resource == "Gas") {
				if (gas >= amount && pv[i]->getPlayersMoney() >= price * amount)
					gas = gas - map->buyResource(resource, price, amount, pv[i]);
				else {
					std::cout << "Invalid amount \n";
					continue;
				}
			}
			else if (resource == "Uranium \n") {
				if (uranium >= amount && pv[i]->getPlayersMoney() >= price * amount)
					uranium = uranium - map->buyResource(resource, price, amount, pv[i]);
				else {
					std::cout << "Invalid amount \n";
					continue;
				}
			}
			else if (resource == "Garbage") {
				if (garbage >= amount && pv[i]->getPlayersMoney() >= price * amount)
					garbage = garbage - map->buyResource(resource, price, amount, pv[i]);
				else {
					std::cout << "Invalid amount \n";
					continue;
				}

			}

		}
	}
	for (int i = 0; i < pv.size();i++) {
		pv[i]->printResources();
		std::cout << "Player " << i+1 << " money: " << pv[i]->getPlayersMoney() << "\n";
	}

	std::cout << "\n";
	map->printResourceMarket();
	std::cout << "\n";
}

ResourceBuying::~ResourceBuying() {}
