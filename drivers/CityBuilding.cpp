#include "CityBuilding.h"
#include "../City.h"
#include "../GameMap.h"

void Phase4() {
	City city1("Toronto");
	City city2("Montreal");
	City city3("Vancouver");

	//Create game map
	GameMap gameMap;

	//Add cities to game map
	gameMap.addCity(&city1);
	gameMap.addCity(&city2);
	gameMap.addCity(&city3);

	std::cout << "Display all cities: " << std::endl;
	gameMap.displayAllCities();
	std::cout << std::endl << std::endl;

	city1.addNeighbour(&city2, 10);
	city2.addNeighbour(&city3, 20);
	city2.addNeighbour(&city1, 40);
	city3.addNeighbour(&city1, 69);

	city1.displayAllNeighbours();
	city2.displayAllNeighbours();
	city3.displayAllNeighbours();

	Player* pa = new Player("(pa) RED");
	Player* pb = new Player("(pb) BLUE");
	Player* pc = new Player("(pc) GREEN");
	Player* pd = new Player("(pd) YELLOW");

	//Player vector
	std::vector<Player*> pv = { pa,pb,pc,pd };
	std::string cityChosen = "";
	for (int i = pv.size()-1; i >= 0; i--) {
		std::cout << "Player " << i+1 << " 'turn \n";
		std::cout << pv[i]->getPlayersMoney() << "\n";
		int choice = -1;

		while(choice!=2){
		if (pv[i]->getCities().size() == 0) {
			std::cout << "1-Build first city \n2-End turn \n";
			std::cin >> choice;
			if (choice == 2) {
				continue;
			}
			if (choice == 1) {
				std::cout << "Select city: \n";
				std::cin >> cityChosen;
				if (gameMap.isCity(cityChosen)) {
					if (pv[i]->buyCity(gameMap.getCity(cityChosen))) {

						std::cout << "Bought city sucessfully\n";
						std::cout << pv[i]->getPlayersMoney() << "\n";
					}
					else {
						std::cout << "City buying conditions not met\n";
					}

				}

			}
			
			}
		}
	}
}