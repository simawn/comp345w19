#ifndef RES_H
#define RES_H
#include <string>
/**A Interface for the different resources, Coal, Gas, Uranium and Garbage.*/
class Resource {
protected:
	int value;/**< Provides value for the given resource (cost). */
public:
	/**Default Constructor for resources.*/
	Resource() {}
	/**Provides a value for the resource when constructed.*/
	Resource(int v) { value = v; }
	/**To return the value given for comparison and costing.*/
	int getValue() { return value; }
	/**Virtual method to set the name of the resource ie Coal for coal.*/
	virtual std::string getName() = 0;
};
#endif // !RES_H
