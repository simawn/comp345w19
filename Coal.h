#ifndef COAL_H
#define COAL_H
#include"Resources.h"
class Coal : public Resource
{
public:
	Coal(int v) :Resource(v) {};
	const char* getName() { return "Coal"; }

};
#endif // !COAL_H

