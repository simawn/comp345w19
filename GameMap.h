#pragma once
#include "City.h"
#include "GameMap.h"
#include "Resources.h"
#include "Coal.h"
#include "Garbage.h"
#include "Gas.h"
#include "Uranium.h"
#include "Player.h"
#include <unordered_map>
#include <string>
#include <set>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * Class that creates the game map
 */
class GameMap {
	/*
	*The market for the resources
	*/
	std::vector<std::vector<Resource*>> resourceMarket;
	
	/**
	 * Adjacency list for the cities
	 */
	std::unordered_map<std::string, City*> adjList;

	std::unordered_map<std::string, std::vector<std::string>> adjRegion;/**<List of adjacent regions*/

	std::vector<std::string> districtList;/**<List of districts (outer regions for the cities).*/

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
	/**Loads the map from a selected json file*/
	void loadMap();
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
	/**Get all the districts so that a player may choose their starting area*/
	std::vector<std::string> getAllDistricts();
	/**Limit the map size by getting the list of cities based on the number of districts*/
	void loadRegionAdjacency(json jsonMap);
	/**Get adjecent regions for a given region*/
	std::vector<std::string> getAdjacentRegions(std::string region);
	/**
	 * Checks if GameMap is valid. Checks if all the cities are connected.
	 * @return A boolean indicating if the game map is valid
	 */
	bool checkMapValidity();

	/**
	 * A recursive depth-first search algorithm to traverse the game map
	 */
	void traverse(City*, std::set<std::string>*);
	/**
	*add resources to the resource market
	@param Grid number
	@param number of resource to be added
	@param type of resource to be added
	*/
	void addResource(int Grid, int nbOfResource, std::vector<Coal*> &resource);

	/**
	*add resources to the resource market
	@param Grid number
	@param number of resource to be added
	@param type of resource to be added
	*/
	void addResource(int Grid, int nbOfResource, std::vector<Garbage*> &resource);

	/**
	*add resources to the resource market
	@param Grid number
	@param number of resource to be added
	@param type of resource to be added
	*/
	void addResource(int Grid, int nbOfResource, std::vector<Uranium*> &resource);

	/**
	*add resources to the resource market
	@param Grid number
	@param number of resource to be added
	@param type of resource to be added
	*/
	void addResource(int Grid, int nbOfResource, std::vector<Gas*> &resource);
	/*
	*Indicates what is currently in the resource market
	*/
	void printResourceMarket();
	/*
	* Allows players to buy from the resource market
	*/
	int buyResource(std::string resourceType, int price,int nbOfResources,Player *currentPlayer);

	int freeResourceGridSlots(int i, std::string resourceType);
    /*
	*Indicates if a valid city exits in GameMap
	*/
	bool isCity(std::string cityName);
};