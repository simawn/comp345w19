#include "PlayerBotAggressive.h"
#include <chrono>
#include <thread>

int PlayerBotAggressive::auctionDecision(Marketplace* marketplace, int turn) {
	//Code below adds a delay (defined in Player.h) before output
	std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
	//If it is the first turn, bot will put the first powerplant in auction
	//If the bot has enough money to buy the least expensive powerpoint, there's a 90% chance that it will put it in auction
	int choice = turn == 1 ? 
		0 : 
		std::rand() % 100 < 90 && this->getPlayersMoney() > marketplace->getCurrentMarket().begin()->second->getCost() ? 
			0 : 
			-1;
	std::cout << choice << std::endl;
	return choice;
}

int PlayerBotAggressive::bidDecision(Marketplace* marketplace, Cards * card, int currentBid, int turn) {
	//Code below adds a delay (defined in Player.h) before output
	std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
	//If the bot has enough money, there's a 95% chance that it will bid +1 for the current card in auction

	int choice = turn == -1 ? //In this case, if turn is -1, it means that they started the auction and must bid something. They will bid the min value (Face value of card)
		currentBid :
		std::rand() % 100 < 95 && this->getPlayersMoney() > currentBid ?
		currentBid + 1 : 
		-1;
	std::cout << choice << std::endl;
	return choice;
}

PlayerBotAggressive::~PlayerBotAggressive() {}
