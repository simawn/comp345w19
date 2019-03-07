#include <iostream>
#include "GameDriver.h"
#include "GameMapDriver.h"
#include "GameMapLoaderDriver.h"
#include "CardCreationDriver.h"
#include "ResourcesLoaderDriver.h"
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
void TestResourceLoader() {
	cout << "\n === TESTING RESOURCE LOADER === \n";
	resourceLoaderDriver();
	cout << "\n === END TESTING RESOURCE LOADER  === \n";
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
	TestResourceLoader(); //Part3
	testPlayer(); //Part 4
	testCardCreation(); //Part 5
	system("pause");
	return 0;
}