#ifndef PLAYER_H
#define PLAYER_H
#include "Money.h"
#include "House.h"
#include "Resources.h"
#include "City.h"
#include "PowerPlant.h"
#include <vector>
#include <string>
/**Class that represents a player, playable character in the game*/
class Player{
private:
	std::vector<Resource *> resources;/**<The resources that a given player has.*/
	std::vector<City *> cities;/**<The cities that a player owns.*/
	std::vector<PowerPlant *> powerplants;/**<The power plants that a player has.*/
	Money* money;/**<The money pointer for money management.*/
	House* house;/**<The house pointer for the house management, colour and amounts.*/
	std::string starting_district;/**<The starting district for the player.*/
public:
	/**Default constructor.*/
	Player(); //Added to prevent City.cpp errors
	/**Set the player up with their colour.*/
	Player(std::string);
	/**Get the amount of money a player has.*/
	int getPlayersMoney();
	/**Get the colour for a given player set up for their house.*/
	std::string getPlayerColour();
	/**Pay for something, may be deprecated in the next release.*/
	void pay(int amount);
	/**Destructor.*/
	void destroy();
	/**The the resource for the player by type, ie coal.*/
	Resource * getResourceByType(std::string);
	/**Get all the resources that a player owns.*/
	std::vector<Resource *> getResources();
	/**Buy a resource for a given player.*/
	bool buyResources(Resource * res);
	/**PLace a resource, ie remove a resource for the player.*/
	Resource * placeResource(std::string res);
	/**Get all the cities a player owns.*/
	std::vector<City *> getCities();
	/**Buy a city and add it to the owned cities.*/
	bool buyCity(City * city);
	/**Get all the power plants that a player owns.*/
	std::vector<PowerPlant *> getPowerPlants();
	/**Buy a power plant for the player.*/
	bool buyPowerPlant(PowerPlant *pp);
	/**Set the colour of the player*/
	void setPlayerColor(std::string c);
	/**Set the starting district*/
	void setStartingDistrict(std::string district);
	/**Get the starting district*/
	std::string getStartingDistrict();


};
#endif // !PLAYER_H
