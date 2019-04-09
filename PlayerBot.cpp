#include "PlayerBot.h"
#include <chrono>
#include <thread>

int PlayerBot::auctionDecision(Marketplace * marketplace) {
	//std::this_thread::sleep_for(std::chrono::milliseconds(this->DELAY + std::rand() % this->MAX_OFFSET));
	std::cout << "-1" << std::endl;
	return -1;

}

int PlayerBot::pass() {
	return -1;
}

int PlayerBot::auction() {
	return -1;
}

int PlayerBot::bidDecision(Cards * card, int currentBid)
{
	return 0;
}

void PlayerBot::buyResource() {
}

void PlayerBot::buildCity() {
}

PlayerBot::~PlayerBot()
{
}
