#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "Cards.h"
class Deck:public Cards {
private:
	std::vector<Cards> stack;

public:
	Deck();
	
	/**General Constructor
	*@param Powerplant[] src
	*@param int size - size of powerplant array
	*generates a deck and then fills it with the members of the source array
	*/
	Deck( Cards *src[], int size);
	
	/**Fill
	*@param Powerplant[] src
	*@param int size - size of powerplant array
	*fill a deck with the members of the source array
	*/
	void fill( Cards *src[], int size);
	
	/**push
	*@param Cards card
	*adds 'card' to the top of the deck.
	*/
	void push( Cards *card);
	
	/**insert
	*@param Cards card
	*adds 'card' to the bottom of the deck.
	*/
	void insert( Cards *card);
	
	/**shuffle
	shuffles the elements of the vector in an inline fashion.
	*/
	void shuffle();
	
	/*print
	Displays all elements in the vector with the back most element on the right.
	*/
	void print();
	
	/**draw
	*@returns Card
	*pops the backmost Powerplant card element form the vector and returns it
	*/
	Cards draw();
};


