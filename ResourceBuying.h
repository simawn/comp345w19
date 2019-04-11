#pragma once
#include <vector>
#include "GameMap.h"

class ResourceBuying {
public:
	/*Constructor for resource buying phase
	@param pv Player vector
	@param map A pointer to the game map
	@param turn Current turn
	*/
	ResourceBuying(std::vector<Player*> pv, GameMap* map, int turn);
	/*
	Destructor for resource buying phase
	*/
	~ResourceBuying();
};

