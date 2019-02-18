#pragma once
#include "City.h"
#include <unordered_map>
#include <string>

class GameMap {
	std::unordered_map<std::string, City*> adjList;

public:
	GameMap();
	void addCity(City*);
	void displayAllCities();
};