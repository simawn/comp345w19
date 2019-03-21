#ifndef POWERPLANT_H
#define POWERPLANT_H
#include "Resources.h"
#include "Cards.h"
#include <vector>
/**Class that represents the power plants, what resources they cost, how much they cost ans and the housing value*/
class PowerPlant:public Cards {
private:
	int cost;/**<The cost of the given powerplant.*/
	int resource_cost;/**<The amount of resources it takes to power.*/
	int housing_value;/**<The amount of houses it powers.*/
	std::vector<Resource *> resource_type;/**<The type of resource that the powerplant uses.*/
public:
	/**Constructor to set up all the values.*/
	PowerPlant(int c, int rc, int hv, Resource * rt);
	/**Constructor for two resorces*/
	PowerPlant(int c, int rc, int hv, Resource * rt, Resource * rt1);
	/**Default constructor.*/
	PowerPlant();
	/**Get the cost of the given powerplant.*/
	int getCost();
	/**Get the amount of the given resource it costs.*/
	int getResourceCost();
	/**Get the housing amount that it powers.*/
	int getHouseValue();
	/**Get the resource type for the powerplant ie Coal.*/
	std::vector<Resource *> getResourceType();
};
#endif // !POWERPLANT_H
