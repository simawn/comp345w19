//#include "../GameMap.h"
//#include "../City.h"
//#include <iostream>
//
//int main() {
//
//	//Create cities
//	City city1;
//	City city2;
//	City city3;
//
//	std::cout << city1.getCityId() << std::endl;
//	std::cout << city2.getCityId() << std::endl;
//	std::cout << city3.getCityId() << std::endl;
//
//	//Create game map
//	GameMap gameMap;
//
//	//Add cities to game map
//	gameMap.addCity(&city1);
//	gameMap.addCity(&city2);
//	gameMap.addCity(&city3);
//
//	gameMap.displayAllCities();
//
//	//Add neighbours + weight
//	/*
//	1 --10--> 2 --20--> 3
//	2 --40--> 1
//	3 --69--> 1
//	*/
//
//	city1.addNeighbour(&city2, 10);
//	city2.addNeighbour(&city3, 20);
//	city2.addNeighbour(&city1, 40);
//	city3.addNeighbour(&city1, 69);
//
//	city1.displayAllNeighbours();
//	city2.displayAllNeighbours();
//	city3.displayAllNeighbours();
//
//	std::cin.get();
//}