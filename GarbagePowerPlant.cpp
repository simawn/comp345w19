#include "GarbagePowerPlant.h"  
GarbagePowerPlant::GarbagePowerPlant(Cards * decoratedCards) :CardsDecorator(decoratedCards) {

}
void GarbagePowerPlant::print() {
	CardsDecorator::print();
	std::cout << "This powerplant is a GarbagePowerPlant \n";

}
int GarbagePowerPlant::getCost() {
	return CardsDecorator::getCost();

}
int GarbagePowerPlant::getResourceCost() {
	return CardsDecorator::getResourceCost();

}
int GarbagePowerPlant::getHouseValue() {
	return CardsDecorator::getHouseValue();
}
std::vector<Resource *>GarbagePowerPlant::getResourceType() {
	return CardsDecorator::getResourceType();
}