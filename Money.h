#pragma once
#ifndef MONEY_H
class Money
{
public:
	Money() {
		amount = 50;
	}
	int getMoney() {
		return amount;
	}
	void setMoney(int a) {
		if (a < 0) {
			//error cannot do
		}
		else
		{
			amount = a;
		}
	}
	/*
	* Return true if it is succesful, return false if it is not sucessful
	*/
	bool removeMoney(int a) {
		if (amount - a < 0) {
			return false;
		}
		else {
			amount = amount - a;
			return true;
		}
	}


private:
	int amount;
};
#define MONEY_H
#endif // MONEY_H