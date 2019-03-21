#pragma once
#include <iostream>
class Cards {
public:
	/**print
	*output class object description
	*/
	virtual void print();

	/**Max Cities Supplied
	*@return max nb cities it can supply
	* Getter
	*/
	virtual int getmaxCitiesSupplied();
	/**Card number
	*@return Number identifier of the card
	*Getter
	*/
	virtual int getCardNumber();
	/**Number of Resource Needed
	*@return Sum of nb of ressource needed
	*Getter
	*/
	virtual int getNbResourceNeeded();
	/**Type of Ressource Needed
	@return Vector containing one type per index
	*Getter
	*/
	virtual std::vector<std::string> getRessourcesNeeded();
};