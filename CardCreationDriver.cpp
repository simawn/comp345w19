#include "../PowerPlantCard.h"
#include "../SummaryCard.h"
#include "../Step3Card.h"
#include <vector>
std::vector<Cards> createDeckCards(){
	std::vector<Cards> deck;
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
		deck.push_back(PowerPlantCard3);
		deck.push_back(PowerPlantCard4);
		deck.push_back(PowerPlantCard5);
		deck.push_back(PowerPlantCard6);
		deck.push_back(PowerPlantCard7);
		deck.push_back(PowerPlantCard8);
		deck.push_back(PowerPlantCard9);
		deck.push_back(PowerPlantCard10);
		deck.push_back(PowerPlantCard11);
		deck.push_back(PowerPlantCard12);
		deck.push_back(PowerPlantCard13);
		deck.push_back(PowerPlantCard14);
		deck.push_back(PowerPlantCard15);
		deck.push_back(PowerPlantCard16);
		deck.push_back(PowerPlantCard17);
		deck.push_back(PowerPlantCard18);
		deck.push_back(PowerPlantCard19);
		deck.push_back(PowerPlantCard20);
		deck.push_back(PowerPlantCard21);
		deck.push_back(PowerPlantCard22);
		deck.push_back(PowerPlantCard23);
		deck.push_back(PowerPlantCard24);
		deck.push_back(PowerPlantCard25);
		deck.push_back(PowerPlantCard26);
		deck.push_back(PowerPlantCard27);
		deck.push_back(PowerPlantCard28);
		deck.push_back(PowerPlantCard29);
		deck.push_back(PowerPlantCard30);
		deck.push_back(PowerPlantCard31);
		deck.push_back(PowerPlantCard32);
		deck.push_back(PowerPlantCard33);
		deck.push_back(PowerPlantCard34);
		deck.push_back(PowerPlantCard35);
		deck.push_back(PowerPlantCard36);
		deck.push_back(PowerPlantCard37);
		deck.push_back(PowerPlantCard38);
		deck.push_back(PowerPlantCard39);
		deck.push_back(PowerPlantCard40);
		deck.push_back(PowerPlantCard42);
		deck.push_back(PowerPlantCard44);
		deck.push_back(PowerPlantCard50);
		deck.push_back(Step3Card());
	
}
std::vector<Cards> createSummaryCards() {
	std::vector<Cards> summaryCardsPack;
	for (int i = 1; i <= 6; i++) {
		summaryCardsPack.push_back(SummaryCard());
	}
	return summaryCardsPack;
}