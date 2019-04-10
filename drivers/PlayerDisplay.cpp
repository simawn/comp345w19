#include "playerDisplay.h"

PlayerDisplay::PlayerDisplay(Player* p) {
	pl = p;
}

PlayerDisplay::~PlayerDisplay()
{
	pl = nullptr;
}

void PlayerDisplay::notify()
{
	//batch script

	std::string info = "";

	info += " echo ==========" + pl->getPlayerColour() + "==========";
	info += " &echo Elektro " + std::to_string(pl->getPlayersMoney()) + "€";//displays th amount of money


	info += " &echo:";//displays each city a player owns
	info += " &echo Cities------- &echo \tID \tNAME";
	for (City* c : pl->getCities()) {
		info += "&echo \t" + std::to_string(c->getCityId());
		info += " \t" + c->getName();
	}

	info += " &echo:";//displays the amount of each resource a player owns
	info += " &echo Resources-------";
	info += " &echo \t Coal \t\t" + std::to_string(pl->totalPlayerResourcesOfType("Coal"));
	info += " &echo \t Gas \t\t" + std::to_string(pl->totalPlayerResourcesOfType("Gas"));
	info += " &echo \t Garbage \t" + std::to_string(pl->totalPlayerResourcesOfType("Garbage"));
	info += " &echo \t Uranium \t" + std::to_string(pl->totalPlayerResourcesOfType("Uranium"));

	info += " &echo:";//Segment displays all powerplants a player owns
	info += " &echo Powerplants-------";
	for (PowerPlant* pp : pl->getPowerPlants()) {
		info += " &echo \t#" + std::to_string(pp->getCost());
		info += " : Powers " + std::to_string(pp->getHouseValue());
		info += " : Fuels " + std::to_string(pp->getResourceCost());
		for (Resource * r : pp->getResourceType()) {
			info += " [" + r->getName();
		}
		info += "]";
	}
	info += " &echo ==========";
	system(("start \"PlayerStats - " + pl->getPlayerColour() + "\" cmd /C \" " + info + " & pause\"").c_str()); //opens a new window that displays all the information
}
