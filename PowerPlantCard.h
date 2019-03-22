#pragma once
#include "Resources.h"
#include <vector>
#include "Cards.h"
class PowerPlantCard:public Cards{
public:
	/**Max Cities Supplied
	*@return max nb cities it can supply
	* Getter
	*/
	int getmaxCitiesSupplied();
	/**Card number
	*@return Number identifier of the card
	*Getter
	*/
	int getCardNumber();
	/**Number of Resource Needed
	*@return Sum of nb of ressource needed
	*Getter
	*/
	int getNbResourceNeeded();
	/**Type of Ressource Needed
	@return Vector containing one type per index
	*Getter
	*/
	std::vector<std::string> getRessourcesNeeded();
	/**
	* Max Nb of cities it can supply
	*/
	int maxCitiesSupplied;
	/**
	*Card nb identifier
	*/
	int cardNumber;
	/**
	* Vector containing type of resource needed
	*/
	std::vector<std::string> resourcesNeeded;
	/**
	*Total number of resource needed
	*/
	int nbResourceNeeded;
	/**
	*@param cards nb identifier
	*@param max cities it can supply
	*@param number of resource it needs
	
	*constructor
	*/
	PowerPlant(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded);

	/**
	*@param cards nb identifier
	*@param max cities it can supply
	*@param number of resource it needs
	@param type of resource needed
	*constructor
	*/
	
	PowerPlant(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded,std::string resource1 );
	/**
	*@param cards nb identifier
	*@param max cities it can supply
	*@param number of resource it needs
	@param type of resource needed
	@param type of resource needed
	*constructor
	*/
	PowerPlant(int cardNumber, int maxCitiesSupplied, int nbResourceNeeded, std::string resource1, std::string resource2);
	
	/**print
	* Output class objects details
	*/
	virtual void print();
};