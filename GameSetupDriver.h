#pragma once
#include <iostream>
#include "../Player.h"
#include "../GameMap.h"
#include <vector>
#include <string>
//Part1
using namespace std;
/**Glabal variables*/
extern vector<Player> currentPlayers;
extern GameMap gameMap;
extern 	vector<string> playing_districts;

/**selesct the gamemap*/
GameMap* selectMap();
/**Select teh starting distrcist that must be adjacent to be played in*/
void setUpStartingArea();
/**Get the total number of players playing*/
int getPlayerCount();
/**Set up the array of colours for the player to select from*/
vector<string> getColorArray();
/**Set the players colours*/
std::string setColors(vector<string> colorArr);
/**Set up the players choices and return the vecotr of players*/
vector<Player> setUpPlayers();
/**Place all the resources on the map*/
void placeResourcesOnMap(GameMap* gameMap);
/**Print all the resources that are on the map*/
void printResources();