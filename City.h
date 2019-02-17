#pragma once
#include <string>
#include "Player.h"

class City {
	std::string name;
	Player player;
public:
	City();
	City(std::string);
	City(std::string, Player);

	void setName(std::string);
	std::string getName();

	void setPlayer(Player);
	Player getPlayer();
};

