#pragma once
#include <vector>
#include "GameMap.h"

class ResourceBuying {
public:
	ResourceBuying(std::vector<Player*> pv, GameMap* map, int turn);
	~ResourceBuying();
};

