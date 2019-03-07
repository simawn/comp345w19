#include "../drivers/ResourcesLoaderDriver.h"

#include "../GameMap.h"
void resourceLoaderDriver() {
	GameMap map;
	std::vector<Coal*> TotalCoal;
	std::vector<Garbage*> TotalGarbage;
	std::vector<Gas*> TotalGas;
	std::vector<Uranium*> TotalUranium;
	for (int i = 0; i < 24; i++)
	{

		TotalCoal.push_back(new Coal(1));
	}
	for (int i = 0; i < 24; i++) {
		TotalGas.push_back(new Gas(7));
	}
	for (int i = 0; i < 24; i++) {
		TotalGarbage.push_back(new Garbage(3));
	}
	for (int i = 0; i < 12; i++) {
		TotalUranium.push_back(new Uranium(14));
	}
	for (int i = 0; i < 8; i++) {
		map.addResource(i, 3, TotalCoal);
	}
	for (int i = 2; i < 8; i++) {
		map.addResource(i, 3, TotalGas);
	}
	map.addResource(6, 3, TotalGarbage);
	map.addResource(7, 3, TotalGarbage);
	map.addResource(13, 3, TotalUranium);
	map.addResource(15, 3, TotalUranium);
	map.printResourceMarket();

}