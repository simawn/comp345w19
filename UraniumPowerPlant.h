
#pragma once
#include "CardsDecorator.h"
#include "Cards.h"
class UraniumPowerPlant :public CardsDecorator {
public:
	/** Constructor takes in an object of Card type*/
	UraniumPowerPlant(Cards * decoratedCards);
	/** display information of the given powerplant*/
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
