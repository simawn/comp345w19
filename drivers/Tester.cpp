#include <iostream>
#include "GameDriver.h"
#include "GameMapDriver.h"
#include "GameMapLoaderDriver.h"
#include "CardCreationDriver.h"
using namespace std;



void testPlayer(){
	cout << "\n === START TESTING PLAYER === \n";
	GameDriver();
	cout << "\n === END TESTING PLAYER === \n";
}

void testMap() {
	cout << "\n === START TESTING MAP  === \n";
	GameMapDriver();
	cout << "\n === END TESTING MAP  === \n";
}

void testMapLoader() {
	cout << "\n === TESTING MAP LOADER === \n";
	GameMapLoaderDriver();
	cout << "\n === END MAP LOADER === \n";
}
void testCardCreation() {
	cout << "\n === TESTING CARD CREATION ===\n";
	createDeckCards();
	cout << "\n === END TESTING CARD CREATION ===\n";
}

int main() {
	
	testMap(); //Part 1
	testMapLoader(); //Part 2

	//testPlayer(); //Part 4
	//testCardCreation(); //Part 5
	system("pause");
	return 0;
}