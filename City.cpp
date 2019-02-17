#include "Player.h"
#include "City.h"
#include <string>

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

/*
//override hash/equal
size_t OverrideHash::operator()(const char *addr) const {
	return std::hash<std::string>()(addr);
}

bool OverrideEqual::operator()(const char *addr1, const char *addr2) const {
	return std::string(addr1) == std::string(addr2);
}
*/

//neighbours
void City::addNeighbour(City* city, int weight) {
	neighbours[city] = weight;
}


