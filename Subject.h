#pragma once
#include "Observer.h"
#include <vector>
class Subject {	
public:
	virtual void attachObserver(Observer* o) = 0;
	virtual void notifyObservers() = 0;
	virtual void removeObserver(Observer* o) = 0;
};