#pragma once
#include <iostream>
#include "../Player.h"
#include "../GameMap.h"
#include <vector>
#include <string>
//Part1
using namespace std;
extern vector<Player> currentPlayers;
extern GameMap gameMap;
void loadPowerPlants();
void loadSummaryCards();
void loadStep3();
GameMap selectMap();
void setUpStartingArea();
string choosePlayableArea(Player p,vector<string> districts);
int getPlayerCount();
vector<string> getColorArray();
std::string setColors(vector<string> colorArr);
vector<Player> setUpPlayers();
void placeResourcesonMap();