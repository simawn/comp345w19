#pragma once
#include "../Observer.h"
#include <vector>
#include <string>
#include "../Player.h"
#include "../City.h"
#include "../PowerPlant.h"


/*
Using the Observer design pattern, implement a view that displays some useful statistics about the game,
the minimum being:
	each player location, and procession view that shows using some kind of bar graph depicting what city is currently being o by each player, each player resources, etc. 
This should dynamically be updated as the map state changes and be visible at all times during game play.

TODO

PLAYER commands changed:
	income
	buypowerplant
	buycitiy
	buyresource
	placeresource
*/

class PlayerDisplay : public Observer {
private:
	Player * pl;
public:
	/*constructor for observer*/
	PlayerDisplay(Player* p);
	/*destructor for observer*/
	~PlayerDisplay();

	/*generates a new window with updated info for that player*/
	void notify();

};