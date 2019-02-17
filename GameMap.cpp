#include "GameMap.h"
#include <iostream>

GameMap::GameMap(){}

void GameMap::addCity(City* city) {
	adjList.insert(city);
}

void GameMap::displayAllCities() {
	for (auto it = adjList.begin(); it != adjList.end(); it++) {
		std::cout << "ID: " << (*it)->getCityId() << ", City Name: " << (*it)->getName() << std::endl;
	}
}