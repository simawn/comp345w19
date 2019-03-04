#include "Deck.h"

	/**Default Deck constructor
	*/
	Deck::Deck() {
	}

	/**General Constructor
	*@param Powerplant[] src
	*@param int size - size of powerplant array
	*generates a deck and then fills it with the members of the source array
	*/
	Deck::Deck(const Cards src[], int size) {
		Deck::fill(src, size);
	}

	/**Fill
	*@param Powerplant[] src
	*@param int size - size of powerplant array
	*fill a deck with the members of the source array
	*/
	void Deck::fill(const Cards src[], int size) {
		//fill deck with elements
		for (int i = 0; i < size;i++) { 
			Deck::stack.push_back(src[i]);
		}
	}

	/**push
	*@param Cards card
	*adds 'card' to the top of the deck.
	*/
	void Deck::push(const Cards card) {
		Deck::stack.push_back(card);
	}

	/**insert
	*@param Cards card
	*adds 'card' to the bottom of the deck.
	*/
	void Deck::insert(const Cards card) {
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
		std::cout << "BOTTOM\t";
		for(const Cards& D : Deck::stack) {
			std::cout << D << " "; 
		}
		std::cout <<"\tTOP"<< std::endl;
	}
	
	/**draw
	*@returns Card
	*pops the backmost Powerplant card element form the vector and returns it
	*/
	Cards Deck::draw() {
		// returns the last element of the vector, and removes it 
		Cards x = Deck::stack.back();
		Deck::stack.pop_back();
		return x;
	}
