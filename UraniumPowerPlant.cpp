#include "UraniumPowerPlant.h"  
UraniumPowerPlant::UraniumPowerPlant(Cards * decoratedCards) :CardsDecorator(decoratedCards) {

}
void UraniumPowerPlant::print() {
	CardsDecorator::print();
	std::cout << "This powerplant is a UraniumPowerPlant \n";

}
int UraniumPowerPlant::getCost() {
	return CardsDecorator::getCost();

}
int UraniumPowerPlant::getResourceCost() {
	return CardsDecorator::getResourceCost();

}
int UraniumPowerPlant::getHouseValue() {
	return CardsDecorator::getHouseValue();
}
std::vector<Resource *>UraniumPowerPlant::getResourceType() {
	return CardsDecorator::getResourceType();
}