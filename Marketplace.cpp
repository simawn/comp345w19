#include "Marketplace.h"
#include "PowerPlant.h"

Marketplace::Marketplace(Deck* deck) {
	this->deck = deck; //For further deck calls
	for (int i = 0; i < 8; i++) { //Initial insertion
		this->insert(&(deck->draw())); //Insert the addr
	}
}

bool Marketplace::buy(int) { //Basically remove but we need to return some values
	return false;
}

void Marketplace::insert(Cards* card) {
	market[card->getCardNumber] = card;
}

void Marketplace::remove(Cards* card) { //On remove, insert new card immediately
	market.erase(card->getCardNumber());
	this->insert(&(deck->draw())); //Check if deck is not empty?
}
