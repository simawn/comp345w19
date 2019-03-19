#pragma once
#include <iostream>
#include "../Player.h"
#include "../GameMap.h"
#include <vector>
#include <string>
//Part1
using namespace std;
void loadPowerPlants();
void loadSummaryCards();
void loadStep3();
GameMap selectMap();
void choosePlayableArea(Player p);
int getPlayerCount();
vector<string> getColorArray();
std::string setColors(int size,vector<string> colorArr);
vector<Player> setUpPlayers();
void placeResourcesonMap();