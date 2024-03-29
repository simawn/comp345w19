#include "GameMap.h"
#include "City.h"
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <fstream>
#include <vector>
#include "Player.h"
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

		int count = 1;
		//Loops through files in path and add it into files array
		for (const auto &entry : std::filesystem::directory_iterator(path)) {
			files.push_back(entry.path());
			std::cout << count << ". " << entry.path().filename() << std::endl;
			++count;
		}
		int chosen = 1;
		do {
			std::cout << "Enter your selection: " << std::endl;
			std::cin >> chosen;
		} while (chosen < 1 || chosen > files.size());
			try {
				openMap(files[(chosen-1)].string()); //Load map if .json is valid and exists, throws exception if not
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
GameMap::GameMap(std::string filePath) {
	resourceMarket.resize(16);
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
bool GameMap::isCity(std::string cityName) {
	for (auto it = adjList.begin(); it != adjList.end(); it++) {
		if (it->first == cityName)
			return true;
	}
	return false;
}

std::vector<std::vector<Resource*>> GameMap::getResourceMarket() const
{
	return this->resourceMarket;
}

std::unordered_map<std::string, City*> GameMap::getCities() const
{
	return this->adjList;
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
	loadRegionAdjacency(jsonMap);
	//Adding main cities to map (NODES)
	for(auto regionLoop : jsonMap.at("Region")) {
		//districtList.push_back(regionLoop.at("NAME").get<std::string>());
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


void GameMap::addResource(int Grid, int nbOfResource, std::vector<Coal*> &resource) {
	for (int i = 0; i < nbOfResource; i++) {
		resource[0] = new Coal(Grid+1);
 		resourceMarket[Grid].push_back(resource[0]);
		resource.erase(resource.begin());
	}
}

void GameMap::addResource(int Grid, int nbOfResource, std::vector<Gas*> &resource) {
	for (int i = 0; i < nbOfResource; i++) {
		resource[0] = new Gas(Grid+1);

		resourceMarket[Grid].push_back(resource[0]);
		resource.erase(resource.begin());
		
	}
}

void GameMap::addResource(int Grid, int nbOfResource, std::vector<Uranium*> &resource) {
	for (int i = 0; i < nbOfResource; i++) {
		resource[0] = new Uranium(Grid+1);
		resourceMarket[Grid].push_back(resource[0]);
		resource.erase(resource.begin());
	}
}

void GameMap::addResource(int Grid, int nbOfResource, std::vector<Garbage*> &resource) {
	for (int i = 0; i < nbOfResource; i++) {
		resource[0] = new Garbage(Grid+1);
		resourceMarket[Grid].push_back(resource[0]);
		resource.erase(resource.begin());
	}
}


int GameMap::buyResource(std::string resourceType, int price,int nbOfResources,Player *currentPlayer) {
	int counter = 0;
	int resourceCounter=0;
	for (Resource*a : resourceMarket[price]) {
		if (a->getName() == resourceType) {
			if (currentPlayer->buyResources(a)){
				std::cout << "Bought one " << a->getName() << "\n";
				resourceMarket[price].erase(resourceMarket[price].begin() + counter);
				--counter;
				resourceCounter++; }
			if (resourceCounter == nbOfResources) {
				return resourceCounter;
			}
		}
		counter++;
	}
	std::cout << "\n Not enough resources available to buy the requested amount \n";
	return resourceCounter;
}


void GameMap::printResourceMarket() {
	int outer_size = this->resourceMarket.size();
	int inner_size;
	for (int i = 0; i < outer_size; i++) {
		if (!resourceMarket[i].empty()) {
			std::cout << "In grid " << (i + 1) << " Resources: ";
			inner_size = this->resourceMarket[i].size();
			for (int j = 0; j < inner_size; j++) {
				std::cout << this->resourceMarket[i][j]->getName() << " ";
			}
			std::cout << "\n";
		}
	}
}

std::vector<std::string> GameMap::getAllDistricts() {
	return districtList;
}

void GameMap::loadRegionAdjacency(json jsonMap) {
	for (auto regionLoop : jsonMap.at("ConnectedRegions")) {
		districtList.push_back(regionLoop.at("Region").get<std::string>());
		for (auto nodesLoop : regionLoop.at("Neighbour")) {
			adjRegion[regionLoop.at("Region").get<std::string>()].push_back(nodesLoop.at("Region").get<std::string>());
			//nodesLoop.at("Region").get<std::string>();
		}
	}
}

std::vector<std::string> GameMap::getAdjacentRegions(std::string region) {
	return adjRegion[region];
}

int GameMap::freeResourceGridSlots(int i, std::string resourceType) {
	int freeslots = 3;
	if (resourceType == "Uranium") { freeslots = 1;	}
	if (!this->resourceMarket[i].empty()) {
		for (int j = 0; j < this->resourceMarket[i].size(); j++) {
			if (this->resourceMarket[i][j]->getName() == resourceType) {
				freeslots--;
			}
		}
	}else if(i==14 || i==12 || i==10){ //preents inserting uranium where there isnt supposed to be any.
		freeslots = 0;
	}
	//returns the amount of free spots for a resource type in a grid i.
	return freeslots;
}