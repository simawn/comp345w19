#ifndef PLAYER_H
#define PLAYER_H
#include "Money.h"
#include "House.h"
#include "Resources.h"
#include "City.h"
#include "PowerPlant.h"
#include <vector>

class Player{
private:
	std::vector<Resource *> resources;
	std::vector<City *> cities;
	std::vector<PowerPlant *> powerplants;
	Money* money;
	House* house;
public:
	Player(); //Added to prevent City.cpp errors
	Player(const char* c);
	int getPlayersMoney();
	const char* getPlayerColour();
	void pay(int amount);
	void destroy();
	Resource * getResourceByType(std::string);
	std::vector<Resource *> getResources();
	bool buyResources(Resource * res);
	Resource * placeResource(std::string res);
	std::vector<City *> getCities();
	bool buyCity(City * city);
	std::vector<PowerPlant *> getPowerPlants();
	bool buyPowerPlant(PowerPlant *pp);

};
#endif // !PLAYER_H
