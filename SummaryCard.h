#pragma once
#include <string>
#include "Cards.h"
class SummaryCard {

private:
	/**GameSteps
	*Struct contained the General steps and details of the steps
	*/
	struct GameSteps {
		std::string General;
		std::string Details;
	};
	
	/**A step
	*@param Step Number identifier
	*@return A gameStep
	*Getter
	*/
	GameSteps getAStep(int stepNumber);
	/**General Step
	*@param Step Number identifier
	*@return string outputing general step
	*Getter
	*/
	std::string getGeneral(int stepNumber);
	/**Detail Step
	@param Step Number identifier
	@return string outputing detail step
	*Getter
	*/
	std:: string getDetails(int stepNumber);
public:
	/**
	*Default constructor
	*/
	SummaryCard();
	/**
	*Array holding all 5 game steps of the game
	*/
	GameSteps StepsOfTheGame[5];
	/**
	* creation of the 5 steps of the game
	*/
	struct GameSteps one, two, three, four, five;
	/**print
	* output class object description
	*/
	virtual void print();
};