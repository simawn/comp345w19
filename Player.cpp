#include "House.h"
#include "Money.h"
class Player
{

private:
	House* house;
	Money* money;
public:
	Player(char* c){
		house = new House(c);
		money = new Money();
	}

};
