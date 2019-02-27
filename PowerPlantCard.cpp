#include "PowerPlantCard.h"
PowerPlantCard::PowerPlantCard(int cardNumber, int maxCitiesSupplied, std::vector<Resource> ressourcesNeeded) {
	PowerPlantCard::cardNumber = cardNumber;
	PowerPlantCard::maxCitiesSupplied = maxCitiesSupplied;
	PowerPlantCard::ressourcesNeeded = ressourcesNeeded;

}
int PowerPlantCard:: getmaxCitiesSupplied(){
	return PowerPlantCard::maxCitiesSupplied;
}
int PowerPlantCard::getCardNumber(){
	return PowerPlantCard::cardNumber
}
std::vector<Resource> PowerPlantCard:: getRessourcesNeeded(){
	return PowerPlantCard::ressourcesNeeded;
}