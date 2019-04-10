#include "PlayerBotEnvironmentalist.h"

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
