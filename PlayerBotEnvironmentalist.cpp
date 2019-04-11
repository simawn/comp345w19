#include "PlayerBotEnvironmentalist.h"
#include <chrono>
#include <thread>

//This bot focuses on clean powerpoint such as PP: 13, 18, 22, 27, 33, 37, 44, 50
int PlayerBotEnvironmentalist::auctionDecision(Marketplace* marketplace, int turn) {
	//Code below adds a delay (defined in Player.h) before output
	std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));

	std::map<int, Cards*> currentMarket = marketplace->getCurrentMarket();
	//Checking if current market contains a clean powerplant
	int cleanPP = -1;
	for (int num : this->cleanPP) {
		if (currentMarket.count(num) > 0) {
			//check if enough money to buy
			if (this->getPlayersMoney() >= currentMarket[num]->getCost()) {
				//Using distance since the auction only takes 0..3 as an input and not the actual PP cost
				cleanPP = distance(currentMarket.begin(), currentMarket.find(num));
				break;
			}
		}
	}
	if (cleanPP != -1) { //Returns clean choice
		std::cout << cleanPP << std::endl;
		return cleanPP;
	} else {
		std::cout << "ENVIRONMENTAL: No clean PowerPlant found, going to normal behaviour" << std::endl;
		return PlayerBot::auctionDecision(marketplace, turn);
	}
}

int PlayerBotEnvironmentalist::bidDecision(Marketplace* marketplace, Cards* card, int currentBid, int turn) {
	//Code below adds a delay (defined in Player.h) before output
	std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));

	//Checking if card is clean
	bool isCleanPP = false;
	for (int num : this->cleanPP) {
		if (card->getCost() == num) {
			isCleanPP = true;
			break;
		}
	}

	//Checking if current market has a clean powerplant
	bool hasCleanPP = false;
	for (int num : this->cleanPP) {
		if (marketplace->getCurrentMarket().count(num) > 0) {
			hasCleanPP = true;
			break;
		}
	}

	//If it is a clean PowerPlant, bid
	if (isCleanPP) { 
		int bidAmount = -1;

		if (turn == -1) { //Turn -1 means that they have started the auction and must bid something
			bidAmount = currentBid;
		}
		else if (this->getPlayersMoney() > currentBid && std::rand() % 100 < 95) { //If player has enough money, there's a 95% chance of bidding +1
			bidAmount = currentBid + 1;
		}
		
		std::cout << bidAmount << std::endl;
		return bidAmount;
	}
	//If the bot sees a clean powerplant in the current market, skips all bids
	else if (hasCleanPP) {
		std::cout << "-1" << std::endl;
		return -1;
	}
	//If not go back to default bot behaviour
	else {
		std::cout << "ENVIRONMENTAL: No clean PowerPlant found, going to normal behaviour" << std::endl;
		return PlayerBot::bidDecision(marketplace, card, currentBid, turn);
	}
	return 0;
}

PlayerBotEnvironmentalist::~PlayerBotEnvironmentalist() {}
