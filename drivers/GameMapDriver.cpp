#include "../GameMap.h"
#include "../City.h"
#include <iostream>

int main456789() {

	//Create cities
	City city1("Toronto");
	City city2("Montreal");
	City city3("Vancouver");
	//City city4("Calgary"); //Invalid city (alone)

	/*
	std::cout << city1.getCityId() << std::endl;
	std::cout << city2.getCityId() << std::endl;
	std::cout << city3.getCityId() << std::endl;
	*/

	//Create game map
	GameMap gameMap;

	//Add cities to game map
	gameMap.addCity(&city1);
	gameMap.addCity(&city2);
	gameMap.addCity(&city3);
	//gameMap.addCity(&city4);

	std::cout << "Display all cities: " << std::endl;
	gameMap.displayAllCities();
	std::cout << std::endl << std::endl;

	//Add neighbours + weight
	/*
	1 --10--> 2 --20--> 3
	2 --40--> 1
	3 --69--> 1
	*/

	city1.addNeighbour(&city2, 10);
	city2.addNeighbour(&city3, 20);
	city2.addNeighbour(&city1, 40);
	city3.addNeighbour(&city1, 69);

	city1.displayAllNeighbours();
	city2.displayAllNeighbours();
	city3.displayAllNeighbours();

	gameMap.checkMapValidity() ? std::cout << "Game map is VALID" << std::endl : std::cout << "Game map is INVALID" << std::endl;

	std::cin.get();
	return 0;
}