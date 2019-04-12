#include "PhaseObserver.h"
#include <iostream>
 void PhaseObserver::notify(std::string color, std::string step, std::string phase, std::string action) {
	std::cout << color << " (STEP: " << step << " | PHASE: "<<phase<<")" <<" ACTION: "<<action<<std::endl;	 
}