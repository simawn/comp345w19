#include "PlayerBot.h"
#include "GameMap.h"
#include <chrono>
#include <thread>

int PlayerBot::auctionDecision(Marketplace* marketplace, int turn) {
	//std::cout << "In Player Bot" << std::endl;
	//Code below adds a delay (defined in Player.h) before output
	std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
	//If it is the first turn, bot will put the first powerplant in auction
	//If the bot has enough money to buy the least expensive powerpoint, there's a 50% chance that it will put it in auction
	int choice = turn == 1 ? 
		0 : 
		std::rand() % 100 < 50 && this->getPlayersMoney() > marketplace->getCurrentMarket().begin()->second->getCost() ? 
			0 : 
			-1;
	std::cout << choice << std::endl;
	return choice;
}

int PlayerBot::pass() { return -1; }

int PlayerBot::auction() { return -1; }

int PlayerBot::bidDecision(Marketplace* marketplace, Cards* card, int currentBid, int turn) {
	//std::cout << "In Player Bot" << std::endl;
	//Code below adds a delay (defined in Player.h) before output
	std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
	//If the bot has enough money, there's a 50% chance that it will bid +1 for the current card in auction
	int choice = turn == -1 ? //In this case, if turn is -1, it means that they started the auction and must bid something. They will bid the min value (Face value of card)
		currentBid :
		std::rand() % 100 < 50 && this->getPlayersMoney() > currentBid ? 
			currentBid + 1 : 
			-1;
	std::cout << choice << std::endl;
	return choice;
}

int PlayerBot::resourceDecision(std::vector<std::vector<Resource*>> resourceMarket) {

	
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

		//10% chance of skipping resource buying
		if (std::rand() % 100 < 10) {
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

		//50% chance that the bot would like to buy 2x the amount
		int firstPPResourceCost = targetPowerPlant->getResourceCost() * (std::rand() % 100 < 50? 1 : 2);

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

std::string PlayerBot::resourceType() {
	std::cout << this->resourceTypeToBuy << std::endl;
	return this->resourceTypeToBuy;
}

int PlayerBot::resourcePrice() {
	std::cout << this->resourcePriceToPay << std::endl;
	return this->resourcePriceToPay;
}

int PlayerBot::resourceAmount() {
	std::cout << this->resourceAmountToBuy << std::endl;
	return this->resourceAmountToBuy;
}

int PlayerBot::buildCityDecision(std::unordered_map<std::string, City*> cities) {
	//Done buying cities
	if (this->doneBuyingCities) {
		std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
		std::cout << "2 - Done buying" << std::endl;
		return 2;
	}
	else if (std::rand() % 100 < 10) {
		std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
		std::cout << "2 - RNG skip" << std::endl;
		return 2;
	}
	//Checks if enough money to buy a city
	else if (this->getPlayersMoney() < 10) {
		std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
		std::cout << "2 - Not enough money" << std::endl;
		return 2;
	}
	//If no cities, choose one at random
	else if (this->getCities().size() == 0) {

		//Put all the keys into a vector for rng selection
		std::vector<std::string> citiesString;
		for (auto name : cities) {
			citiesString.push_back(name.first);
		}

		this->cityToBuild = citiesString[std::rand() % citiesString.size()];


		std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
		std::cout << "1" << std::endl;
		return 1;
	}
	//If have existing cities, build one next to it
	else {
		std::vector<City*> playerCities = this->getCities();
		City* chosenCity = playerCities[std::rand() % playerCities.size()];
		std::unordered_map<City*, int> chosenCityNeighbours = chosenCity->getNeighbours();
		

		//Put all the keys into vector for rng selection
		std::vector<City*> neighbourToChoose;
		for (auto city : chosenCityNeighbours) {
			neighbourToChoose.push_back(city.first);
		}

		this->cityToBuild = neighbourToChoose[std::rand() % neighbourToChoose.size()]->getName();
		
		std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
		std::cout << "1" << std::endl;
		return 1;
	}

	return 2;
}

std::string PlayerBot::selectCity() {
	std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
	std::cout << this->cityToBuild << std::endl;

	//There's a 50% chance that they will stop buying more cities
	this->doneBuyingCities = std::rand() % 100 < 50 ? true : false;

	return this->cityToBuild;
}
