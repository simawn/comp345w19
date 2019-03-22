#include "../GameSetupDriver.h"
#include <iostream>
vector<Player> currentPlayers;//current players
GameMap gameMap;//current gamemap
/*To get the amount of players that will be playing*/
int getPlayerCount() {
	int playerCount;
	do {
		cout << "How many players will be playing the game? (2-6)" << endl;
		cin >> playerCount;
		if (!cin) {
			cout <<"Invalid entry please enter a number between 2 and 6"<<endl;
		}
		else if (playerCount < 2 || playerCount>6) {
			cout << "Invalid entry please enter a number between 2 and 6" << endl;
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
string selectorHelper(vector<string> arr) {
	int size = arr.size();
	int i = 1;
	for (string s : arr) {
		cout << i << ". " << s << endl;
		++i;
	}
	int selection;
	do {
		cin >> selection;
		if (!cin) {
			cout << "Invalid entry please enter a number between 1 and " << (size) << endl;
		}
		else if (selection < 1 || selection >size) {
			cout << "Invalid entry please enter a number between 1 and " << (size) << endl;
		}
	} while (selection < 1 || selection >size);
	string currSelection = arr[(selection - 1)];
	return currSelection;
}

string setColors(vector<string> colorArr) {
	cout << "The colours available are:" << endl;
	return selectorHelper(colorArr);
}

vector<Player> setUpPlayers() {
	const int pc = getPlayerCount();
	vector<Player> players;

	vector<string> colorArr = getColorArray();
	for (int i = 0; i < pc; ++i) {
		std::string s = setColors(colorArr);
		players.push_back(Player(s));
		auto itr = std::find(colorArr.begin(), colorArr.end(), s);
		colorArr.erase(itr);
	}
	currentPlayers=players;
	return players;
}
/*Places the resources on map based on the configuration loaded*/
void placeResourcesOnMap(){}

void loadPowerPlants() {}
void loadSummaryCards() {}
void loadStep3() {}

GameMap selectMap() {
	GameMap *gm = new GameMap();
	gm->loadMap();
	gameMap = *gm;
	return *gm;
}

void setUpStartingArea() {
	int pc = currentPlayers.size();
	std::vector<std::string> districts(gameMap.getAllDistricts(pc));

	for (Player p : currentPlayers) {
		string s = choosePlayableArea(p,districts);
		p.setStartingDistrict(s);
		auto itr = std::find(districts.begin(), districts.end(), s);
		districts.erase(itr);
	}
}
string choosePlayableArea(Player p, vector<string> districts) {	
	cout << p.getPlayerColour() <<  " choose your starting area: " << endl;
	return selectorHelper(districts);
}