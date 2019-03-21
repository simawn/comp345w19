#include "PowerPlant.h"
PowerPlant::PowerPlant(){}
PowerPlant::PowerPlant(int c, int rc, int hv, Resource * rt,Resource * rt1) {
	cost = c;
	resource_cost = rc;
	housing_value = hv;
	resource_type.push_back(rt);
	resource_type.push_back(rt1);
}
PowerPlant::PowerPlant(int c, int rc, int hv, Resource * rt) {
	cost = c;
	resource_cost = rc;
	housing_value = hv;
	resource_type.push_back(rt);
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

std::vector<Resource *> PowerPlant::getResourceType() {
	return resource_type;
}