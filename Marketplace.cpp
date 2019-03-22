#include "Marketplace.h"
#include "PowerPlant.h"
#include "Cards.h"

Marketplace::Marketplace(Deck* deck) {
	this->deck = deck; //For further deck calls
	
	for (Cards* card : deck->getInitialCards()) {
		this->insert(card);
	}
}

void Marketplace::insert(Cards* card) {
	market[card->getCost()] = card;
}

void Marketplace::remove(int cardCost) { //On remove, insert new card immediately
	market.erase(cardCost);
	std::cout << "Removed: " << cardCost << std::endl;
	if (deck->size() != 0) {
		Cards* newCard = deck->draw();
		this->insert(newCard);
		std::cout << "Inserted: " << newCard->getCost() << std::endl;
	}
}

void Marketplace::print() {
	std::cout << "=== Current market: ===" << std::endl;
	int i = 0; //This is a shady way of limiting loop with an iterator...
	for (auto it = market.begin(); it != market.end(); it++) {
		if (i == 4) break;
		it->second->print();
		i++;
	}
	std::cout << "=== Future market: ===" << std::endl;
	for (auto it = market.begin(); it != market.end(); it++) {
		i--;
		if (i >= 0) continue;
		it->second->print();
	}
}

std::map<int, Cards*> Marketplace::getMarket() {
	return this->market;
}
