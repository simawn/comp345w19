#include "HybridPowerPlant.h"  
HybridPowerPlant::HybridPowerPlant(Cards * decoratedCards) :CardsDecorator(decoratedCards) {

}
void HybridPowerPlant::print() {
	CardsDecorator::print();
	std::cout << "This powerplant is a HybridPowerPlant \n";

}
int HybridPowerPlant::getCost() {
	return CardsDecorator::getCost();

}
int HybridPowerPlant::getResourceCost() {
	return CardsDecorator::getResourceCost();

}
int HybridPowerPlant::getHouseValue() {
	return CardsDecorator::getHouseValue();
}
std::vector<Resource *>HybridPowerPlant::getResourceType() {
	return CardsDecorator::getResourceType();
}