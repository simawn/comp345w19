#include "../drivers/ResourcesLoaderDriver.h"

#include "../GameMap.h"
void resourceLoaderDriver() {
	GameMap map;
	std::vector<Coal*> TotalCoal(24);
	std::vector<Garbage*> TotalGarbage(24);
	std::vector<Gas*> TotalGas(24);
	std::vector<Uranium*> TotalUranium(12);
	for (int i = 0; i < 8; i++) {
		map.addResource(i, 3, TotalCoal);
	}
	for (int i = 2; i < 8; i++) {
		map.addResource(i, 3, TotalGas);
	}
	map.addResource(6, 3, TotalGarbage);
	map.addResource(7, 3, TotalGarbage);
	map.addResource(13, 1, TotalUranium);
	map.addResource(15, 1, TotalUranium);
	map.printResourceMarket();
	map.buyResource("Gas", 2,2);
	map.printResourceMarket();


}