//#include "lib/nlohmann/json.hpp"
#include "City.h"
#include "GameMap.h"
#include "GameMapLoader.h"
#include <iostream>
#include <fstream>

void openMap(std::string path) {
	std::string line;
	std::ifstream file (path);
	if (file.is_open) {
		while (getline(file, line)) {
			std::cout << line << std::endl;
		}
		file.close;
	} else {
		std::cout << "Unable to load file" << std::endl;
	}
}

void createMap() {

}