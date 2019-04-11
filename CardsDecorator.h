#pragma once
#include "Cards.h";
class CardsDecorator :public Cards {
protected: 
	Cards *decoratedCard;
public:
	/**Decorator constructor */
	CardsDecorator(Cards * decoratedCard);
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
