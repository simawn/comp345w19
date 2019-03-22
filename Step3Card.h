#pragma once
#include "Cards.h"
#include "Resources.h"

class Step3Card :public Cards {
public:
	/**Step3Card
	*Default constructor
	*/
	Step3Card();
	/**Get the cost of the given powerplant.*/
	int getCost() { return -1; };
	/**Get the amount of the given resource it costs.*/
	int getResourceCost() { return -1; };
	/**Get the housing amount that it powers.*/
	int getHouseValue() { return -1; };
	/**Get the resource type for the powerplant ie Coal.*/
	std::vector<Resource *> getResourceType() { return std::vector<Resource*>(); };
	/**Print function*/
	void print();
};