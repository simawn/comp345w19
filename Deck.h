#pragma once
#include <iostream>
#include <vector>
#include <ctime>

template <class V> class Deck {

private:
	//member variables
	std::vector<V *> stack;

public:
	//constructors
	Deck();
	Deck(const V[], int);
	//member functions
	void fill(const V[], int);
	void shuffle();
	void print();
	V draw();
};
