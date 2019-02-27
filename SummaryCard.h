#pragma once
#include <string>; 
#include "Cards.h"
class SummaryCard :public Cards {

private:
	struct GameSteps {
		std::string General;
		std::string Details;
	};
	GameSteps StepsOfTheGame[5];
	struct GameSteps one, two, three, four, five;
	SummaryCard();
	GameSteps getAStep(int stepNumber);
	std::string getGeneral(int stepNumber);
	std:: string getDetails(int stepNumber);
};