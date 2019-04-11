#include "PlayerHuman.h"

int PlayerHuman::auctionDecision(Marketplace * marketplace, int turn) {
	int choice;
	std::cin >> choice;
	return choice;
}

int PlayerHuman::pass() {
	return -1;
}

int PlayerHuman::auction() {
	return -1;
}

int PlayerHuman::bidDecision(Marketplace* marketplace, Cards * card, int currentBid, int turn) {
	int choice;
	std::cin >> choice;
	return choice;
}

int PlayerHuman::resourceDecision(std::vector<std::vector<Resource*>> resourceMarket)
{
	int choice;
	std::cin >> choice;
	return choice;
}

std::string PlayerHuman::resourceType()
{
	std::string choice;
	std::cin >> choice;
	return choice;
}

int PlayerHuman::resourcePrice()
{
	int choice;
	std::cin >> choice;
	return choice;
}

int PlayerHuman::resourceAmount()
{
	int choice;
	std::cin >> choice;
	return choice;
}

int PlayerHuman::buildCityDecision(std::unordered_map<std::string, City*> cities)
{
	int choice;
	std::cin >> choice;
	return choice;
}

std::string PlayerHuman::selectCity()
{
	std::string choice;
	std::cin >> choice;
	return choice;
}