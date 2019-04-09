#pragma once
#include "CardsDecorator.h"
#include "Cards.h"
class HybridPowerPlant :public CardsDecorator {
public:
	HybridPowerPlant(Cards * decoratedCards);
	void print();
	/**Get the cost of the given powerplant.*/
	int getCost();
	/**Get the amount of the given resource it costs.*/
	int getResourceCost();
	/**Get the housing amount that it powers.*/
	int getHouseValue();
	/**Get the resource type for the powerplant ie Coal.*/
	std::vector<Resource *> getResourceType();
};
