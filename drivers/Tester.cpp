#include <iostream>
#include "GameDriver.h"
#include "GameMapDriver.h"
#include "GameMapLoaderDriver.h"
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

int main() {
	testPlayer();
	testMap();
	testMapLoader();
	system("pause");
	return 0;
}