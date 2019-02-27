#pragma once
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include "GameMap.h"

void openMap(std::string);
void processMap(nlohmann::json, GameMap*);