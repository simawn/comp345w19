#include "Player.h"

	Player::Player(const char* c){
		house = new House(c);
		money = new Money();
	}
	int Player::getPlayersMoney() {
		return money->getMoney();
	}
	const char* Player::getPlayerColour() {
		return house->getColour();
	}

