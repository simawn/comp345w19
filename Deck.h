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
	Deck(const Cards src[], int size);
	void fill(const Cards src[], int size);
	void push(const Cards card);
	void insert(const Cards card);
	void shuffle();
	void print();
	Cards draw();
};


