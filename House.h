#ifndef HOUSE_H
#define HOUSE_H
#include <string>
class House
{
private:
	std::string colour;/**< The colour of the house to associate with the player.*/
	int amount;/**<The amount of houses a player has.*/
public:
	/**Constructor, sets the colour of the house up for a player colour.*/
	House(std::string);
	/**Decrements the amount of houses by one and returns the new amount.*/
	int placeHouse();
	/**Gets the amount of houses a player has.*/
	int getHouseAmount();
	/**Sets the amount of houses, if necessary, might be removed.*/
	void setHouseAmount(int a);
	/**Gets the colour of a given player, their house colour.*/
	std::string getColour();
};
#endif // HOUSE_H