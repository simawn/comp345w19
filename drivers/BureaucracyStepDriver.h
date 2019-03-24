#pragma once
#include "../Marketplace.h"
#include "../Player.h"
#include "../Resources.h"
#include <vector>

//Part 4 Phase 5
/*Bureaucracy, where the players earn cash, re-supply the resource market, and remove a power plant
from the power plant market, replacing it with a new one from the stack.*/

extern std::vector<Player> currentPlayers;
extern int step;
extern Marketplace market;

void doBureaucracy(Marketplace x);
void updateCardMarket(Marketplace* x);
void payPlayer();
void resupplyResourceMarket();
void checkForStep2();	//must be implemented
void resourceTableSolution(); //consults the resource table and determines howmuch of each resource is going into the resource market.
