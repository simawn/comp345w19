#ifndef GARBAGE_H
#define GARBAGE_H
#include "Resources.h"

class Garbage: public Resource
{
public:
	/**Garbage constructor calls the super to set the value.*/
	Garbage(int v) :Resource(v) {};
	/**Sets the name of the resource to know which one it is.*/

	std::string getName() { return "Garbage"; }

};
#endif // !GARBAGE_H