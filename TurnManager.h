#pragma once
#include <vector>
#include "Player.h"

/* Determines the turn order. It directly modifies the Player array
*/
class TurnManager {
	std::vector<Player*>* playerOrder;
	//bool compare(Player, Player);

public:
	TurnManager();
	TurnManager(std::vector<Player*>*);

	void determineOrder(bool);
};