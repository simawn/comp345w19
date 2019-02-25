#include "City.h"
#include "GameMap.h"
#include "GameMapLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void openMap(std::string path) {
	std::ifstream file(path);
	json jsonMap;
	file >> jsonMap; //jsonMap will be 'null' if .json is not valid
	std::cout << jsonMap << std::endl << std::endl;
	std::cout << jsonMap["1"]["Boston"] << std::endl; //test
}

void createMap() {

}