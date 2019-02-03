#pragma once
#ifndef MONEY_H
class Money
{
public:
	Money();
	int getMoney();
	void setMoney(int a);
	/*
	* Return true if it is succesful, return false if it is not sucessful
	*/
	bool removeMoney(int a);

private:
	int amount;
};
#define MONEY_H
#endif // MONEY_H