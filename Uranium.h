#ifndef URANIUM_H
#define URANIUM_H
#include "Resources.h"
/**Derived class from Resource to make uranium resource*/
class Uranium : public Resource
{
public:
	/**Coal constructor calls the super to set the value.*/
	Uranium(int v) :Resource(v) {};
	/**Sets the name of the resource to know which one it is.*/
	std::string getName() { return "Uranium"; }
};
#endif // !URANIUM_H