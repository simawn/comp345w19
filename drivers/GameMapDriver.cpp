#include "../GameMap.h"
#include "../City.h"
#include <iostream>

void GameMapDriver() {
	//Create cities
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

	gameMap.checkMapValidity() ? std::cout << "Game map is VALID" << std::endl : std::cout << "Game map is INVALID" << std::endl;

	//Invalid map
	std::cout << "Adding an invalid city to the map..." << std::endl;
	City city4("Calgary");
	gameMap.addCity(&city4);
	city4.displayAllNeighbours();

	gameMap.checkMapValidity() ? std::cout << "Game map is VALID" << std::endl : std::cout << "Game map is INVALID" << std::endl;
}