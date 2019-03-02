#include "../PowerPlantCard.h"
#include "../SummaryCard.h"
#include "../Step3Card.h"
#include "../Deck.h"
#include <vector>
void createDeckCards(){
		PowerPlantCard PowerPlantCard3(3, 1, 2, "Gas");
		PowerPlantCard PowerPlantCard4(4,1,2,"Coal");
		PowerPlantCard PowerPlantCard5(5,1,2,"Gas","Coal");
		PowerPlantCard PowerPlantCard6(6,1,1,"Garbage");
		PowerPlantCard PowerPlantCard7(7,2,3,"Gas");
		PowerPlantCard PowerPlantCard8(8,2,3,"Coal");
		PowerPlantCard PowerPlantCard9(9,1,1,"Gas");
		PowerPlantCard PowerPlantCard10(10,2,2,"Coal");
		PowerPlantCard PowerPlantCard11(11,2,1,"Uranium");
		PowerPlantCard PowerPlantCard12(12,2,2,"Gas","Coal");
		PowerPlantCard PowerPlantCard13(12,1,0);
		PowerPlantCard PowerPlantCard14(14,2,2,"Garbage");
		PowerPlantCard PowerPlantCard15(15,3,2,"Coal");
		PowerPlantCard PowerPlantCard16(16,3,2,"Gas");
		PowerPlantCard PowerPlantCard17(17,2,1,"Uranium");
		PowerPlantCard PowerPlantCard18(18,2,0);
		PowerPlantCard PowerPlantCard19(19,3,2,"Garbage");
		PowerPlantCard PowerPlantCard20(20,5,3, "Coal");
		PowerPlantCard PowerPlantCard21(21,4,2,"Gas","Coal");
		PowerPlantCard PowerPlantCard22(22,2,0);
		PowerPlantCard PowerPlantCard23(23,3,1,"Uranium");
		PowerPlantCard PowerPlantCard24(24,4,2,"Garbage");
		PowerPlantCard PowerPlantCard25(25,5,2, "Coal");
		PowerPlantCard PowerPlantCard26(26,5,2,"Gas");
		PowerPlantCard PowerPlantCard27(27,3,0);
		PowerPlantCard PowerPlantCard28(28,4,1,"Uranium");
		PowerPlantCard PowerPlantCard29(29,4,1,"Gas","Coal");
		PowerPlantCard PowerPlantCard30(30,6,3,"Garbage");
		PowerPlantCard PowerPlantCard31(31,6,3,"Coal");
		PowerPlantCard PowerPlantCard32(32,6,3,"Gas");
		PowerPlantCard PowerPlantCard33(33,4,0);
		PowerPlantCard PowerPlantCard34(34,5,1,"Uranium");
		PowerPlantCard PowerPlantCard35(35,5,1,"Gas");
		PowerPlantCard PowerPlantCard36(36,7,3,"Coal");
		PowerPlantCard PowerPlantCard37(37,4,0);
		PowerPlantCard PowerPlantCard38(38,7,3,"Garbage");
		PowerPlantCard PowerPlantCard39(39,6,1,"Uranium");
		PowerPlantCard PowerPlantCard40(40,6,2,"Gas");
		PowerPlantCard PowerPlantCard42(42,6,2,"Coal");
		PowerPlantCard PowerPlantCard44(44,5,0);
		PowerPlantCard PowerPlantCard46(46,7,3,"Gas","Coal");
		PowerPlantCard PowerPlantCard50(50,6,0);

		PowerPlantCard src[42] = { PowerPlantCard3,PowerPlantCard4,PowerPlantCard5,PowerPlantCard6,PowerPlantCard7,PowerPlantCard8,PowerPlantCard9,
		PowerPlantCard10,PowerPlantCard11,PowerPlantCard12,PowerPlantCard13,PowerPlantCard14,PowerPlantCard15,PowerPlantCard16,PowerPlantCard17,PowerPlantCard18,PowerPlantCard19,
		PowerPlantCard20,PowerPlantCard21,PowerPlantCard22,PowerPlantCard23,PowerPlantCard24,PowerPlantCard25,PowerPlantCard26,PowerPlantCard27,PowerPlantCard28,PowerPlantCard29,
		PowerPlantCard30,PowerPlantCard31,PowerPlantCard32,PowerPlantCard33,PowerPlantCard34,PowerPlantCard35,PowerPlantCard36,PowerPlantCard37,PowerPlantCard38,PowerPlantCard39,
		PowerPlantCard40,PowerPlantCard42,PowerPlantCard44,PowerPlantCard46,PowerPlantCard50 };
		
		Deck DECK(src, 42);
		DECK.shuffle();
		DECK.insert(Step3Card());
}
std::vector<Cards> createSummaryCards() {
	std::vector<Cards> summaryCardsPack;
	for (int i = 1; i <= 6; i++) {
		summaryCardsPack.push_back(SummaryCard());
	}
	return summaryCardsPack;
}
