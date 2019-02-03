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

	//cout << "Hello World!" << endl;
	system("pause");
	return 0;
}
