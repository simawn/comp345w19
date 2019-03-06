#ifndef MONEY_H
#define MONEY_H
/**Class to represent money*/
class Money
{
public:
	/**Constructor, set up the default amount of 50 at the beginning of setting up a player.*/
	Money();
	/**Get the amount of money that a player has.*/
	int getMoney();
	/**Set the amount of money for a plyer will be transormed into simply adding onto the current amount.*/
	void setMoney(int a);
	/*
	* Return true if it is succesful, return false if it is not sucessful.
	* Removes the amount passed if succesful otherwise can't perform the action.
	*/
	bool removeMoney(int a);

private:
	int amount;/**<The amount of money that there is for that player cannot go below zero.*/
};

#endif // MONEY_H