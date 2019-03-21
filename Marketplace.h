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

	bool buy(int);

	void insert(Cards*);

	void remove(Cards*);
};