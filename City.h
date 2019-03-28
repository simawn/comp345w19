#pragma once
#include <string>
#include <unordered_map>

/**
 * A City class
 */
class City {

	/**
	 * The next city ID to be assigned.
	 * An unique ID is generated for each City object that is created.
	 */
	static int cityIdGen;

	/**
	 * City object ID 
	 */
	int cityId;

	/**
	 * Default cost if a city
	 */
	int cost = 10;

	/**
	 * The name of the city
	 */
	std::string name;
	
	/**
	 * List of adjacent neighbours the city posseses
	 */
	std::unordered_map<City*, int> neighbours;

public:
	/**
	 * Default City constructor.
	 * Will assign "City name not set" as city name
	 */
	City();

	/**
	 * City constructor taking a name variab
	 */
	City(std::string);
	//City(std::string, Player);

	/**
	 * Change the name of a city
	 */
	void setName(std::string);

	/**
	 * Retrieves a city name
	 */
	std::string getName();

	/**
	 * Retrives the cost of a city
	 */
	int getValue();

	//void setPlayer(Player);
	//Player getPlayer();

	/**
	 * Return the city Id
	 */
	int getCityId();

	/**
	 * Adds a neighbour to a city
	 * Takes a city pointer and a traveling cost (int)
	 */
	void addNeighbour(City*, int);

	/**
	 * Displays all neighbours of the city on the console
	 */
	void displayAllNeighbours();

	/**
	 * Get the list of neighbours of a city
	 * @Return A list containing pointers to a City and their travel cost
	 */
	std::unordered_map<City*, int> getNeighbours();
	int findCityConnectingCost(City* city);
};

