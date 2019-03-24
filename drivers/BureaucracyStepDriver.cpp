#include "BureaucracyStepDriver.h"

std::vector<int> EoTSupply; //amount of Resources added at EoT. [Coal, Gas, Garbage, Uranium]

void doBureaucracy() {
	if (step == 1) { checkForStep2(); }
//	updateCardMarket();
	resupplyResourceMarket();
	//payPlayer();
	market.print();
}

void updateCardMarket() {
	market.remove(7);
}

void payPlayer() {
	int income = 10;
	/*
	learn how many cities are being powered.
	*/

}

void resupplyResourceMarket() {
	resourceTableSolution();
	//insert into the resource market according to the ammounts dictated by EoTSupply.
}


void checkForStep2() {};	//must be implemented

//consults the resource table and determins howmuch of each resource is going into the resource market.
void resourceTableSolution() {
	int noPlayers = 3;//currentPlayers.size;		doesn't work because of pointers?
	switch (noPlayers) {
	default: EoTSupply = { 0,0,0,0 }; break;
	case 2:
		if (step == 1) { EoTSupply = { 3,2,1,1 }; }
		if (step == 2) { EoTSupply = { 4,2,2,1 }; }
		if (step == 3) { EoTSupply = { 3,4,3,1 }; }
		break;
	case 3:
		if (step == 1) { EoTSupply = { 4,2,1,1 }; }
		if (step == 2) { EoTSupply = { 5,3,2,1 }; }
		if (step == 3) { EoTSupply = { 3,4,3,1 }; }
		break;
	case 4:
		if (step == 1) { EoTSupply = { 5,4,3,2 }; }
		if (step == 2) { EoTSupply = { 6,4,3,2 }; }
		if (step == 3) { EoTSupply = { 4,5,4,2 }; }
		break;
	case 5:
		if (step == 1) { EoTSupply = { 5,4,3,2 }; }
		if (step == 2) { EoTSupply = { 7,5,3,3 }; }
		if (step == 3) { EoTSupply = { 5,6,5,2 }; }
		break;
	case 6:
		if (step == 1) { EoTSupply = { 7,5,3,2 }; }
		if (step == 2) { EoTSupply = { 9,6,5,3 }; }
		if (step == 3) { EoTSupply = { 6,7,6,3 }; }
		break;
	}
}
