#include "CityBuilding.h"
#include <vector>
#include "Player.h"
#include "GameMap.h"

CityBuilding::CityBuilding(std::vector<Player*> pv, GameMap* gameMap, int turn) {
	std::string cityChosen = "";
	for (int i = pv.size() - 1; i >= 0; i--) {
		std::cout << "Player " << i + 1 << " 'turn \n";
		std::cout << "Player " << i + 1 << " current money: " << pv[i]->getPlayersMoney() << "\n";
		int choice = -1;

		while (true) {
			if (pv[i]->getCities().size() == 0) {
				std::cout << "1-Build first city \n2-End turn \n";
//CIN buildCity()
				std::cin >> choice;

				if (choice == 2) {
					break;
				}

				if (choice == 1) {
					std::cout << "Select city: \n";
//CIN selectCity()
					std::cin >> cityChosen;
					if (gameMap->isCity(cityChosen)) {
						if (pv[i]->buyCity(gameMap->getCity(cityChosen))) {

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
//CIN buildCity()
				std::cin >> choice;
				if (choice == 2) {
					break;
				}
				if (choice == 1) {
					std::cout << "Select city: \n";
//CIN selectCity()
					std::cin >> cityChosen;
					bool isSameCity = false;
					if (gameMap->isCity(cityChosen)) {
						for (City * a : pv[i]->getCities()) {
							if (a == gameMap->getCity(cityChosen)) {
								std::cout << "Cannot buy the same city twice \n";
								isSameCity = true;
								break;
							}
						}
						if(!isSameCity)
							if (pv[i]->getPlayersMoney() >= gameMap->getCity(cityChosen)->getValue() + pv[i]->findCityConnectingCost(gameMap->getCity(cityChosen))) {
								pv[i]->buyCity(gameMap->getCity(cityChosen));
								pv[i]->pay(pv[i]->findCityConnectingCost(gameMap->getCity(cityChosen)));
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
