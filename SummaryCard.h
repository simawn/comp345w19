#pragma once
#include <string>; 
class SummaryCard {
	
	private:
		struct GameSteps {
			std::string General;
			std::string Details;
		};
	GameSteps StepsOfTheGame[5];
	SummaryCard();
	GameSteps getAStep(int stepNumber);
};