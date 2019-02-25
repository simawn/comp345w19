#pragma once
#include <string>
#include "Player.h"
#include <unordered_map>

class City {
	static int cityIdGen;
	int cityId;
	std::string name;
	Player player;
	std::unordered_map<City*, int> neighbours;

public:
	//ctors
	City();
	City(std::string);
	City(std::string, Player);

	//get/set
	void setName(std::string);
	std::string getName();

	void setPlayer(Player);
	Player getPlayer();

	int getCityId();

	//addNeighbours
	void addNeighbour(City*, int);
	void displayAllNeighbours();
	std::unordered_map<City*, int> getNeighbours();
};

