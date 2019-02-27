#pragma once
#include "City.h"
#include <unordered_map>
#include <string>
#include <set>

class GameMap {
	std::unordered_map<std::string, City*> adjList;

public:
	GameMap();
	void addCity(City*);
	City* getCity(std::string);
	void displayAllCities();
	bool checkMapValidity();
	void traverse(City*, std::set<std::string>*);
};