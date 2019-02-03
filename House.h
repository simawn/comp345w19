#pragma once
#ifndef HOUSE_H
#define HOUSE_H
class House
{
private:
	char * colour;
	int amount;
public:
	House(char *c) {
		colour = c;
		amount = 22;
	}
	int placeHouse() {
		amount = amount - 1;
		return amount;
	}
	int getHouseAmount() {
		return amount;
	}
	void setHouseAmount(int a) {
		amount = a;
	}
};
#endif // HOUSE_H