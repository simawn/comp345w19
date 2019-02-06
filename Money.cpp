#include "Money.h"
Money::Money() {
	amount = 50;
}
int Money::getMoney() {
	return amount;
}
void Money::setMoney(int a) {
	if (a < 0) {
		throw "Cannot have negative money";
	}
	else
	{
		amount = a;
	}
}
/*
* Return true if it is succesful, return false if it is not sucessful
*/
bool Money::removeMoney(int a) {
	if (amount - a < 0) {
		return false;
	}
	else {
		amount = amount - a;
		return true;
	}
}
