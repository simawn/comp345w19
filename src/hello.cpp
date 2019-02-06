#include <iostream>
#include "../Player.h"
using namespace std;

int main() {

	Player * p = new Player("RED");
	Player * p1 = new Player("BLUE");
	cout << "Colour: "<< p->getPlayerColour() << endl;
	cout << "Default Balance: " << p->getPlayersMoney() << endl;
	cout << "Colour: " << p1->getPlayerColour() << endl;
	cout << "Default Balance: " << p1->getPlayersMoney() << endl;
	p->pay(51);	
	cout << "Colour: " << p->getPlayerColour() << " tried to pay 51"<<endl;
	cout << "Balance: " << p->getPlayersMoney() << endl;
	p->pay(5);
	cout << "Colour: " << p->getPlayerColour() << " tried to pay 5" << endl;
	cout << "Balance: " << p->getPlayersMoney() << endl;
	p->destroy();
	p1->destroy();
	delete p;
	delete p1;
	system("pause");
	return 0;
}
