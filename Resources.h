#pragma once
#ifndef RES_H
class Resource {
protected:
	int value;
public:
	Resource(int v) { value = v; }
	int getValue() { return value; }
	virtual const char* getName() = 0;
};
#endif // !RES_H
