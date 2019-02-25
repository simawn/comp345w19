#include "Player.h"
#include "City.h"
#include <string>
#include <iostream>

int City::cityIdGen = 0; //static

//Upon ctor call, assign unique custom ID to city
City::City() : 
	name("City name not set"),
	cityId(cityIdGen) {
	cityIdGen++;
}

City::City(std::string name) : 
	name(name), 
	cityId(cityIdGen) {
	cityIdGen++;
}

City::City(std::string name, Player player) : 
	name(name), 
	player(player), 
	cityId(cityIdGen) {
	cityIdGen++;
}

//getters/setters
void City::setName(std::string name){
	this->name = name;
}

std::string City::getName() {
	return this->name;
}

void City::setPlayer(Player player) {
	this->player = player;
}

Player City::getPlayer() {
	return this->player;
}

int City::getCityId() {
	return this->cityId;
}

//neighbours
void City::addNeighbour(City* city, int weight) {
	neighbours[city] = weight;
	std::cout << this->getName() << " to " << city->getName() << " for " << weight << " added." << std::endl;
}

void City::displayAllNeighbours() {
	std::cout << "========" << std::endl;
	std::cout << "Neighbours for " << this->getName() << " (" << this->getCityId() << "):" << std::endl;
	for (auto it = neighbours.begin(); it != neighbours.end(); it++) {
		std::cout << "To: " << it->first->getName() << " (" << it->first->getCityId() << ") Cost: " << it->second << std::endl;
	}
	std::cout << "========" << std::endl;
}

std::unordered_map<City*, int> City::getNeighbours() {
	return neighbours;
}
