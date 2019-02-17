#include "Player.h"
#include "City.h"
#include <string>

City::City() : name("not set") {}

City::City(std::string name) : name(name) {}

City::City(std::string name, Player player) : name(name), player(player) {}

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