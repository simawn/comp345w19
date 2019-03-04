#include <iostream>
#include "GameDriver.h"
#include "GameMapDriver.h"
#include "GameMapLoaderDriver.h"
#include "CardCreationDriver.h"
using namespace std;

/*USE THIS CLASS, CREATE A METHOD AND RUN TASKS FOR TESTING FOR EACH*/

//DONE
void testPlayer(){
	GameDriver();
}

void testMap() {
	GameMapDriver();
}

void testMapLoader() {
	cout << "\n === TESTING MAP LOADER === \n";
	GameMapLoaderDriver();
}
void testCardCreation() {
	cout << "\n === TESTING CARD CREATION ===\n";
	createDeckCards();

}

int main() {
	testPlayer();
	testMap();
	testMapLoader();
	testCardCreation();
	system("pause");
	return 0;
}