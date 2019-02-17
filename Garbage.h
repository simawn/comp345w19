#ifndef GARBAGE_H
#define GARBAGE_H
#include "Resources.h"
class Garbage: public Resource
{
public:
	Garbage(int v) :Resource(v) {};
	const char* getName() { return "Garbage"; }

};
#endif // !GARBAGE_H