#include "Deck.h"
#include <iostream>
#include <vector>
#include <ctime>

template <class V> class Deck {
private:
	std::vector<V > stack;

public:
	//constructors
	Deck() {
		//default constructor
	}

	Deck(const V src[], int size) {
		fill(src, size);
	}

	//member functions

	void fill(const V src[], int size) {
		//fill deck with elements
		for (int i = 0; i < size;i++) { 
			stack.push_back(src[i]);
		}
	}

	void shuffle() {
		//grabs a random value in the vector and pushes at the back.
		//the range of this decreases until there are no more 'ordered' values

		int x;
		srand(time(0));				//allows true random number generation

		for (int i = stack.size(); i > 0; i--) {
			x = rand() % i;								//selects an index in the range of 0 - i
			stack.push_back(stack[x]);					//pushes the value at that index to the back;
			stack.erase(stack.begin() + x);				//removes that index, shifting everything down
		}
		stack.shrink_to_fit();
	}

	void print() {	
		//displays deck
		cout << "BOTTOM\t";
		for(const V& D : stack) { std::cout << D << " "; }
		std::cout <<"\tTOP"<< std::endl;
	}
	
	V draw() {
		// returns the last element of the vector, and removes it 
		V x = stack.back();
		stack.pop_back();
		return x;
	}
};

/*
int main() {
	//example driver using integer array
	int capacity = 10;
	const int cardsData[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Deck<int> myDeck(cardsData,capacity);
	myDeck.print();
	myDeck.shuffle();
	
	
	int card = myDeck.draw();
	std::cout <<"drew card: "<< card << std::endl;
	myDeck.print();

	return 0;
}
*/
