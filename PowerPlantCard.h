#pragma once
#include "Resources.h"
#include <vector>
#include "Cards.h"
class PowerPlantCard:public Cards{
private:
	
	int getmaxCitiesSupplied();
	int getCardNumber();
	int getNbResourceNeeded();
	std::vector<std::string> getRessourcesNeeded();
public:
	int maxCitiesSupplied;
	int cardNumber;
	std::vector<std::string> resourcesNeeded;
	int nbResourceNeeded;
	PowerPlantCard(int cardNumber, int maxCitiesSupplied,int nbResourceNeeded);
	PowerPlantCard(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded,std::string resource1 );
	PowerPlantCard(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded, std::string resource1, std::string resource2);
	PowerPlantCard(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded, std::string resource1, std::string resource2, std::string resource3 );

};