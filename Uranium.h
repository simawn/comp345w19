#ifndef URANIUM_H
#define URANIUM_H
#include "Resources.h"
class Uranium : public Resource
{
public:
	Uranium(int v) :Resource(v) {};
	std::string getName() { return "Uranium"; }
};
#endif // !URANIUM_H