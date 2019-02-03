#pragma once
#ifndef HOUSE_H
#define HOUSE_H
class House
{
private:
	const char * colour;
	int amount;
public:
	House(const char *c);
	int placeHouse();
	int getHouseAmount();
	void setHouseAmount(int a);
	const char * getColour();
};
#endif // HOUSE_H