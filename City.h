#pragma once
#include <string>
#include "Player.h"
#include <unordered_map>

/*
//Overrides needed for custom keys in map
class OverrideHash {
public:
	size_t operator() (const char*) const;
};

class OverrideEqual {
public:
	bool operator() (const char*, const char*) const;
};
*/

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
};

