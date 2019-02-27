#include "SummaryCard.h"
SummaryCard::SummaryCard() {
	one.General = "DETERMINE TURN ORDER";
	one.Details = "";
	two.General = "BUY POWER PLANT";
	two.Details = "The first player begins. \n Per round, each may buy only one power plant.";
	three.General = "BUY RAW MATERIAL";
	three.Details = "The last player begins. \n Maximum double input per power plant.";
	four.General = "BUILDING";
	four.Details = "The last player begins";
	five.General = "BUREAUCRACY";
	five.Details = "Get money.\n In phase 1 and 2:Place highest power plant under the stack.\n In phase 3: Remove lowest power plant from the game. \n Restock raw materials.";
	StepsOfTheGame[0] = one;
	StepsOfTheGame[1] = two;
	StepsOfTheGame[2] = three;
	StepsOfTheGame[3] = four;
	StepsOfTheGame[4] = five;


}
SummaryCard::GameSteps SummaryCard::getAStep(int stepNumber) {
	return StepsOfTheGame[stepNumber];
}
std::string SummaryCard::getGeneral(int stepNumber) {
	return StepsOfTheGame[stepNumber].General;
}
std::string SummaryCard::getDetails(int stepNumber) {
	return StepsOfTheGame[stepNumber].Details;
}
