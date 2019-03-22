#pragma once
#include <iostream>
#include <vector>
#include "Resources.h"

class Cards {
public:
	/**Get the cost of the given powerplant.*/
	virtual int getCost() = 0;
	/**Get the amount of the given resource it costs.*/
	virtual int getResourceCost() = 0;
	/**Get the housing amount that it powers.*/
	virtual int getHouseValue() = 0;
	/**Get the resource type for the powerplant ie Coal.*/
	virtual std::vector<Resource *> getResourceType() = 0;
	/**Print function*/
	virtual void print() {};
};