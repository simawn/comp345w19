#ifndef PLAYER_H
#define PLAYER_H
#include "Money.h"
#include "House.h"
#include "Resources.h"
#include "City.h"
#include "PowerPlant.h"
#include <vector>
#include <string>
#include "SummaryCard.h"
#include "Subject.h"
#include "Cards.h"
#include "Marketplace.h"
#include "PhaseObserver.h"

/**Class that represents a player, playable character in the game*/
class Player: public Subject{
protected: //DELAY and MAX_OFFSET are used by bot players
	const int DELAY = 300; /*Minimum break in ms before bot outputs its decision. Faking that the bot is thinking*/
	const int MAX_OFFSET = 200; /*Maximum additional offset in ms for break. To add randomness*/
private:
	std::vector<Resource *> resources;/**<The resources that a given player has.*/
	std::vector<City *> cities;/**<The cities that a player owns.*/
	std::vector<PowerPlant *> powerplants;/**<The power plants that a player has.*/
	Money* money;/**<The money pointer for money management.*/
	House* house;/**<The house pointer for the house management, colour and amounts.*/
	SummaryCard sc;/**<The summary for the player*/
	std::vector<Observer *> observers;
	std::string currentStep;/**<Says what the current step is*/
	PhaseObserver pObs;/**<The phase observer*/
	/**notify observer for the phase*/
	void notifyObserver(std::string phase, std::string action);

public:
	/**Default constructor.*/
	Player(); //Added to prevent City.cpp errors
	/**Set the player up with their colour.*/
	Player(std::string);
	/**Get the amount of money a player has.*/
	int getPlayersMoney();
	/**Get the colour for a given player set up for their house.*/
	std::string getPlayerColour();
	/**Pay for something, may be deprecated in the next release.*/
	void pay(int amount);
	/**Destructor.*/
	void destroy();
	/**The the resource for the player by type, ie coal.*/
	Resource * getResourceByType(std::string);
	/**Get all the resources that a player owns.*/
	std::vector<Resource *> getResources();
	/**Buy a resource for a given player.*/
	bool buyResources(Resource * res);
	/**PLace a resource, ie remove a resource for the player.*/
	Resource * placeResource(std::string res);
	/**Get all the cities a player owns.*/
	std::vector<City *> getCities();
	/**Buy a city and add it to the owned cities.*/
	bool buyCity(City * city);
	/**Get all the power plants that a player owns.*/
	std::vector<PowerPlant *> getPowerPlants();
	/**Buy a power plant for the player.*/
	bool buyPowerPlant(PowerPlant *pp);
	/**Buy a power plant for a custom amount (Auction)*/
	bool buyPowerPlant(PowerPlant * pp, int cost);
	/**Set the colour of the player*/
	void setPlayerColor(std::string c);
	/**Return the number of power plants a player possesses*/
	int getNbPowerPlants();
	/**Returns the power plant with the highest cost that a player possesses*/
	int getLargestNbPowerPlant();
	/**Operator overload for Player comparison*/
	const bool operator==(Player & other);
	/**Operator overload for Player comparison*/
	const bool operator!=(Player & other);
	/**Prints the player's Name, Money, Cities, PowerPlants*/
	void printPlayerInfo();
	/**Get the summary card for the given player*/
	SummaryCard getSummaryCard();
	/**Set the current step*/
	void setCurrentStep(std::string step);
	/**Pays the player*/
	void income(int a);
	/**Returns the amount a player has of a given resource*/
	int totalPlayerResourcesOfType(std::string);
	/**prints the resources the player has available*/
	void printResources();
/**Find the weight between citites for cost*/
	int findCityConnectingCost(City* city);

	/*The methods below will be implemented by PlayerBot and PlayerHuman*/
	 void attachObserver(Observer* o) override;
	 void notifyObservers() override;
	 void removeObserver(Observer* o) override;
	//During auction phase
	virtual int auctionDecision(Marketplace* marketplace, int turn) = 0;
	virtual int pass() = 0;
	virtual int auction() = 0;
	virtual int bidDecision(Marketplace* marketplace, Cards* card, int currentBid, int turn) = 0;
	
	//During resource buying phase
	virtual int resourceDecision(std::vector<std::vector<Resource*>> resourceMarket) = 0;
	virtual std::string resourceType() = 0;
	virtual int resourcePrice() = 0;
	virtual int resourceAmount() = 0;

	//During city building phase
	virtual int buildCityDecision(std::unordered_map<std::string, City*> cities) = 0;
	virtual std::string selectCity() = 0;

	//Destructor for Player
	virtual ~Player();
};
#endif // !PLAYER_H
