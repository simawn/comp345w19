#include "../PowerPlantCard.h"
#include "../SummaryCard.h"
#include "../Step3Card.h"
#include "../Deck.h"
#include "../drivers/CardCreationDriver.h"
#include <vector>
void createDeckCards(){
	Cards* PowerPlantCard3 = new PowerPlantCard(3, 1, 2, "Gas");
	Cards* PowerPlantCard4 = new PowerPlantCard(4,1,2,"Coal");
	Cards* PowerPlantCard5 = new PowerPlantCard(5,1,2,"Gas","Coal");
	Cards* PowerPlantCard6 = new PowerPlantCard(6,1,1,"Garbage");
	Cards* PowerPlantCard7 = new PowerPlantCard(7,2,3,"Gas");
	Cards* PowerPlantCard8 = new PowerPlantCard(8,2,3,"Coal");
	Cards* PowerPlantCard9 = new PowerPlantCard(9,1,1,"Gas");
	Cards* PowerPlantCard10 = new PowerPlantCard(10,2,2,"Coal");
	Cards* PowerPlantCard11 = new PowerPlantCard(11,2,1,"Uranium");
	Cards* PowerPlantCard12 = new PowerPlantCard(12,2,2,"Gas","Coal");
	Cards* PowerPlantCard13 = new PowerPlantCard(12,1,0);
	Cards* PowerPlantCard14 = new PowerPlantCard(14,2,2,"Garbage");
		Cards* PowerPlantCard15 = new PowerPlantCard(15,3,2,"Coal");
		Cards* PowerPlantCard16 = new PowerPlantCard(16,3,2,"Gas");
		Cards* PowerPlantCard17 = new PowerPlantCard(17,2,1,"Uranium");
		Cards* PowerPlantCard18 = new PowerPlantCard(18,2,0);
		Cards* PowerPlantCard19 = new PowerPlantCard(19,3,2,"Garbage");
		Cards* PowerPlantCard20 = new PowerPlantCard(20,5,3, "Coal");
		Cards* PowerPlantCard21 = new PowerPlantCard(21,4,2,"Gas","Coal");
		Cards* PowerPlantCard22 = new PowerPlantCard(22,2,0);
		Cards* PowerPlantCard23 = new PowerPlantCard(23,3,1,"Uranium");
		Cards* PowerPlantCard24 = new PowerPlantCard(24,4,2,"Garbage");
		Cards* PowerPlantCard25 = new PowerPlantCard(25,5,2, "Coal");
		Cards* PowerPlantCard26 = new PowerPlantCard(26,5,2,"Gas");
		Cards* PowerPlantCard27 = new PowerPlantCard(27,3,0);
		Cards* PowerPlantCard28 = new PowerPlantCard(28,4,1,"Uranium");
		Cards* PowerPlantCard29 = new PowerPlantCard(29,4,1,"Gas","Coal");
		Cards* PowerPlantCard30 = new PowerPlantCard(30,6,3,"Garbage");
		Cards* PowerPlantCard31 = new PowerPlantCard(31,6,3,"Coal");
		Cards* PowerPlantCard32 = new PowerPlantCard(32,6,3,"Gas");
		Cards* PowerPlantCard33 = new PowerPlantCard(33,4,0);
		Cards* PowerPlantCard34 = new PowerPlantCard(34,5,1,"Uranium");
		Cards* PowerPlantCard35 = new PowerPlantCard(35,5,1,"Gas");
		Cards* PowerPlantCard36 = new PowerPlantCard(36,7,3,"Coal");
		Cards* PowerPlantCard37 = new PowerPlantCard(37,4,0);
		Cards* PowerPlantCard38 = new PowerPlantCard(38,7,3,"Garbage");
		Cards* PowerPlantCard39 = new PowerPlantCard(39,6,1,"Uranium");
		Cards* PowerPlantCard40 = new PowerPlantCard(40,6,2,"Gas");
		Cards* PowerPlantCard42 = new PowerPlantCard(42,6,2,"Coal");
		Cards* PowerPlantCard44 = new PowerPlantCard(44,5,0);
		Cards* PowerPlantCard46 = new PowerPlantCard(46,7,3,"Gas","Coal");
		Cards* PowerPlantCard50 = new PowerPlantCard(50,6,0);

		 Cards *src[42] = { PowerPlantCard3,PowerPlantCard4,PowerPlantCard5,PowerPlantCard6,PowerPlantCard7,PowerPlantCard8,PowerPlantCard9,
		PowerPlantCard10,PowerPlantCard11,PowerPlantCard12,PowerPlantCard13,PowerPlantCard14,PowerPlantCard15,PowerPlantCard16,PowerPlantCard17,PowerPlantCard18,PowerPlantCard19,
		PowerPlantCard20,PowerPlantCard21,PowerPlantCard22,PowerPlantCard23,PowerPlantCard24,PowerPlantCard25,PowerPlantCard26,PowerPlantCard27,PowerPlantCard28,PowerPlantCard29,
		PowerPlantCard30,PowerPlantCard31,PowerPlantCard32,PowerPlantCard33,PowerPlantCard34,PowerPlantCard35,PowerPlantCard36,PowerPlantCard37,PowerPlantCard38,PowerPlantCard39,
		PowerPlantCard40,PowerPlantCard42,PowerPlantCard44,PowerPlantCard46,PowerPlantCard50 };
		for ( Cards *a : src) {
			a->print();
			std::cout << "\n";
		}
		Cards* step3Card = new Step3Card();
		step3Card->print();
		Deck DECK(src, 42);
	    DECK.shuffle();
		DECK.insert(step3Card);
		DECK.print();
}
std::vector<Cards> createSummaryCards() {
	std::vector<Cards> summaryCardsPack;
	for (int i = 1; i <= 6; i++) {
		summaryCardsPack.push_back(SummaryCard());
	}
	return summaryCardsPack;
}
