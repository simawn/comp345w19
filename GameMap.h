#pragma once
#include "City.h"
#include <set>

class GameMap {
	std::set<City*> adjList; //Using sets to avoid duplicate cities

public:
	GameMap();
	void addCity(City*);
	void displayAllCities();
};