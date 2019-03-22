#include "GameMap.h"
#include "City.h"
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <filesystem> //Need C++17
#include <nlohmann/json.hpp> //Used to process .json files

using json = nlohmann::json;

GameMap::GameMap() {
	resourceMarket.resize(16);

	
}

void GameMap::loadMap() {
	bool mapIsValid = false;

	while (!mapIsValid) {
		std::cout << "Select a starting map:" << std::endl;

		std::vector<std::filesystem::path> files;
		std::string path = "./data/maps";

		int count = 0;
		//Loops through files in path and add it into files array
		for (const auto &entry : std::filesystem::directory_iterator(path)) {
			files.push_back(entry.path());
			std::cout << "[" << count << "] " << entry.path().filename() << std::endl;
			count++;
		}

		int chosen = 0;
		std::cout << "Enter your selection: (Integer in [ ]): " << std::endl;
		std::cin >> chosen;
		if (chosen >= 0 && chosen < files.size()) { //Choice is valid
			try {
				openMap(files[chosen].string()); //Load map if .json is valid and exists, throws exception if not
				if (!this->checkMapValidity()) { //Check if loaded map is valid
					adjList.clear(); //we might want to create a function that wipes adjlist + all cities objects that were created
					throw "Invalid map.";
				}
				else {
					mapIsValid = true; //Map is valid, exit menu
				}
			}
			catch (std::exception &e) { //TODO: Better exception handling?
				std::cerr << "Cannot load map: " << e.what() << " \nPlease select another map. \n\n" << std::endl;
			}
			catch (const char* e) {
				std::cerr << e << " Please select another map. \n\n" << std::endl;
			}
		}
	}
}
GameMap::GameMap(std::string filePath) {
	openMap(filePath);
}

void GameMap::addCity(City* city) {
	std::string cityName = city->getName();
	adjList[cityName] = city;
	//std::cout << cityName << " added to map." << std::endl;
}

City* GameMap::getCity(std::string cityName) {
	return adjList.find(cityName)->second;
}

void GameMap::displayAllCities() {
	for (auto it = adjList.begin(); it != adjList.end(); it++) {
		std::cout << "City Name: " << it->first << " (ID: " << it->second->getCityId() << ")" << std::endl;
	}
}

bool GameMap::checkMapValidity() {
	//Using 'new' so we can access it outside of scope
	std::set<std::string>* checked = new std::set<std::string>();

	//std::cout << "Checking map validity..." << std::endl;
	traverse(adjList.begin()->second, checked);

	int checkedSize = checked->size();
	delete checked;

	//std::cout << "Checked size : " << checkedSize << std::endl;
	//std::cout << "Adj size : " << adjList.size() << std::endl;

	return checkedSize == adjList.size();
}

void GameMap::traverse(City* city, std::set<std::string>* checked) {
	if (checked->find(city->getName()) == checked->end()) { //If city NOT in checked
		//std::cout << "In: " << city->getName() << std::endl;
		checked->insert(city->getName()); //Mark it as checked
		std::unordered_map<City*, int> neighbours = city->getNeighbours(); //Get their neighbours
		for (auto it : neighbours) { //Traverse the neighbours
			traverse(it.first, checked);
		}
	}
}

//Functions for processing map file
void GameMap::openMap(std::string path) {
	//try { //We want try/catch for json library
		std::ifstream file(path);
		json jsonMap;
		file >> jsonMap;
		processMap(jsonMap);
		file.close();
	//}
	//catch (std::exception &e) {
	//	std::cerr << "Invalid .json file : " << e.what() << std::endl;
	//}
}

void GameMap::processMap(json jsonMap) {
	//std::cout << jsonMap.at("Region")[0].at("NODES") << "\n\n";
	
	//Adding main cities to map (NODES)
	for (auto regionLoop : jsonMap.at("Region")) {
		districtList.push_back(regionLoop.at("NAME").get<std::string>());
		for (auto nodesLoop : regionLoop.at("NODES")) {
			//std::cout << nodesLoop.at("name").get<std::string>() << "\n";
			this->addCity(new City(nodesLoop.at("name").get<std::string>()));
		}
	}

	//this->displayAllCities();

	//Adding all neighbours (EDGES)
	for (auto regionLoop : jsonMap.at("Region")) {
		for (auto edgesLoop : regionLoop.at("EDGES")) {
			//doing NodeA -> NodeB and NodeB -> NodeA to ensure both directions
			this->getCity(edgesLoop.at("NodeA").get<std::string>())->addNeighbour(this->getCity(edgesLoop.at("NodeB").get<std::string>()), edgesLoop.at("price").get<int>());
			this->getCity(edgesLoop.at("NodeB").get<std::string>())->addNeighbour(this->getCity(edgesLoop.at("NodeA").get<std::string>()), edgesLoop.at("price").get<int>());
		}
	}

	//Adding neighbours that goes to other regions 
	for (auto regionEdgesLoop : jsonMap.at("RegionEdges")) {
		//same concept as above
		this->getCity(regionEdgesLoop.at("NodeA").get<std::string>())->addNeighbour(this->getCity(regionEdgesLoop.at("NodeB").get<std::string>()), regionEdgesLoop.at("price").get<int>());
		this->getCity(regionEdgesLoop.at("NodeB").get<std::string>())->addNeighbour(this->getCity(regionEdgesLoop.at("NodeA").get<std::string>()), regionEdgesLoop.at("price").get<int>());
	}

	//this->checkMapValidity() ? std::cout << "Game map is VALID" << std::endl : std::cout << "Game map is INVALID" << std::endl;
}

void GameMap::addResource(int Grid, int nbOfResource, std::vector<Coal*> resource) {
	for (int i = 0; i < nbOfResource; i++) {
		resource[0] = new Coal(Grid);
 		resourceMarket[Grid].push_back(resource[0]);
		resource.erase(resource.begin());
	}
}

void GameMap::addResource(int Grid, int nbOfResource, std::vector<Gas*> resource) {
	for (int i = 0; i < nbOfResource; i++) {
		resource[0] = new Gas(Grid);

		resourceMarket[Grid].push_back(resource[0]);
		resource.erase(resource.begin());
		
	}
}

void GameMap::addResource(int Grid, int nbOfResource, std::vector<Uranium*> resource) {
	for (int i = 0; i < nbOfResource; i++) {
		resource[0] = new Uranium(Grid);
		resourceMarket[Grid].push_back(resource[0]);
		resource.erase(resource.begin());
	}
}

void GameMap::addResource(int Grid, int nbOfResource, std::vector<Garbage*> resource) {
	for (int i = 0; i < nbOfResource; i++) {
		resource[0] = new Garbage(Grid);
		resourceMarket[Grid].push_back(resource[0]);
		resource.erase(resource.begin());
	}
}

void GameMap::printResourceMarket() {
	for (int i = 0; i < resourceMarket.size(); i++) {
		std::cout << "\n In grid " << (i + 1) << " Resources: ";
		for (int j = 0; j < resourceMarket[i].size(); j++) {
			std::cout << resourceMarket[i][j]->getName() << " ";
		}

	}
}

std::vector<std::string> GameMap::getAllDistricts(int pc) {
	if (pc < 4) {
		for (int i = 0; i < 3; ++i) {
			districtList.pop_back();
		}
	}
	else if (pc < 5) {
		for (int i = 0; i < 2; ++i) {
			districtList.pop_back();
		}
	}
	else if (pc < 7) {
		for (int i = 0; i < 1; ++i) {
			districtList.pop_back();
		}
	}
	return districtList;
}
