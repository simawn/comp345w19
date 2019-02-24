#ifndef RES_H
#define RES_H
#include <string>
class Resource {
protected:
	int value;
public:
	Resource() {}
	Resource(int v) { value = v; }
	int getValue() { return value; }
	virtual std::string getName() = 0;
};
#endif // !RES_H
