#include "Player.h"
#include <iostream>
#include <string>

	Player::Player(){
		money = new Money();
		sc = SummaryCard();
	}
	
	Player::Player(std::string c){
		house = new House(c);
		money = new Money();
		sc = SummaryCard();
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
		std::cout << "Money before buying: "<< this->getPlayersMoney() << "\n";
		if (money->removeMoney(res->getValue())) {
			resources.push_back(res);
			std::cout << "Current resources of player :";
			for (int i = 0; i < resources.size(); i++) {
				std::cout << resources[i]->getName() << " ";
			}
			
			std::cout <<"\n Money after buying: " << this->getPlayersMoney() <<"\n";
			notifyObservers();
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
			notifyObservers();
			return true;
		}
		return false;
	}
	

	int Player::findCityConnectingCost(City* city) {
		for (City* a : cities) {
			for (auto it : a->getNeighbours()) {
				if (it.first->getName() == city->getName()) {
					return it.second;

				}
			}
			for (auto it : a->getNeighbours()) {
				if(it.first->findCityConnectingCost(city)!=0)
				return it.second +(it.first->findCityConnectingCost(city));
			}
		}

	}

	std::vector<PowerPlant *> Player::getPowerPlants() {
		return powerplants;
	}
	
	bool Player::buyPowerPlant(PowerPlant * pp) {
		if (money->removeMoney(pp->getCost())) {
			powerplants.push_back(pp);
			notifyObservers()
			return true;
		}
		return false;
	}

	bool Player::buyPowerPlant(PowerPlant * pp, int cost) {
		if (money->removeMoney(cost)) {
			powerplants.push_back(pp);
			notifyObservers();
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
	
	const bool Player::operator==(Player &other) {
		return this->getPlayerColour().compare(other.getPlayerColour()) == 0;
	}

	const bool Player::operator!=(Player & other) {
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

		this->printResources();
	}
	
	SummaryCard Player::getSummaryCard() {
		return sc;
	}


	void Player::income(int a) {
		money->setMoney(money->getMoney() + a);
		std::cout << "you earned " << a << " Elektro. Total:" << money->getMoney() << "\n" << std::endl;
		notifyObservers();
	}

	int Player::totalPlayerResourcesOfType(std::string res) {
		int total = 0;
		for (int i = 0; i < resources.size(); ++i) {
			if (resources[i]->getName().compare(res) == 0) {
				total++;
			}
		}
		return total;
	}

	void Player::printResources() {
		std::cout << "::" << getPlayerColour() << "'s Resources::\n"
			<< "Coal: [" << totalPlayerResourcesOfType("Coal")
			<< "], Gas: [" << totalPlayerResourcesOfType("Gas")
			<< "], Garbage: [" << totalPlayerResourcesOfType("Garbage")
			<< "], Uranium: [" << totalPlayerResourcesOfType("Uranium") << "]" << std::endl;
	}
	void Player::attachObserver(Observer* o) {
		observers.push_back(o);
	}
	void Player::removeObserver(Observer* o) {
		auto itr = std::find(observers.begin(), observers.end(), o);
		if (itr != observers.end()) {
			observers.erase(itr);
		}
	}
	void Player::notifyObservers() {
		for (Observer *o : observers) {
			o->notify();
		}
	}

	Player::~Player()
	{
	}
