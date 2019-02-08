#pragma once
#ifndef POWERPLANT_H
#define POWERPLANT_H
#include "Resources.h"
class PowerPlant {
private:
	int cost;
	int resource_cost;
	int housing_value;
	Resource * resource_type;
public:
	PowerPlant(int c, int rc, int hv, Resource * rt);
	int getCost();
	int getResourceCost();
	int getHouseValue();
	Resource * getResourceType();
};
#endif // !POWERPLANT_H
