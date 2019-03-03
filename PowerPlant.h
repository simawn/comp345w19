#ifndef POWERPLANT_H
#define POWERPLANT_H
#include "Resources.h"
class PowerPlant {
private:
	int cost;/**<The cost of the given powerplant.*/
	int resource_cost;/**<The amount of resources it takes to power.*/
	int housing_value;/**<The amount of houses it powers.*/
	Resource * resource_type;/**<The type of resource that the powerplant uses.*/
public:
	/**Constructor to set up all the values.*/
	PowerPlant(int c, int rc, int hv, Resource * rt);
	/**Default constructor.*/
	PowerPlant();
	/**Get the cost of the given powerplant.*/
	int getCost();
	/**Get the amount of the given resource it costs.*/
	int getResourceCost();
	/**Get the housing amount that it powers.*/
	int getHouseValue();
	/**Get the resource type for the powerplant ie Coal.*/
	Resource * getResourceType();
};
#endif // !POWERPLANT_H
