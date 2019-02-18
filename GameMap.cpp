#include "GameMap.h"
#include <iostream>

GameMap::GameMap(){}

void GameMap::addCity(City* city) {
	adjList[city->getName()] = city;
	std::cout << "Added!" << std::endl;
}

void GameMap::displayAllCities() {
	for (auto it = adjList.begin(); it != adjList.end(); it++) {
		std::cout << "City Name: " << it->first << " (ID: " << it->second->getCityId() << ")" <<std::endl;
	}
}