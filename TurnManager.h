#pragma once
#include <vector>
#include "Player.h"

/** Modifies the player array so the turn order is correct
@param playersVector A pointer to a players array
@param gameBegin If true, array will be randomized. False by default.
*/
void determineOrder(std::vector<Player*>* playersVector, bool gameBegin = false);