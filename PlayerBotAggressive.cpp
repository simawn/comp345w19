#include "PlayerBotAggressive.h"
#include <chrono>
#include <thread>

int PlayerBotAggressive::auctionDecision(Marketplace* marketplace) {
	//Code below adds a delay (defined in Player.h) before output
	std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
	//If the bot has enough money to buy the least expensive powerpoint, there's a 90% chance that it will put it in auction
	return std::rand() % 100 < 90 && this->getPlayersMoney() > marketplace->getCurrentMarket().begin()->second->getCost() ? 0 : -1;;
}

int PlayerBotAggressive::bidDecision(Cards * card, int currentBid) {
	//Code below adds a delay (defined in Player.h) before output
	std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
	//If the bot has enough money, there's a 95% chance that it will bid +1 for the current card in auction
	return std::rand() % 100 < 95 && this->getPlayersMoney() > currentBid ? currentBid + 1 : -1;
}

PlayerBotAggressive::~PlayerBotAggressive() {}
