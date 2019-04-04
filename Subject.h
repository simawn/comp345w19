#pragma once
#include "Observer.h"
#include <vector>
class Subject {
private:
	std::vector<Observer> observers;
public:
	void attachObserver(Observer& o);
	void notifyObservers();
	void removeObserver(Observer& o);
};