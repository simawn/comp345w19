#ifndef GAS_H
#define GAS_H
#include "Resources.h"
class Gas : public Resource
{
public:
	/**Gas constructor calls the super to set the value.*/
	Gas(int v) :Resource(v) {};
	/**Sets the name of the resource to know which one it is.*/
	std::string getName() { return "Gas"; }

};
#endif // !GAS_H

