#include <iostream>
#include "Player.h"
using namespace std;
/*To get the amount of players that will be playing*/
int getPlayerCount() {
	int playerCount;
	cout << "How many players will be playing the game? (2-6)"<<endl;
	cin >> playerCount;
	return playerCount;
}

const char * setPlayerColours(int pn) {
	//Player players[4];
	cout << "The colours available are:" << endl <<
		"1. Blue" << endl <<
		"2. Red" << endl <<
		"3. Purple" << endl <<
		"4. Black" << endl <<
		"5. Yellow" << endl <<
		"6. Green" << endl;
	int colour;
	cout << "Player " << pn << " colour?" << endl;
	cin >> colour;
	switch (colour)
	{
		case 1:
		return "Blue";
		break;
		case 2:
			return "Red";
			break;
		case 3:
			return "Purple";
			break;
		case 4:
			return "Black";
			break;
		case 5:
			return "Yellow";
			break;
		case 6:
			return "Green";
			break;
	default:
		
		break;
	}
}

/*Places the resources on map based on the configuration loaded*/
void placeResourcesonMap(){}
