#pragma once
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include "GameMap.h"

/**
 * Open a .json file containing a map data
 */
void openMap(std::string);

/**
 * Processes the .json map data. It creates all the required cities and connections
 */
void processMap(nlohmann::json, GameMap*);