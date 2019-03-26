#include "BureaucracyStepDriver.h"
/*
Implement adding resources to the map.
*/
std::vector<int> EoTSupply; //amount of Resources added at EoT. [Coal, Gas, Garbage, Uranium]

void doBureaucracy() {
	payPlayers();				//working
	updateCardMarket();			//working
	//resupplyResourceMarket();
}

void updateCardMarket() {
	market.remove(7);
}

void payPlayers() {
	int income;
	int index=0;

	for (Player* p : currentPlayers_) {
		int numCities = p->getCities().size();
		int numPowered = 0;
		std::cout << "__________________________\n";
		std::cout << p->getPlayerColour() << ", please enter the cost number of the Power Plants you wish to power. \nEnter '-1' once satisfied or power all of your houses to finish.\n" 
			<< numPowered << "/" << numCities << " houses powered." << std::endl;
		p->printResources();

		for (PowerPlant* PP: p->getPowerPlants()) {
			PP->print();
		}

		int entered;	//input variable
		std::vector<int> powered;	//vector is used to avoid repaeting powers.
		do{							//loop alows player to select all powerplants they wish to power
			std::cin >> entered;	

			if (entered == -1){ break; }
			if (isNewEntry(powered, entered)) {	//loop checks validity of a powerplant

				for (PowerPlant* PP : p->getPowerPlants()) {

					if (entered == PP->getCost()) {
						
						std::vector<Resource *> type = PP->getResourceType();

						int tPRoT = p->totalPlayerResourcesOfType(type[0]->getName());
						if (type.size() > 1) { tPRoT += p->totalPlayerResourcesOfType(type[1]->getName());}	//used in the case a dual type appears

						if (tPRoT >= PP->getResourceCost()) {		//checks if the player has the resources to power the plant.
							
							if (type.size() == 1) {	powerPlants(PP, p, tPRoT, type[0]); }
							else { powerPlants(PP, p, type[0], type[1]); }

							numPowered += PP->getHouseValue();	//informs the player how many houses they have powered.
							if (numPowered >= numCities) {
								std::cout << "All your houses are powered! " << numCities << "/" << numCities <<" houses powered."<< std::endl;
								entered = -1; //breaks player out of powering more plants.
								numPowered = numCities; //ensures the players arent overpaid and dont power more than the amount of houses they own.
							}
							else {
								std::cout<< PP->getHouseValue() << "more houses are powered! " << PP->getHouseValue() << "/" << numCities <<" houses powered."<< std::endl;
							}

						}	//else of player has resources
						else {
							std::cout << "You don't have the materials to power the Power Plant!" << std::endl;
						}
						

					}
					else { //else for if powerplant found
						std::cout << "You don't own a Power Plant like that.\nTry entering the costs of the Power Plants that you own." << std::endl;
					}

				}//end of for-loop
				
			}//else of valid powerplant
			else {
				std::cout << "That Power Plant is already Being Powered!" << std::endl;
			}

		} while (entered != -1);

		p->income(getPoweredCityValue(numPowered));
		index++;
	}//end of player loop

}

void resupplyResourceMarket() {
	resourceTableSolution();
	//insert into the resource market according to the ammounts dictated by EoTSupply.
}

//consults the resource table and determines how much of each resource is going into the resource market.
void resourceTableSolution() {
	switch (currentPlayers_.size()) {
	default: EoTSupply = { 0,0,0,0 }; break;
	case 2:
		if (step == 1) { EoTSupply = { 3,2,1,1 }; }
		if (step == 2) { EoTSupply = { 4,2,2,1 }; }
		if (step == 3) { EoTSupply = { 3,4,3,1 }; }
		break;
	case 3:
		if (step == 1) { EoTSupply = { 4,2,1,1 }; }
		if (step == 2) { EoTSupply = { 5,3,2,1 }; }
		if (step == 3) { EoTSupply = { 3,4,3,1 }; }
		break;
	case 4:
		if (step == 1) { EoTSupply = { 5,4,3,2 }; }
		if (step == 2) { EoTSupply = { 6,4,3,2 }; }
		if (step == 3) { EoTSupply = { 4,5,4,2 }; }
		break;
	case 5:
		if (step == 1) { EoTSupply = { 5,4,3,2 }; }
		if (step == 2) { EoTSupply = { 7,5,3,3 }; }
		if (step == 3) { EoTSupply = { 5,6,5,2 }; }
		break;
	case 6:
		if (step == 1) { EoTSupply = { 7,5,3,2 }; }
		if (step == 2) { EoTSupply = { 9,6,5,3 }; }
		if (step == 3) { EoTSupply = { 6,7,6,3 }; }
		break;
	}
}

