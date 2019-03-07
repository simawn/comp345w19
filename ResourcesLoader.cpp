#include "../ResourcesLoader.h"

#include "../GameMap.h"
void resourceLoader() {
	GameMap map;
	std::vector<Coal> TotalCoal;
	std::vector<Garbage> TotalGarbage;
	std::vector<Gas> TotalGas;
	std::vector<Uranium> TotalUranium;
	for (int i = 0; i < 24; i++) {
		TotalCoal.push_back(Coal(1));
	}
	for (int i = 0; i < 24; i++) {
		TotalGas.push_back(Gas(7));
	}
	for (int i = 0; i < 24; i++) {
		TotalGarbage.push_back(Garbage(3));
	}
	for (int i = 0; i < 12; i++) {
		TotalUranium.push_back(Uranium(14));
	}
	for(int i = 1; i < 9; i++) {
		map.addResource(i, 3, TotalCoal);
	}
	for (int i = 3; i < 9; i++) {
		map.addResource(i, 3, TotalGas);
	}
	map.addResource(7, 3, TotalGarbage);
	map.addResource(8, 3, TotalGarbage);
	map.addResource(14, 3, TotalUranium);
	map.addResource(16, 3, TotalUranium);

	
