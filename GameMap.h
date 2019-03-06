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
	/**
	 * Adjacency list for the cities
	 */
	std::unordered_map<std::string, City*> adjList;

	/**
	 * Reads a .json and checks if it's valid before processing it
	 */
	void openMap(std::string);

	/**
	 * Processes the .json file by creating all the Cities and neighbours specified in the file
	 */
	void processMap(json);

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