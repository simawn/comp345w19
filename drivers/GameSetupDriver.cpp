/* 
//The new player.cpp breaks this...


#include "../GameSetupDriver.h"
#include <iostream>
vector<Player> currentPlayers;//current players
GameMap gameMap;//current gamemap
vector<string>playing_districts;//the current playing districts for the game

								//To get the amount of players that will be playing
int getPlayerCount() {
	int playerCount;
	do {

		cout << "How many players will be playing the game? (2-6)" << endl;
		cin >> playerCount;
		if (!cin) {
			cout <<"Invalid entry please enter a number between 2 and 6"<<endl;
			playerCount = 0;
		}
		else if (playerCount < 2 || playerCount>6) {
			cout << "Invalid entry please enter a number between 2 and 6" << endl;
			playerCount = 0;
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
		cout << "Select: "; cin >> selection;
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

void placeResourcesOnMap(){
	std::vector<Coal*> TotalCoal(24);
	std::vector<Garbage*> TotalGarbage(24);
	std::vector<Gas*> TotalGas(24);
	std::vector<Uranium*> TotalUranium(12);
	for (int i = 0; i < 8; i++) {
		gameMap.addResource(i, 3, TotalCoal);
	}
	for (int i = 2; i < 8; i++) {
		gameMap.addResource(i, 3, TotalGas);
	}
	gameMap.addResource(6, 3, TotalGarbage);
	gameMap.addResource(7, 3, TotalGarbage);
	gameMap.addResource(13, 1, TotalUranium);
	gameMap.addResource(15, 1, TotalUranium);
}

GameMap selectMap() {
	GameMap * gm = new GameMap();
	gm->loadMap();
	gameMap = *gm;
	placeResourcesOnMap();
	return *gm;
}

void printResources() {
	gameMap.printResourceMarket();
}
void setUpStartingArea() {
	int pc = currentPlayers.size();
	std::vector<std::string> districts(gameMap.getAllDistricts());
	int max_districts;
	if (pc < 4) {
		max_districts = 3;
	}
	else if (pc < 5) {
		max_districts = 4;
	}
	else {
		max_districts = 5;
	}
	bool first_choice = true;
	for (int i = 0; i < max_districts; ++i) {
		if (first_choice) {
			cout << "Select the districts" << endl;
			playing_districts.push_back(selectorHelper(districts));
			first_choice = false;
		}
		else {
			std::vector<std::string> districts_adj(gameMap.getAdjacentRegions(playing_districts[(i - 1)]));
			for (string d : playing_districts) {
				auto itr = std::find(districts_adj.begin(), districts_adj.end(), d);
				if (itr != districts_adj.end()) {
					districts_adj.erase(itr);
				}
			}
			cout << "Select the districts" << endl;
			playing_districts.push_back(selectorHelper(districts_adj));
		}
	}
}
*/