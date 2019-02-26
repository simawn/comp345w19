#include <iostream>
#include "GameDriver.h"
#include "GameMapDriver.h"
using namespace std;

/*USE THIS CLASS, CREATE A METHOD AND RUN TASKS FOR TESTING FOR EACH*/

//DONE
void testPlayer(){
	GameDriver();
}

void testMap() {
	GameMapDriver();
}

int main() {
	testPlayer();
	testMap();
	system("pause");
}