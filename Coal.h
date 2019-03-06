#ifndef COAL_H
#define COAL_H
#include"Resources.h"
/**Derived class from Resource to make coal resource*/
class Coal : public Resource
{
public:
	/**Coal constructor calls the super to set the value.*/
	Coal(int v) :Resource(v) {};
	/**Sets the name of the resource to know which one it is.*/
	std::string getName() { return "Coal"; }

};
#endif // !COAL_H

