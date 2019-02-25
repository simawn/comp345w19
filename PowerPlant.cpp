#include "PowerPlant.h"
/*Default Constructor*/
PowerPlant::PowerPlant(){}
/*Sets the cost of the PowerPlant, Resource cost, House value and the resource type(s)*/
PowerPlant::PowerPlant(int c, int rc, int hv, Resource * rt) {
	cost = c;
	resource_cost = rc;
	housing_value = hv;
	resource_type = rt;
}
/*Gets teh cost of the house*/
int PowerPlant::getCost() {
	return cost;
}
/*Gets the amount of houses it will power*/
int PowerPlant::getHouseValue() {
	return housing_value;
}
/*Gets how many resources it will cost*/
int PowerPlant::getResourceCost() {
	return resource_cost;
}
/*Gets the type(s) of resource it costs*/
Resource * PowerPlant::getResourceType() {
	return resource_type;
}