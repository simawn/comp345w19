#include "Player.h"
#include <iostream>

	Player::Player(){} //Added to prevent City.cpp errors

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
	void Player::pay(int amount) {
		if (money->removeMoney(amount)) {
			std::cout << "Succesfully payed for" << std::endl;
		}
		else {
			std::cout << "Cannot go into the negatives, try another purchase" << std::endl;
		}
	}

	Resource * Player::getResources() {
		return resource;
	}
	bool Player::buyResources(Resource * res) {
		resource = res;
		return true;
	}
	void Player::destroy() {
		delete money;
		delete house;
	}

