#pragma once
#include <map>
#include "Cards.h"
#include "Deck.h"
#include "PowerPlant.h"

class Marketplace {
	std::map<int, Cards*> market; //Using map to keep card order
	Deck* deck;
public:
	Marketplace(Deck*);

	void insert(Cards*);

	void remove(int);

	void print();

	std::map<int, Cards*> getMarket();

	std::map<int, Cards*> getCurrentMarket();

	Cards* getCard(int);
};