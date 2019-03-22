#include "PowerPlantCard.h"
PowerPlant::PowerPlant(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded) {
	PowerPlant::cardNumber = cardNumber;
	PowerPlant::maxCitiesSupplied = maxCitiesSupplied;
	PowerPlant::nbResourceNeeded = nbResourceNeeded;
}

PowerPlant::PowerPlant(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded, std::string resource1) {
	PowerPlant::cardNumber = cardNumber;
	PowerPlant::maxCitiesSupplied = maxCitiesSupplied;
	PowerPlant::nbResourceNeeded = nbResourceNeeded;
	PowerPlant::resourcesNeeded.push_back(resource1);
}
PowerPlant::PowerPlant(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded, std::string resource1, std::string resource2) {
	PowerPlant::cardNumber = cardNumber;
	PowerPlant::maxCitiesSupplied = maxCitiesSupplied;
	PowerPlant::nbResourceNeeded = nbResourceNeeded;
	PowerPlant::resourcesNeeded.push_back(resource1);
	PowerPlant::resourcesNeeded.push_back(resource2);



}


int PowerPlant:: getmaxCitiesSupplied(){
	return PowerPlant::maxCitiesSupplied;
}
int PowerPlant::getCardNumber(){
	return PowerPlant::cardNumber;
}
std::vector<std::string> PowerPlant:: getRessourcesNeeded(){
	return PowerPlant::resourcesNeeded;
}
int PowerPlant::getNbResourceNeeded(){
	return PowerPlant::nbResourceNeeded;
}
 void PowerPlant:: print() {
	 std::cout << "powerplantcard number is " << PowerPlant::cardNumber << " nb of resource needed is " << PowerPlant::nbResourceNeeded << " max number of cities supplied is "<< PowerPlant::nbResourceNeeded << " Resource needed are: ";
	 
	 for (std::string a : PowerPlant::resourcesNeeded) {
		 std::cout << a << "";
	 }

 }
