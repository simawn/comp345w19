#include "PlayerBotEnvironmentalist.h"

//This bot focuses on clean powerpoint such as PP: 13, 18, 22, 27, 33, 37, 44, 50
int PlayerBotEnvironmentalist::auctionDecision(Marketplace* marketplace, int turn) {
	std::map<int, Cards*> currentMarket = marketplace->getCurrentMarket();
	//Checking if current market contains a clean powerplant
	int cleanPP = -1;
	for (int num : this->cleanPP) {
		if (currentMarket.count(num) > 0) {
			cleanPP = num;
			break;
		}
	}
	if (cleanPP != -1) {
		return cleanPP;
	}
	else {
		std::cout << "ENVIRONMENTAL: No clean PP found, going to normal behaviour" << std::endl;
		return PlayerBot::auctionDecision(marketplace, turn);
	}
}

int PlayerBotEnvironmentalist::bidDecision(Cards* card, int currentBid, int turn) {
	//Checking if card is clean
	bool isCleanPP = false;
	for (int num : this->cleanPP) {
		if (card->getCost() == num) {
			isCleanPP = true;
			break;
		}
	}
	if (isCleanPP) {
		return turn == -1 ? currentBid : currentBid + 1;
	}
	else {
		std::cout << "ENVIRONMENTAL: No clean PP found, going to normal behaviour" << std::endl;
		return PlayerBot::bidDecision(card, currentBid, turn);
	}
	return 0;
}

PlayerBotEnvironmentalist::~PlayerBotEnvironmentalist()
{

}
int PlayerBotEnvironmentalist::auctionDecision(Marketplace* marketplace) {
	for (std::map<int, Cards *>::iterator it = marketplace->getCurrentMarket().begin(); it != marketplace->getCurrentMarket().end();++it) {
		if (it->second->getResourceType().empty()) {
			return it->first;
		}
	}
	return -1;//pass
}
int PlayerBotEnvironmentalist::bidDecision(Cards* card, int currentBid) {
	if (card->getResourceType().empty()) {
		return currentBid + 1;
	}
	else {
		return -1;//pass
	}
}
