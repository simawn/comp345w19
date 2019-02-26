#include <iostream>
#include "../Player.h"
#include "../Coal.h"
#include "../PowerPlant.h"
using namespace std;

int main0000() {
	//set up
	cout << "Player testing" << endl;
	Player * p = new Player("RED");
	Player * p1 = new Player("BLUE");
	cout << "Colour: "<< p->getPlayerColour() << endl;
	cout << "Default Balance: " << p->getPlayersMoney() << endl;
	cout << "Colour: " << p1->getPlayerColour() << endl;
	cout << "Default Balance: " << p1->getPlayersMoney() << endl<<endl;
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
	Resource * res;
	Coal c(1);
	res = &c;
	p->buyResources(res);
	cout << "Value of " << res->getName()<<": "<< res->getValue() << endl<<endl;
	//power plant
	cout << "Power Plant testing" << endl;
	PowerPlant * pp;
	pp = new PowerPlant(1, 2, 1, &c);
	cout << "Power Plant" << endl << "cost: " << pp->getCost() << endl << "Resource cost: " << pp->getResourceCost() << endl <<
		"Housing cost: " << pp->getHouseValue() << endl << "Resource type: " << pp->getResourceType()->getName() << endl;
	//destruction
	p->destroy();
	p1->destroy();
	delete p;
	delete p1;
	system("pause");
	return 0;
}
