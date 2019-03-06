#include "PowerPlantCard.h"
PowerPlantCard::PowerPlantCard(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded) {
	PowerPlantCard::cardNumber = cardNumber;
	PowerPlantCard::maxCitiesSupplied = maxCitiesSupplied;
	PowerPlantCard::nbResourceNeeded = nbResourceNeeded;
}

PowerPlantCard::PowerPlantCard(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded, std::string resource1) {
	PowerPlantCard::cardNumber = cardNumber;
	PowerPlantCard::maxCitiesSupplied = maxCitiesSupplied;
	PowerPlantCard::nbResourceNeeded = nbResourceNeeded;
	PowerPlantCard::resourcesNeeded.push_back(resource1);
}
PowerPlantCard::PowerPlantCard(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded, std::string resource1, std::string resource2) {
	PowerPlantCard::cardNumber = cardNumber;
	PowerPlantCard::maxCitiesSupplied = maxCitiesSupplied;
	PowerPlantCard::nbResourceNeeded = nbResourceNeeded;
	PowerPlantCard::resourcesNeeded.push_back(resource1);
	PowerPlantCard::resourcesNeeded.push_back(resource2);



}


int PowerPlantCard:: getmaxCitiesSupplied(){
	return PowerPlantCard::maxCitiesSupplied;
}
int PowerPlantCard::getCardNumber(){
	return PowerPlantCard::cardNumber;
}
std::vector<std::string> PowerPlantCard:: getRessourcesNeeded(){
	return PowerPlantCard::resourcesNeeded;
}
int PowerPlantCard::getNbResourceNeeded(){
	return PowerPlantCard::nbResourceNeeded;
}
 void PowerPlantCard:: print() {
	 std::cout << "powerplantcard number is " << PowerPlantCard::cardNumber << " nb of resource needed is " << PowerPlantCard::nbResourceNeeded << " max number of cities supplied is "<< PowerPlantCard::nbResourceNeeded;
}
