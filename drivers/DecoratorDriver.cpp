#include "../drivers/DecoratorDriver.h"
#include "../CardsDecorator.h"
#include "../PowerPlant.h"
#include "../GameMap.h"
#include "../GasPowerPlant.h"
#include "../CoalPowerPlant.h"
#include "../EcologicalPowerPlant.h"
#include "../GarbagePowerPlant.h"
#include "../HybridPowerPlant.h"
#include "../UraniumPowerPlant.h"
void decoratorTest() {
	Gas* g = new Gas(1);
	Coal* c = new Coal(1);
	Garbage* ga = new Garbage(1);
	Uranium* u = new Uranium(1);
	Cards* PowerPlantCard3 = new PowerPlant(3, 1, 2, g);
	PowerPlantCard3 = new GasPowerPlant(PowerPlantCard3);
	Cards* PowerPlantCard4 = new PowerPlant(4, 1, 2, c);
	PowerPlantCard4 = new CoalPowerPlant(PowerPlantCard4);
	Cards* PowerPlantCard5 = new PowerPlant(5, 1, 2, g, c);
	PowerPlantCard5 = new HybridPowerPlant(PowerPlantCard5);
	Cards* PowerPlantCard6 = new PowerPlant(6, 1, 1, ga);
	PowerPlantCard6 = new GarbagePowerPlant(PowerPlantCard6);
	Cards* PowerPlantCard7 = new PowerPlant(7, 2, 3, g);
	PowerPlantCard7 = new GasPowerPlant(PowerPlantCard7);
	Cards* PowerPlantCard8 = new PowerPlant(8, 2, 3, c);
	PowerPlantCard8 = new CoalPowerPlant(PowerPlantCard8);
	Cards* PowerPlantCard9 = new PowerPlant(9, 1, 1, g);
	PowerPlantCard9 = new GasPowerPlant(PowerPlantCard9);
	Cards* PowerPlantCard10 = new PowerPlant(10, 2, 2, c);
	PowerPlantCard10 = new CoalPowerPlant(PowerPlantCard10);
	Cards* PowerPlantCard11 = new PowerPlant(11, 2, 1, u);
	PowerPlantCard11 = new UraniumPowerPlant(PowerPlantCard11);
	Cards* PowerPlantCard12 = new PowerPlant(12, 2, 2, g, c);
	PowerPlantCard12 = new HybridPowerPlant(PowerPlantCard12);
	Cards* PowerPlantCard13 = new PowerPlant(12, 1, 0);
	PowerPlantCard13 = new EcologicalPowerPlant(PowerPlantCard13);
	
	PowerPlantCard3->print();
	PowerPlantCard4->print();
	PowerPlantCard5->print();
	PowerPlantCard6->print();
	PowerPlantCard11->print();
	PowerPlantCard13->print();



}