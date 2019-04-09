#include "CoalPowerPlant.h"
CoalPowerPlant::CoalPowerPlant(Cards * decoratedCards):CardsDecorator(decoratedCards){

}
void CoalPowerPlant::print() {
	CardsDecorator::print();
	std::cout << "This powerplant is a CoalPowerPlant \n";

}
int CoalPowerPlant :: getCost() {
	return CardsDecorator::getCost();

}
int CoalPowerPlant :: getResourceCost() {
	return CardsDecorator::getResourceCost();

}
int CoalPowerPlant :: getHouseValue() {
	return CardsDecorator::getHouseValue();
}
std::vector<Resource *>CoalPowerPlant :: getResourceType() {
	return CardsDecorator::getResourceType();
}