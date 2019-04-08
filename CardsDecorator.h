#pragma once
#include "Cards.h";
class CardsDecorator :Cards {
protected: 
	Cards *decoratedCard;
public:
	CardsDecorator(Cards * decoratedCard);
	void print();
};