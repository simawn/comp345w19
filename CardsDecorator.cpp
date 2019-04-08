#include "CardsDecorator.h"
CardsDecorator::CardsDecorator(Cards * decoratedCard) {
	this->decoratedCard = decoratedCard;
}
void CardsDecorator::print() {
	 decoratedCard->print();
}