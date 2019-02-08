#pragma once
#ifndef GAS_H
#define GAS_H
#include "Resources.h"
class Gas : public Resource
{
public:
	Gas(int v) :Resource(v) {};
	const char* getName() { return "Gas"; }

};
#endif // !GAS_H

