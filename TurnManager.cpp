#include "TurnManager.h"
#include <algorithm>
#include <random>
#include <vector>

bool compare(Player* a, Player* b) { //Custom sort function
	int numA = a->getCities().size();
	int numB = b->getCities().size();
	if (numA == numB) return a->getLargestNbPowerPlant() > b->getLargestNbPowerPlant();
	return numA > numB;
}

void determineOrder(std::vector<Player*>* playersVector, bool gameBegin) {
	if (gameBegin) {
		std::shuffle(std::begin(*playersVector), std::end(*playersVector), std::default_random_engine{});
	}
	else {
		std::sort(std::begin(*playersVector), std::end(*playersVector), compare);
	}
}