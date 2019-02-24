#include "Player.h"
#include <iostream>
#include <string>
	/*Default Contsructor*/
	Player::Player(){}
	/*Constructor for the gameplay*/
	Player::Player(const char* c){
		house = new House(c);
		money = new Money();
	}
	/*Get the players money*/
	int Player::getPlayersMoney() {
		return money->getMoney();
	}
	/*Get the colour the player is playing as*/
	const char* Player::getPlayerColour() {
		return house->getColour();
	}
	/*Pay for any item on the board*/
	void Player::pay(int amount) {
		if (money->removeMoney(amount)) {
			std::cout << "Succesfully payed for" << std::endl;
		}
		else {
			std::cout << "Cannot go into the negatives, try another purchase" << std::endl;
		}
	}
	/*Get teh resource list for that player*/
	std::vector<Resource *> Player::getResources() {
		return resources;
	}
	/*Get the resource of a given type*/
	Resource * Player::getResourceByType(std::string res) {
		for (int i = 0; i < resources.size(); ++i) {
			if (resources[i]->getName().compare(res)==0) {
				return resources[i];
			}
		}
		return NULL;
	}
	/*Buy a resource for that player from the market*/
	bool Player::buyResources(Resource  *res) {
		if (money->removeMoney(res->getValue())) {
			resources.push_back(res);			
			return true;
		}
		return false;
	}
	/*Place a resource on the board of a given type*/
	Resource * Player::placeResource(std::string res) {
		for (int i = 0; i < resources.size(); ++i) {
			if (resources[i]->getName().compare(res) == 0) {
				Resource * r = resources[i];
				resources.erase(resources.begin()+i);
				return r;
			}
		}
		return NULL;
	}
	/*Get the cities that the player owns*/
	std::vector<City *> Player::getCities() {
		return cities;
	}
	/*Buy a city*/
	bool Player::buyCity(City * city) {
		if (money->removeMoney(city->getValue())) {
			cities.push_back(city);
			return true;
		}
		return false;
	}
	/*Get the powerplants that the player owns*/
	std::vector<PowerPlant *> Player::getPowerPlants() {
		return powerplants;
	}
	/*Buy a powerplant*/
	bool Player::buyPowerPlant(PowerPlant * pp) {
		if (money->removeMoney(pp->getCost())) {
			powerplants.push_back(pp);
			return true;
		}
		return false;
	}
	/*destruct*/
	void Player::destroy() {
		delete money;
		delete house;
	}

