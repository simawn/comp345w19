#include "../GameSetupDriver.h"
#include <iostream>

/*To get the amount of players that will be playing*/
int getPlayerCount() {
	int playerCount;
	do {
		cout << "How many players will be playing the game? (2-6)" << endl;
		cin >> playerCount;
		if (!cin) {
			cout <<"Invalid entry please enter a number between 2 and 6"<<endl;
		}
	} while (playerCount < 2 || playerCount>6);
	return playerCount;
}
vector<string> getColorArray() {
	vector<string> colorArr;
	colorArr.push_back("Green");
	colorArr.push_back("Blue");
	colorArr.push_back("Red");
	colorArr.push_back("Purple");
	colorArr.push_back("Black");
	colorArr.push_back("Yellow");
	return colorArr;
}
std::string setColors(int size,vector<string> colorArr) {
	cout << "The colours available are:" << endl;
	for (int i = 1; i <= size; ++i) {
		cout<< i <<". " << colorArr[(i - 1)] << endl;
	}
	int color;
	cin >> color;
	string currColor = colorArr[(color-1)];
	return currColor;
}

vector<Player> setUpPlayers() {
	const int pc = getPlayerCount();
	vector<Player> players;

	vector<string> colorArr = getColorArray();
	int size = 6;
	for (int i = 0; i < pc; ++i) {
		std::string s = setColors(size, colorArr);
		players.push_back(Player(s));
		--size;
		auto itr = std::find(colorArr.begin(), colorArr.end(), s);
		colorArr.erase(itr);
	}
	return players;
}
/*Places the resources on map based on the configuration loaded*/
void placeResourcesOnMap(){}

void loadPowerPlants() {}
void loadSummaryCards() {}
void loadStep3() {}

GameMap selectMap() {
	GameMap *gm = new GameMap();
	return *gm;
}


void choosePlayableArea(Player p,GameMap gm) {
	
}