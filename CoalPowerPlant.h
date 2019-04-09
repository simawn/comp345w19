#pragma once
#include "CardsDecorator.h"
#include "Cards.h"
class CoalPowerPlant :public CardsDecorator {
public:
	CoalPowerPlant(Cards * decoratedCards);
	void print();
};