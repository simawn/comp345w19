#include "Player.h"
#include <iostream>
#include <string>
	
	Player::Player(){
		money = new Money();
	}
	
	Player::Player(std::string c){
		house = new House(c);
		money = new Money();
	}
	
	int Player::getPlayersMoney() {
		return money->getMoney();
	}
	
	std::string Player::getPlayerColour() {
		return house->getColour();
	}
	
	void Player::pay(int amount) {
		if (money->removeMoney(amount)) {
			std::cout << "Succesfully payed for" << std::endl;
		}
		else {
			std::cout << "Cannot go into the negatives, try another purchase" << std::endl;
		}
	}
	
	std::vector<Resource *> Player::getResources() {
		return resources;
	}
	
	Resource * Player::getResourceByType(std::string res) {
		for (int i = 0; i < resources.size(); ++i) {
			if (resources[i]->getName().compare(res)==0) {
				return resources[i];
			}
		}
		return NULL;
	}
	
	bool Player::buyResources(Resource  *res) {
		std::cout << this->getPlayersMoney() << "\n";
		if (money->removeMoney(res->getValue())) {
			resources.push_back(res);
			std::cout << "Current resources of player :";
			for (int i = 0; i < resources.size(); i++) {
				std::cout << resources[i]->getName() << " ";
			}
			
			std::cout <<"\n" << this->getPlayersMoney() <<"\n";
			return true;
		}
		return false;
	}
	
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
	
	std::vector<City *> Player::getCities() {
		return cities;
	}
	
	bool Player::buyCity(City * city) {
		if (money->removeMoney(city->getValue())) {
			cities.push_back(city);
			return true;
		}
		return false;
	}
	
	std::vector<PowerPlant *> Player::getPowerPlants() {
		return powerplants;
	}
	
	bool Player::buyPowerPlant(PowerPlant * pp) {
		if (money->removeMoney(pp->getCost())) {
			powerplants.push_back(pp);
			return true;
		}
		return false;
	}

	bool Player::buyPowerPlant(PowerPlant * pp, int cost) {
		if (money->removeMoney(cost)) {
			powerplants.push_back(pp);
			return true;
		}
		return false;
	}

	void Player::setPlayerColor(std::string c) {
		delete house;
		house = nullptr;
		house = new House(c);
	}
	
	void Player::destroy() {
		delete money;
		delete house;
	}
	void Player::setStartingDistrict(std::string district) {
		starting_district = district;
	}
	std::string Player::getStartingDistrict() {
		return starting_district;
	}
	int Player:: getNbPowerPlants() {
		return Player::powerplants.size();
	}
	int Player::getLargestNbPowerPlant() {
		int max = -1;
		for (int i = 0; i < Player::powerplants.size(); i++) {
			if (powerplants[i]->getCost() > max) {
				max = powerplants[i]->getCost();
			}
		}return max;
	}

	bool Player::operator==(Player &other) {
		return this->getPlayerColour().compare(other.getPlayerColour()) == 0;
	}

	bool Player::operator!=(Player & other) {
		return this->getPlayerColour().compare(other.getPlayerColour()) != 0;
	}

	void Player::printPlayerInfo() {
		std::cout << "=== PLAYER INFO ===" << std::endl;
		std::cout << "Player colour: " << this->getPlayerColour() << std::endl;
		std::cout << "Money: " << this->getPlayersMoney() << std::endl;

		std::cout << "PowerPlants: " << std::endl;
		for (PowerPlant* pp : this->getPowerPlants()) {
			std::cout << "   ";
			pp->print();
		}

		std::cout << "Cities: " << std::endl;
		for (City* city : this->getCities()) {
			std::cout << "   " << city->getName() << std::endl;
		}
	}
