#include "EcologicalPowerPlant.h"  
EcologicalPowerPlant::EcologicalPowerPlant(Cards * decoratedCards) :CardsDecorator(decoratedCards) {

}
void EcologicalPowerPlant::print() {
	CardsDecorator::print();
	std::cout << "This powerplant is a EcologicalPowerPlant \n";

}
int EcologicalPowerPlant ::getCost() {
	return CardsDecorator::getCost();

}
int EcologicalPowerPlant::getResourceCost() {
	return CardsDecorator::getResourceCost();

}
int EcologicalPowerPlant::getHouseValue() {
	return CardsDecorator::getHouseValue();
}
std::vector<Resource *>EcologicalPowerPlant::getResourceType() {
	return CardsDecorator::getResourceType();
}