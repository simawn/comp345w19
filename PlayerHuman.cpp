#include "PlayerHuman.h"

int PlayerHuman::auctionDecision(Marketplace * marketplace) {
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

int PlayerHuman::bidDecision(Cards * card, int currentBid)
{
	return 0;
}

void PlayerHuman::buyResource()
{
}

void PlayerHuman::buildCity()
{
}

PlayerHuman::~PlayerHuman()
{
}