//returns the payout amount for a number of powered cities
int getPoweredCityValue(int poweredCities) {
	switch (poweredCities) {
		default:return 10; break;
		case 1:	return 22; break;
		case 2:	return 33; break;
		case 3:	return 44; break;
		case 4:	return 54; break;
		case 5:	return 64; break;
		case 6:	return 73; break;
		case 7:	return 82; break;
		case 8:	return 90; break;
		case 9:	return 98; break;
		case 10:return 105; break;
		case 11:return 112; break;
		case 12:return 118; break;
		case 13:return 124; break;
		case 14:return 129; break;
		case 15:return 134; break;
		case 16:return 138; break;
		case 17:return 142; break;
		case 18:return 145; break;
		case 19:return 148; break;
		case 20:return 150; break;
	}

}

//used to determined if a powerplant was already selected.
bool isNewEntry(const std::vector<int> E, const int i) {
	bool x = true;
		for (int c = 0; c < E.size(); c++) {
			if (i == E[c]) { x = false; }
		}
	return x;
}

//used to power PowerPlants if there is one resource type.
void powerPlants(PowerPlant * PP, Player * p, int Total, Resource * type){
	for (int i = PP->getResourceCost(); i > 0; i--) { p->placeResource(type->getName()); }//removes resources from player
	std::cout << Total << " " << type->getName() << " removed to power Power Plant #" << PP->getCost() << "." << std::endl;
}

//used to power PowerPlants if there are two resource types
void powerPlants(PowerPlant * PP, Player * p, Resource * type1, Resource * type2){
	int totalType1= p->totalPlayerResourcesOfType(type1->getName());
	int totalType2= p->totalPlayerResourcesOfType(type2->getName());
	int amount1;
	int amount2;
	//fill in for type1
	std::cout << "This Power Plant accepts "<< type1->getName() << " and " << type2->getName() << "." << std::endl;
	std::cout << "You have:" << totalType1 << " " << type1->getName() << ", " << totalType1 << " " << type2->getName() << "." << std::endl;
	std::cout << "How much " << type1->getName() << " do you want to spend? (you have " << totalType1 << "): ";
	do {
		std::cin >> amount1;
		if (amount1 > totalType1 || amount1 < -1 || amount1>PP->getCost()) {
			std::cout << "Please enter a valid amount (a non-negative integer that is within the amount you own)\n";
		}
	} while (amount1<totalType1 && amount1>-1 && amount1<PP->getCost());
	//fill in for type2
	std::cout << "How much " << type2->getName() << " do you want to spend? (you have " << totalType2 << "): ";
	do {
		std::cin >> amount2;
		if (amount2 > totalType1 || amount2 < -1 || (amount2+amount1)>PP->getCost()) {
			std::cout << "Please enter a valid amount (a non-negative integer that is within the amount you own that doesn't exceed prices with both amounts):";
		}
	} while (amount2<totalType2 && amount2>-1 && (amount2 + amount1)!=PP->getCost());
	for (int i = amount1; i > 0; i--) { p->placeResource(type1->getName()); }//removes type1 resources from player
	for (int i = amount2; i > 0; i--) { p->placeResource(type2->getName()); }//removes type2 resources from player
	std::cout << amount1 << " " << type1->getName() << " and "<< amount2 << type2->getName() << " removed to power Power Plant #" << PP->getCost() << "." << std::endl;
}
