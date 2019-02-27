#pragma once
#include "Resources.h"
#include <vector>
class PowerPlantCard {
private:
	int maxCitiesSupplied;
	int cardNumber;
	PowerPlantCard(int cardNumber, int maxCitiesSupplied, std::vector<Resource> ressourcedNeeded);
	std::vector<Resource> ressourcesNeeded;
	int getmaxCitiesSupplied();
	int getCardNumber();
	std::vector<Resource> getRessourcesNeeded();
};