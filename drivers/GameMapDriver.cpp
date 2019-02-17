#include "../GameMap.h"
#include "../City.h"
#include <iostream>

int main() {
	City city1;
	City city2;
	City city3;

	std::cout << city1.getCityId() << std::endl;
	std::cout << city2.getCityId() << std::endl;
	std::cout << city3.getCityId() << std::endl;

	GameMap gameMap;

	gameMap.addCity(&city1);
	gameMap.addCity(&city2);
	gameMap.addCity(&city3);

	gameMap.displayAllCities();

	std::cin.get();
}