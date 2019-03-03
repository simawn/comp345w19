#include "PowerPlant.h"
PowerPlant::PowerPlant(){}
PowerPlant::PowerPlant(int c, int rc, int hv, Resource * rt) {
	cost = c;
	resource_cost = rc;
	housing_value = hv;
	resource_type = rt;
}

int PowerPlant::getCost() {
	return cost;
}

int PowerPlant::getHouseValue() {
	return housing_value;
}

int PowerPlant::getResourceCost() {
	return resource_cost;
}

Resource * PowerPlant::getResourceType() {
	return resource_type;
}