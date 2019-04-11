#include "PlayerBotModerate.h"
#include <chrono>
#include <thread>

int PlayerBotModerate::resourceDecision(std::vector<std::vector<Resource*>> resourceMarket) {


	//Bot will only go through the buying resource driver once
	if (this->doneBuyingResource) {
		std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
		std::cout << "2 - Done buying resources" << std::endl;
		return 2;
	}

	//If bot does not have any powerplants
	if (this->getNbPowerPlants() == 0) {
		std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
		std::cout << "2 - No powerplant" << std::endl;
		return 2;
	}

	else {

		//bot selects a PowerPlant of their choice for resource buying
		Cards* targetPowerPlant = this->getPowerPlants()[std::rand() % this->getPowerPlants().size()];

		//If green pp
		if (targetPowerPlant->getResourceType().empty()) {
			std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
			std::cout << "2 - Green" << std::endl;
			return 2;
		}

		//1% chance of skipping resource buying
		if (std::rand() % 100 < 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
			std::cout << "2 - Rng" << std::endl;
			return 2;
		}



		//
		//Determining if enough money to power
		//

		std::vector<Resource*> firstPPResourceType = targetPowerPlant->getResourceType();

		//Will not deal with dual resources
		if (firstPPResourceType.size() > 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
			std::cout << "2 - Dual resource" << std::endl;
			return 2;
		}

		//Will always try to aim for max resource
		int firstPPResourceCost = targetPowerPlant->getResourceCost() * 2;

		//Will not deal with resources requiring cost from different grids
		if (firstPPResourceCost > 3) {
			std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
			std::cout << "2 - Diff grid" << std::endl;
			return 2;
		}

		//Checking the resource market if all the requested resource can be bought all at once, with one request
		//Aims to get the cheapest ones

		//Checks which grid to buy the resource from
		int gridCost = -1;

		//Loops through the market
		for (int i = 0; i < 15; i++) {
			int countTrack = 0;
			for (int j = 0; j < resourceMarket[i].size(); j++) {
				if (resourceMarket[i][j]->getName() == firstPPResourceType[0]->getName()) {
					countTrack++;
				}
				//When the grid has enough resource
				if (countTrack == firstPPResourceCost) {
					gridCost = i;
					i = 15; //Force break the outerloop
					break;
				}
			}
		}

		//No suitable grid found, skip
		if (gridCost == -1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
			std::cout << "2 - Diff grid after check" << std::endl;
			return 2;
		}

		//Saves data for future calls
		this->resourceTypeToBuy = firstPPResourceType[0]->getName();
		this->resourcePriceToPay = gridCost + 1; //+1 since gridCost is an index
		this->resourceAmountToBuy = firstPPResourceCost;

		this->doneBuyingResource = true;

		std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));

		std::cout << "1" << std::endl;
		return 1;
	}

	this->doneBuyingResource = true;

	return 2; //skips
}

std::string PlayerBotModerate::resourceType() {
	std::cout << this->resourceTypeToBuy << std::endl;
	return this->resourceTypeToBuy;
}

int PlayerBotModerate::resourcePrice() {
	std::cout << this->resourcePriceToPay << std::endl;
	return this->resourcePriceToPay;
}

int PlayerBotModerate::resourceAmount() {
	std::cout << this->resourceAmountToBuy << std::endl;
	return this->resourceAmountToBuy;
}