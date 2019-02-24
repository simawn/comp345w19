#include "Money.h"
/*Constructor for the money, holds an int starting always at 50*/
Money::Money() {
	amount = 50;
}
/*Gets the amount of money*/
int Money::getMoney() {
	return amount;
}
/*Sets the money, checks if less than 0*/
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
* Removes the amount passed if succesful otherwise can't perform the action
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
