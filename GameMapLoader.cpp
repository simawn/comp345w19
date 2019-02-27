#include "City.h"
#include "GameMap.h"
#include "GameMapLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp> //Used to process .json files

using json = nlohmann::json;

void openMap(std::string path) {
	GameMap* gameMap = new GameMap();

	try { //We want try/catch for json library
		std::ifstream file(path);
		json jsonMap;
		file >> jsonMap;
		processMap(jsonMap, gameMap);
		file.close();
	} catch (std::exception &e) {
		std::cerr << "Invalid .json file : " << e.what() << std::endl;
	}
}

void processMap(json jsonMap, GameMap* gameMap) {
	//std::cout << jsonMap.at("Region")[0].at("NODES") << "\n\n";

	//Adding main cities to map (NODES)
	for (auto regionLoop : jsonMap.at("Region")) {
		for (auto nodesLoop : regionLoop.at("NODES")) {
			//std::cout << nodesLoop.at("name").get<std::string>() << "\n";
			gameMap->addCity(new City(nodesLoop.at("name").get<std::string>()));
		}
	}

	gameMap->displayAllCities();

	//Adding all neighbours (EDGES)
	for (auto regionLoop : jsonMap.at("Region")) {
		for (auto edgesLoop : regionLoop.at("EDGES")) {
			//doing NodeA -> NodeB and NodeB -> NodeA to ensure both directions
			gameMap->getCity(edgesLoop.at("NodeA").get<std::string>())->addNeighbour(gameMap->getCity(edgesLoop.at("NodeB").get<std::string>()), edgesLoop.at("price").get<int>());
			gameMap->getCity(edgesLoop.at("NodeB").get<std::string>())->addNeighbour(gameMap->getCity(edgesLoop.at("NodeA").get<std::string>()), edgesLoop.at("price").get<int>());
		}
	}

	//Adding neighbours that goes to other regions 
	for (auto regionEdgesLoop : jsonMap.at("RegionEdges")) {
		//same concept as above
		gameMap->getCity(regionEdgesLoop.at("NodeA").get<std::string>())->addNeighbour(gameMap->getCity(regionEdgesLoop.at("NodeB").get<std::string>()), regionEdgesLoop.at("price").get<int>());
		gameMap->getCity(regionEdgesLoop.at("NodeB").get<std::string>())->addNeighbour(gameMap->getCity(regionEdgesLoop.at("NodeA").get<std::string>()), regionEdgesLoop.at("price").get<int>());
	}

	gameMap->checkMapValidity() ? std::cout << "Game map is VALID" << std::endl : std::cout << "Game map is INVALID" << std::endl;
}