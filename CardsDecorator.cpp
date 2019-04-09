#include "CardsDecorator.h"
CardsDecorator::CardsDecorator(Cards * decoratedCard) {
	this->decoratedCard = decoratedCard;
}
void CardsDecorator::print() {
	 decoratedCard->print();
}
int CardsDecorator::getCost() {
	return decoratedCard->getCost();
}

int CardsDecorator::getResourceCost() {
	return decoratedCard->getResourceCost();
}

int CardsDecorator::getHouseValue() {
	return decoratedCard->getHouseValue();
}

std::vector<Resource *> CardsDecorator::getResourceType() {
	return decoratedCard->getResourceType();
}