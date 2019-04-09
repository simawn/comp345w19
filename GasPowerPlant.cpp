#include "GasPowerPlant.h"
GasPowerPlant::GasPowerPlant(Cards * decoratedCards) :CardsDecorator(decoratedCards) {

}
void GasPowerPlant::print() {
	CardsDecorator::print();
	std::cout << " This powerplant is of a GasPowerPlant\n";

}
int GasPowerPlant :: getCost() {
	return CardsDecorator::getCost();
}

int GasPowerPlant :: getResourceCost() {
	return CardsDecorator::getResourceCost();
}

int GasPowerPlant :: getHouseValue() {
	return CardsDecorator::getHouseValue();
}

std::vector<Resource *> GasPowerPlant :: getResourceType() {
	return CardsDecorator::getResourceType();
}