#pragma once
#include <vector>
#include "GameMap.h"
class CityBuilding {
public:
	/*The city building phase
	@param pv A player array
	@param map A pointer to the current map
	@param turn The current turn
	*/
	CityBuilding(std::vector<Player*> pv, GameMap* map, int turn);
};