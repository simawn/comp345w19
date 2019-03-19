#include "House.h"

House::House(std::string c) {
	colour = c;
	amount = 22;
}
int House::placeHouse() {
	if (amount == 0) {
		return 0;
	}
	else {
		amount = amount - 1;
		return amount;
	}

}
int House::getHouseAmount() {
	return amount;
}
void House::setHouseAmount(int a) {
	amount = a;
}
std::string House::getColour() {
	return colour;
}