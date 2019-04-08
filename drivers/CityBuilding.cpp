#include "CityBuilding.h"
#include "../City.h"
#include "../GameMap.h"
#include "../Player.h"
#include "../PlayerHuman.h"

void Phase4() {
	City city1("Toronto");
	City city2("Montreal");
	City city3("Vancouver");
	City city4("Edmonton");

	//Create game map
	GameMap gameMap;

	//Add cities to game map
	gameMap.addCity(&city1);
	gameMap.addCity(&city2);
	gameMap.addCity(&city3);
	gameMap.addCity(&city4);

	std::cout << "Display all cities: " << std::endl;
	gameMap.displayAllCities();
	std::cout << std::endl << std::endl;

	city1.addNeighbour(&city2, 10);
	city2.addNeighbour(&city3, 20);
	city2.addNeighbour(&city1, 40);
	city3.addNeighbour(&city1, 69);
	city3.addNeighbour(&city4, 21);
	
	city1.displayAllNeighbours();
	city2.displayAllNeighbours();
	city3.displayAllNeighbours();
	city4.displayAllNeighbours();
	Player* pa = new PlayerHuman("(pa) RED");
	Player* pb = new PlayerHuman("(pb) BLUE");
	Player* pc = new PlayerHuman("(pc) GREEN");
	Player* pd = new PlayerHuman("(pd) YELLOW");

	//Player vector
	std::vector<Player*> pv = { pa,pb,pc,pd };
	pd->income(100);
	std::string cityChosen = "";
	for (int i = pv.size() - 1; i >= 0; i--) {
		std::cout << "Player " << i + 1 << " 'turn \n";
		std::cout << "Player " << i + 1 << " current money: " << pv[i]->getPlayersMoney() << "\n";
		int choice = -1;

		while (true) {
			if (pv[i]->getCities().size() == 0) {
				std::cout << "1-Build first city \n2-End turn \n";
				std::cin >> choice;
				
				if (choice == 2) {
					break;
				}
				
					
				
				if (choice == 1) {
					std::cout << "Select city: \n";
					std::cin >> cityChosen;
					if (gameMap.isCity(cityChosen)) {
						if (pv[i]->buyCity(gameMap.getCity(cityChosen))) {

							std::cout << "Bought city sucessfully\n";
							std::cout << "Player " << i + 1 << " current money: " << pv[i]->getPlayersMoney() << "\n";
						}
						else {
							std::cout << "City buying conditions not met\n";
						}

					}

				}

			}

			if (pv[i]->getCities().size() != 0) {
				std::cout << "Player " << i + 1 << " current money: " << pv[i]->getPlayersMoney() << "\n";
				std::cout << "1-Add adjacent city to network  \n2-End turn \n";
				std::cin >> choice;
				if (choice == 2) {
					break;
				}
				if (choice == 1) {
					std::cout << "Select city: \n";
					std::cin >> cityChosen;
					bool isSameCity = false;
					if (gameMap.isCity(cityChosen)) {
						for (City * a : pv[i]->getCities()) {
							if (a == gameMap.getCity(cityChosen)) {
								std::cout << "Cannot buy the same city twice \n";
								isSameCity = true;
								break;
							}
						}
						if(!isSameCity)
						if (pv[i]->getPlayersMoney() >= gameMap.getCity(cityChosen)->getValue() + pv[i]->findCityConnectingCost(gameMap.getCity(cityChosen))) {
							pv[i]->buyCity(gameMap.getCity(cityChosen));
							pv[i]->pay(pv[i]->findCityConnectingCost(gameMap.getCity(cityChosen)));
							std::cout << "Bought adjacent city sucessfully \n";
						}
					}
					std::cout << "Player " << i+1 << " current money: "<< pv[i]->getPlayersMoney() << "\n";
				}

			}
		}
	}
	for (int i = 0; i < pv.size();i++ ) {
		std::cout<<"Player "<< i+1 << " money:" << pv[i]->getPlayersMoney() << "\n";
		std::cout << "Player " << i + 1 << " has cities: ";

		for (City* a: pv[i]->getCities()
			) {
			std::cout << a->getName() << " ";

		}
		std::cout << "\n";
	}
}