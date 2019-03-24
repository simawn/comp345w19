#include "TurnManager.h"
#include <algorithm>
#include <random>
#include <map>
#include <vector>


TurnManager::TurnManager() {
}

TurnManager::TurnManager(std::vector<Player*>* players) {
	this->playerOrder = players;
}

bool compare(Player* a, Player* b) { //Custom sort function
	int numA = a->getCities().size();
	int numB = b->getCities().size();
	if (numA == numB) return a->getLargestNbPowerPlant() > b->getLargestNbPowerPlant();
	return numA > numB;
}

void TurnManager::determineOrder(bool gameBegin = false) {
	if (gameBegin) {
		std::shuffle(std::begin(*(this->playerOrder)), std::end(*(this->playerOrder)), std::default_random_engine{});
	}
	else {
		std::sort(std::begin(*(this->playerOrder)), std::end(*(this->playerOrder)), compare);
	}
}