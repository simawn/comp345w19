#pragma once
#include <iostream>
class Cards {
public:
	friend std::ostream& operator<< (std::ostream &os, const Cards &f);
};