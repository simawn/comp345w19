#include "Deck.h"
#include "Gas.h"
#include "Coal.h"
#include "Uranium.h"
#include "Garbage.h"
#include "PowerPlant.h"
#include "Step3Card.h"

	/**Default Deck constructor
	Shuffles the initial deck
	*/
	Deck::Deck() {
		//Setup Cards
		Gas* g = new Gas(1);
		Coal* c = new Coal(1);
		Garbage* ga = new Garbage(1);
		Uranium* u = new Uranium(1);

		//Below are starting cards. They won't be shuffled in
		/*
		Cards* PowerPlantCard3 = new PowerPlant(3, 1, 2, &g);
		Cards* PowerPlantCard4 = new PowerPlant(4, 1, 2, &c);
		Cards* PowerPlantCard5 = new PowerPlant(5, 1, 2, &g, &c);
		Cards* PowerPlantCard6 = new PowerPlant(6, 1, 1, &ga);
		Cards* PowerPlantCard7 = new PowerPlant(7, 2, 3, &g);
		Cards* PowerPlantCard8 = new PowerPlant(8, 2, 3, &c);
		Cards* PowerPlantCard9 = new PowerPlant(9, 1, 1, &g);
		Cards* PowerPlantCard10 = new PowerPlant(10, 2, 2, &c);
		*/
		//End starting cards

		//Below are cards to be shuffled in the deck
		//TODO: dtor for all
		Cards* PowerPlantCard11 = new PowerPlant(11, 2, 1, u);
		Cards* PowerPlantCard12 = new PowerPlant(12, 2, 2, g, c);
		Cards* PowerPlantCard13 = new PowerPlant(12, 1, 0);
		Cards* PowerPlantCard14 = new PowerPlant(14, 2, 2, ga);
		Cards* PowerPlantCard15 = new PowerPlant(15, 3, 2, c);
		Cards* PowerPlantCard16 = new PowerPlant(16, 3, 2, g);
		Cards* PowerPlantCard17 = new PowerPlant(17, 2, 1, u);
		Cards* PowerPlantCard18 = new PowerPlant(18, 2, 0);
		Cards* PowerPlantCard19 = new PowerPlant(19, 3, 2, ga);
		Cards* PowerPlantCard20 = new PowerPlant(20, 5, 3, c);
		Cards* PowerPlantCard21 = new PowerPlant(21, 4, 2, g, c);
		Cards* PowerPlantCard22 = new PowerPlant(22, 2, 0);
		Cards* PowerPlantCard23 = new PowerPlant(23, 3, 1, u);
		Cards* PowerPlantCard24 = new PowerPlant(24, 4, 2, ga);
		Cards* PowerPlantCard25 = new PowerPlant(25, 5, 2, c);
		Cards* PowerPlantCard26 = new PowerPlant(26, 5, 2, g);
		Cards* PowerPlantCard27 = new PowerPlant(27, 3, 0);
		Cards* PowerPlantCard28 = new PowerPlant(28, 4, 1, u);
		Cards* PowerPlantCard29 = new PowerPlant(29, 4, 1, g, c);
		Cards* PowerPlantCard30 = new PowerPlant(30, 6, 3, ga);
		Cards* PowerPlantCard31 = new PowerPlant(31, 6, 3, c);
		Cards* PowerPlantCard32 = new PowerPlant(32, 6, 3, g);
		Cards* PowerPlantCard33 = new PowerPlant(33, 4, 0);
		Cards* PowerPlantCard34 = new PowerPlant(34, 5, 1, u);
		Cards* PowerPlantCard35 = new PowerPlant(35, 5, 1, g);
		Cards* PowerPlantCard36 = new PowerPlant(36, 7, 3, c);
		Cards* PowerPlantCard37 = new PowerPlant(37, 4, 0);
		Cards* PowerPlantCard38 = new PowerPlant(38, 7, 3, ga);
		Cards* PowerPlantCard39 = new PowerPlant(39, 6, 1, u);
		Cards* PowerPlantCard40 = new PowerPlant(40, 6, 2, g);
		Cards* PowerPlantCard42 = new PowerPlant(42, 6, 2, c);
		Cards* PowerPlantCard44 = new PowerPlant(44, 5, 0);
		Cards* PowerPlantCard46 = new PowerPlant(46, 7, 3, g, c);
		Cards* PowerPlantCard50 = new PowerPlant(50, 6, 0);
		//End cards to be shuffled

		Cards *src[34] = {PowerPlantCard11,PowerPlantCard12,PowerPlantCard13,PowerPlantCard14,PowerPlantCard15,PowerPlantCard16,PowerPlantCard17,PowerPlantCard18,PowerPlantCard19,
PowerPlantCard20,PowerPlantCard21,PowerPlantCard22,PowerPlantCard23,PowerPlantCard24,PowerPlantCard25,PowerPlantCard26,PowerPlantCard27,PowerPlantCard28,PowerPlantCard29,
PowerPlantCard30,PowerPlantCard31,PowerPlantCard32,PowerPlantCard33,PowerPlantCard34,PowerPlantCard35,PowerPlantCard36,PowerPlantCard37,PowerPlantCard38,PowerPlantCard39,
PowerPlantCard40,PowerPlantCard42,PowerPlantCard44,PowerPlantCard46,PowerPlantCard50 };

		Cards* step3Card = new Step3Card();

		this->fill(src, 34);
		this->shuffle();
		this->insert(step3Card);

		/* Messes things up if we delete here
		for (Cards* a : src) delete a;
		delete step3Card;
		*/
	}

	/**General Constructor
	*@param Powerplant[] src
	*@param int size - size of powerplant array
	*generates a deck and then fills it with the members of the source array
	*/
	Deck::Deck( Cards *src[], int size) {
		Deck::fill(src, size);
	}

	/**Fill
	*@param Powerplant[] src
	*@param int size - size of powerplant array
	*fill a deck with the members of the source array
	*/
	void Deck::fill( Cards *src[], int size) {
		//fill deck with elements
		for (int i = 0; i < size;i++) { 
			Deck::stack.push_back(src[i]);
		}
	}

	/**push
	*@param Cards card
	*adds 'card' to the top of the deck.
	*/
	void Deck::push( Cards *card) {
		Deck::stack.push_back(card);
	}

	/**insert
	*@param Cards card
	*adds 'card' to the bottom of the deck.
	*/
	void Deck::insert( Cards *card) {
		Deck::stack.insert(stack.begin(),card);
	}

	/**shuffle
	shuffles the elements of the vector in an inline fashion.
	*/
	void Deck::shuffle() {
		//grabs a random value in the vector and pushes at the back.
		//the range of this decreases until there are no more 'ordered' values

		int x;
		srand(time(0));				//allows true random number generation

		for (int i = Deck::stack.size(); i > 0; i--) {
			x = rand() % i;								//selects an index in the range of 0 - i
			Deck::stack.push_back(Deck::stack[x]);					//pushes the value at that index to the back;
			Deck::stack.erase(stack.begin() + x);				//removes that index, shifting everything down
		}
		Deck::stack.shrink_to_fit();
	}

	/*print
	Displays all elements in the vector with the back most element on the right.
	*/
	void Deck::print() {	
		//displays deck
		std::cout << "BOTTOM\t"<< "\n";
		for(  Cards *D : Deck::stack) {
			D->print();
			std::cout << "\n";
		}
		std::cout <<"\tTOP"<< std::endl;
	}
	
	/**draw
	*@returns Card
	*pops the backmost Powerplant card element form the vector and returns it
	*/
	Cards Deck::draw() {
		// returns the last element of the vector, and removes it 
		Cards* x = Deck::stack.back();
		Deck::stack.pop_back();
		return *x;
	}

	int Deck::size() {
		return this->stack.size();
	}