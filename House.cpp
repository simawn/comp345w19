#include "House.h"
/*Constructor for house, sets the colour*/
House::House(const char *c) {
	colour = c;
	amount = 22;
}
/*Decrements the amount of houses and returns the new amount*/
int House::placeHouse() {
	if (amount == 0) {
		return 0;
	}
	else {
		amount = amount - 1;
		return amount;
	}

}
/*Gets the amount of houses that are left*/
int House::getHouseAmount() {
	return amount;
}
/*Sets the amount of houses for the player*/
void House::setHouseAmount(int a) {
	amount = a;
}
/*Gets the colour of the house*/
const char * House::getColour() {
	return colour;
}