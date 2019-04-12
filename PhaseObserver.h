#pragma once
#include <string>
class PhaseObserver{
public:
	void notify(std::string color, std::string step, std::string phase, std::string action);
};