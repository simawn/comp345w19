#pragma once
#include "../Marketplace.h"
#include "../Player.h"
#include "../Resources.h"
#include "../GameMap.h"
#include <vector>

//Part 4 Phase 5
/*Bureaucracy, where the players earn cash, re-supply the resource market, and remove a power plant
from the power plant market, replacing it with a new one from the stack.*/


extern int step; 
extern Marketplace market;
extern std::vector<Player*> currentPlayers_;//value should be refactored in final build to whatever the global player vector will be
extern GameMap map_;//value should be refactored in final build to whatever the global map will be

/*performs the bureaucracy steps*/
void doBureaucracy();
/**updates the card market by removing the highest power plant card and drawing a new one*/
void updateCardMarket();
/**Directs players to power their powerplants and pays them accoriding to the amount of energy they supplied to their houses*/
void payPlayers();
/**resupplies the resource market with the appropriate amount of each resource*/
void resupplyResourceMarket();
/**consults the resource table and determines how much of each resource is going into the resource market*/
void resourceTableSolution();
/**resupplies the resource market with the amount of the resource type*/
void resupplyOfType(int amount, std::string type);
/**returns the amount of electro earned for powering an amount of cities*/
int getPoweredCityValue(int);
/*checks if integer entry already exists within the integer vector*/
bool isNewEntry(const std::vector<int>, const int);
/*removes the appropriate amount of resources from the player*/
void powerPlants(PowerPlant * PP, Player * p, int Total, Resource * type);
/*remove the appropriate amount of resurces from a player to their partitioning of two types*/
void powerPlants(PowerPlant * PP, Player * p, Resource * type1, Resource * type2);

/**used for testing the filling of resource market*/
void setupTestResourceMap();

/**returns the smaller integer value of the two provided integers*/
int min(const int a, const int b);
