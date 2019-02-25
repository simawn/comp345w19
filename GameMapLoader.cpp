#include "City.h"
#include "GameMap.h"
#include "GameMapLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp> //Used to process .json files

using json = nlohmann::json;

void openMap(std::string path) {
	try { //We want try/catch for json library
		std::ifstream file(path);
		json jsonMap;
		file >> jsonMap;
		processMap(jsonMap);
		file.close();
	} catch (std::exception &e) {
		std::cerr << "Invalid .json file : " << e.what() << std::endl;
	}
}

void processMap(json jsonMap) {
	std::cout << jsonMap << std::endl;
	//Create cities
	//Add neighbours connections
}