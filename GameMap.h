#pragma once
#include "City.h"
#include "GameMap.h"
#include <unordered_map>
#include <string>
#include <set>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * Class that creates the game map
 */
class GameMap {
	std::unordered_map<std::string, City*> adjList;
	void openMap(std::string);
	void processMap(json, GameMap*);

public:
	/**
	 * Constuctor for GameMap
	 */
	GameMap();

	/**
	 * Constructor taking a custom map file
	 */
	GameMap(std::string);

	/**
	 * Adds a city to the map. Takes a City pointer.
	 */
	void addCity(City*);

	/**
	 * Searches for a City object that matches the name
	 * @return A pointer to a City object
	 */
	City* getCity(std::string);

	/**
	 * Shows all the cities in GameMap on the console 
	 */
	void displayAllCities();

	/**
	 * Checks if GameMap is valid. Checks if all the cities are connected.
	 * @return A boolean indicating if the game map is valid
	 */
	bool checkMapValidity();

	/**
	 * A recursive depth-first search algorithm to traverse the game map
	 */
	void traverse(City*, std::set<std::string>*);
};