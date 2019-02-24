#include <iostream>
#include "Player.h"
#include "Coal.h"
#include "PowerPlant.h"
#include "City.h"
#include "GameMap.h"
#include "Uranium.h"
using namespace std;


//DONE
void testPlayer(){

	//set up
	cout << "Player testing" << endl;
	Player * p = new Player("RED");
	Player * p1 = new Player("BLUE");
	cout << "Colour: " << p->getPlayerColour() << endl;
	cout << "Default Balance: " << p->getPlayersMoney() << endl;
	cout << "Colour: " << p1->getPlayerColour() << endl;
	cout << "Default Balance: " << p1->getPlayersMoney() << endl << endl;
	//paying
	cout << "Paying testing" << endl;
	cout << "Colour: " << p->getPlayerColour() << " tried to pay 51" << endl;
	p->pay(51);
	cout << "Balance: " << p->getPlayersMoney() << endl;
	cout << "Colour: " << p->getPlayerColour() << " tried to pay 5" << endl;
	p->pay(5);
	cout << "Balance: " << p->getPlayersMoney() << endl << endl;
	//resources
	cout << "Resource testing" << endl;
	Coal c(1);
	Coal c1(2);
	p->buyResources(&c);
	p->buyResources(&c1);
	Uranium u(1);
	p->buyResources(&u);
	std::vector<Resource *> r = p->getResources();
	for (int i = 0; i < r.size(); ++i) {
		cout << "Resource Value of " << r[i]->getName() << ": " << r[i]->getValue() << endl;
	}
	p->placeResource("Coal");
	cout << "testing placing a resource" << endl;
	std::vector<Resource *> r1 = p->getResources();
	for (int i = 0; i < r1.size(); ++i) {
		cout << "Resource Value of " << r1[i]->getName() << ": " << r1[i]->getValue() << endl;
	}
	cout << "Balance: " << p->getPlayersMoney() << endl << endl;

	cout << endl << endl;
	//power plant
	cout << "Power Plant testing" << endl;
	PowerPlant * pp;
	pp = new PowerPlant(1, 2, 1, &c);
	p->buyPowerPlant(pp);
	cout << "Power Plant" << endl << "cost: " << pp->getCost() << endl << "Resource cost: " << pp->getResourceCost() << endl <<
		"Housing cost: " << pp->getHouseValue() << endl << "Resource type: " << pp->getResourceType()->getName() << endl;
	cout << "Balance: " << p->getPlayersMoney() << endl << endl;

	cout << "Cities testing" << endl << endl;
	City city("Johanesburg");
	City city1("St. Petersburg");
	City city2("Moscow");
	p->buyCity(&city);
	p->buyCity(&city1);
	p->buyCity(&city2);
	cout << "Cities that belong to Player: " << p->getPlayerColour() << endl;
	std::vector<City *> c_arr = p->getCities();
	for (int i = 0; i < c_arr.size(); ++i) {
		cout << "City of " << c_arr[i]->getName() << ": " << c_arr[i]->getValue() << endl;
	}
	cout << "Balance: " << p->getPlayersMoney() << endl << endl;
	cout << endl;
	//destruction
	p->destroy();
	p1->destroy();
	delete p;
	delete p1;
	//system("pause");
	//return 0;
}

void testMap() {

	cout << "************" << endl<< "Testing Map" << endl;
	//Create cities
	City city1;
	City city2;
	City city3;

	std::cout << city1.getCityId() << std::endl;
	std::cout << city2.getCityId() << std::endl;
	std::cout << city3.getCityId() << std::endl;

	//Create game map
	GameMap gameMap;

	//Add cities to game map
	gameMap.addCity(&city1);
	gameMap.addCity(&city2);
	gameMap.addCity(&city3);

	gameMap.displayAllCities();

	//Add neighbours + weight
	/*
	1 --10--> 2 --20--> 3
	2 --40--> 1
	3 --69--> 1
	*/

	city1.addNeighbour(&city2, 10);
	city2.addNeighbour(&city3, 20);
	city2.addNeighbour(&city1, 40);
	city3.addNeighbour(&city1, 69);

	city1.displayAllNeighbours();
	city2.displayAllNeighbours();
	city3.displayAllNeighbours();

	//std::cin.get();
}

int main() {
	testPlayer();
	testMap();
	system("pause");
}