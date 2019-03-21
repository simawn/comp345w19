#include "../PowerPlant.h"
#include "../SummaryCard.h"
#include "../Step3Card.h"
#include "../Deck.h"
#include "../Gas.h"
#include "../Garbage.h"
#include "../Uranium.h"
#include "../Coal.h"

#include "../drivers/CardCreationDriver.h"
#include <vector>
void createDeckCards(){
	Gas g(1);

	Coal c(1);
	Garbage ga(1);
	Uranium u(1);
	Cards* PowerPlantCard3 = new PowerPlant(3, 1, 2, &g);
	Cards* PowerPlantCard4 = new PowerPlant(4,1,2,&c);
	Cards* PowerPlantCard5 = new PowerPlant(5,1,2,&g,&c);
	Cards* PowerPlantCard6 = new PowerPlant(6,1,1,&ga);
	Cards* PowerPlantCard7 = new PowerPlant(7,2,3,&g);
	Cards* PowerPlantCard8 = new PowerPlant(8,2,3,&c);
	Cards* PowerPlantCard9 = new PowerPlant(9,1,1,&g);
	Cards* PowerPlantCard10 = new PowerPlant(10,2,2,&c);
	Cards* PowerPlantCard11 = new PowerPlant(11,2,1,&u);
	Cards* PowerPlantCard12 = new PowerPlant(12,2,2,&g,&c);
	Cards* PowerPlantCard13 = new PowerPlant(12,1,0);
	Cards* PowerPlantCard14 = new PowerPlant(14,2,2,&ga);
		Cards* PowerPlantCard15 = new PowerPlant(15,3,2,&c);
		Cards* PowerPlantCard16 = new PowerPlant(16,3,2,&g);
		Cards* PowerPlantCard17 = new PowerPlant(17,2,1,&u);
		Cards* PowerPlantCard18 = new PowerPlant(18,2,0);
		Cards* PowerPlantCard19 = new PowerPlant(19,3,2,&ga);
		Cards* PowerPlantCard20 = new PowerPlant(20,5,3, &c);
		Cards* PowerPlantCard21 = new PowerPlant(21,4,2,&g,&c);
		Cards* PowerPlantCard22 = new PowerPlant(22,2,0);
		Cards* PowerPlantCard23 = new PowerPlant(23,3,1,&u);
		Cards* PowerPlantCard24 = new PowerPlant(24,4,2,&ga);
		Cards* PowerPlantCard25 = new PowerPlant(25,5,2, &c);
		Cards* PowerPlantCard26 = new PowerPlant(26,5,2,&g);
		Cards* PowerPlantCard27 = new PowerPlant(27,3,0);
		Cards* PowerPlantCard28 = new PowerPlant(28,4,1,&u);
		Cards* PowerPlantCard29 = new PowerPlant(29,4,1,&g,&c);
		Cards* PowerPlantCard30 = new PowerPlant(30,6,3,&ga);
		Cards* PowerPlantCard31 = new PowerPlant(31,6,3,&c);
		Cards* PowerPlantCard32 = new PowerPlant(32,6,3,&g);
		Cards* PowerPlantCard33 = new PowerPlant(33,4,0);
		Cards* PowerPlantCard34 = new PowerPlant(34,5,1,&u);
		Cards* PowerPlantCard35 = new PowerPlant(35,5,1,&g);
		Cards* PowerPlantCard36 = new PowerPlant(36,7,3,&c);
		Cards* PowerPlantCard37 = new PowerPlant(37,4,0);
		Cards* PowerPlantCard38 = new PowerPlant(38,7,3,&ga);
		Cards* PowerPlantCard39 = new PowerPlant(39,6,1,&u);
		Cards* PowerPlantCard40 = new PowerPlant(40,6,2,&g);
		Cards* PowerPlantCard42 = new PowerPlant(42,6,2,&c);
		Cards* PowerPlantCard44 = new PowerPlant(44,5,0);
		Cards* PowerPlantCard46 = new PowerPlant(46,7,3,&g,&c);
		Cards* PowerPlantCard50 = new PowerPlant(50,6,0);

		 Cards *src[42] = { PowerPlantCard3,PowerPlantCard4,PowerPlantCard5,PowerPlantCard6,PowerPlantCard7,PowerPlantCard8,PowerPlantCard9,
		PowerPlantCard10,PowerPlantCard11,PowerPlantCard12,PowerPlantCard13,PowerPlantCard14,PowerPlantCard15,PowerPlantCard16,PowerPlantCard17,PowerPlantCard18,PowerPlantCard19,
		PowerPlantCard20,PowerPlantCard21,PowerPlantCard22,PowerPlantCard23,PowerPlantCard24,PowerPlantCard25,PowerPlantCard26,PowerPlantCard27,PowerPlantCard28,PowerPlantCard29,
		PowerPlantCard30,PowerPlantCard31,PowerPlantCard32,PowerPlantCard33,PowerPlantCard34,PowerPlantCard35,PowerPlantCard36,PowerPlantCard37,PowerPlantCard38,PowerPlantCard39,
		PowerPlantCard40,PowerPlantCard42,PowerPlantCard44,PowerPlantCard46,PowerPlantCard50 };
		
		Cards* step3Card = new Step3Card();
		
		Deck DECK(src, 42);
		std::cout << "=== INITIAL DECK == " << "\n";
		DECK.print();
		
	    DECK.shuffle();
		DECK.insert(step3Card);
		std::cout << "=== Shuffled deck and inserted step3 Card ===" << "\n";
		DECK.print();
		for (Cards* a : src) {
			delete a;
		}	
		delete step3Card;

}
std::vector<Cards> createSummaryCards() {
	std::vector<Cards> summaryCardsPack;
	for (int i = 1; i <= 6; i++) {
		summaryCardsPack.push_back(SummaryCard());
	}
	return summaryCardsPack;
}
