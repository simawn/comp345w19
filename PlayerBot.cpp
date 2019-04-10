#include "PlayerBot.h"
#include <chrono>
#include <thread>

int PlayerBot::auctionDecision(Marketplace* marketplace, int turn) {
	std::cout << "In Player Bot" << std::endl;
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

int PlayerBot::bidDecision(Cards* card, int currentBid, int turn) {
	std::cout << "In Player Bot" << std::endl;
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

void PlayerBot::buyResource() {

}

void PlayerBot::buildCity() {

}

PlayerBot::~PlayerBot() {}
