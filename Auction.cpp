#include "Auction.h"
#include "Cards.h"
#include "PowerPlant.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>	

Auction::Auction(std::vector<Player*> players, Marketplace* marketplace) {
	this->currentPlayers = this->auctioneers = this->bidders = this->nextBidders = players;
	this->marketplace = marketplace;
	this->updateCurrentMarket();
	this->startAuction();
}

void Auction::startAuction() {
	std::cout << "Auction starts:" << std::endl;
	for (Player* auctioneer : this->auctioneers) {
		
		//Displays potential bidders for this round
		this->printPotentialBidders();

		//Card current for auction
		Cards* currentAuction = new PowerPlant();

		//Selects a card for auction
		bool valid = false;
		do {
			int chosen = -1;
			std::cout << "Player " << auctioneer->getPlayerColour() << " choose a power plant for auction: " << std::endl;
			this->displayCurrentMarketPowerPlants();
			std::cin >> chosen;
			//OOR choice
			if (chosen < 0 || chosen > 3) continue;
			currentAuction = choiceMapping.find(chosen)->second;
			valid = true;
		} while (!valid);
		
		//Keeps track of bids
		int auctionValue = currentAuction->getCost();
		
		//Bidding starts
		bool auctionDone = false;
		std::cout << "=== BIDDING STARTS ===" << std::endl;
		std::cout << "Currently bidding for: ";
		currentAuction->print();

		//Looping through all potential bidders
		bool paid = false;
		do {
			int bidAmount = auctionValue;
			//Swap bidders
			//We need this since removing a bidder directly from the bidders array messes up the turn order
			bidders = nextBidders;

			for (Player* bidder : this->bidders) {

				if (auctioneer == bidder && bidAmount == auctionValue) {
					std::cout << "Player " << bidder->getPlayerColour() << " choose a bid amount greater than or equal to " << bidAmount << std::endl;
				}
				else {
					std::cout << "Player " << bidder->getPlayerColour() << " choose a bid amount greater than " << bidAmount << std::endl;
				}
				std::cout << "Enter -1 to pass" << std::endl;
				std::cin >> bidAmount;
				//Pass
				if (bidAmount == -1) {
					nextBidders.erase(std::remove(nextBidders.begin(), nextBidders.end(), bidder), nextBidders.end());
					std::cout << "Player " << bidder->getPlayerColour() << " passes on the bid" << std::endl;
					this->printPotentialBidders();
					break;
				}
				//No more bidders -> Wins the auction
				else if (this->bidders.size() == 1) {
					std::cout << "Player " << bidder->getPlayerColour() << " has won the auction for " << bidAmount << std::endl;
					bidder->buyPowerPlant((PowerPlant*)currentAuction, bidAmount);
					this->marketplace->remove(currentAuction->getCost());
					this->bidWinners.push_back(bidder);
					paid = true;
					break;
				}
			}
		} while (!paid);

		//Resets for next rounds of bids

		//The winner of a power plant cannot be part of the bidders
		this->bidders.clear();
		this->nextBidders.clear();
		for (Player* player : this->currentPlayers) {
			for (Player* winner : this->bidWinners) {
				if (player == winner) continue;
				this->bidders.push_back(player);
			}
		}
		this->nextBidders = this->bidders;
		
	} //End of auctioneers for loop

	std::cout << "=== Auction is over ===" << std::endl;
}

void Auction::displayCurrentMarketPowerPlants() {
	std::cout << "Current market:" << std::endl;
	for (auto it = choiceMapping.begin(); it != choiceMapping.end(); it++) {
		std::cout << "[" << it->first << "] ";
		it->second->print();
	}
}

void Auction::updateCurrentMarket() {
	this->currentMarket = this->marketplace->getCurrentMarket();
	this->choiceMapping.clear();
	int i = 0;
	for (auto it = currentMarket.begin(); it != currentMarket.end(); it++){
		this->choiceMapping[i] = it->second;
		i++;
	}
}

void Auction::printPotentialBidders() {
	std::cout << "Potential bidders: ";
	for (Player* bidder : this->bidders) {
		std::cout << bidder->getPlayerColour() << "; ";
	}
	std::cout << std::endl;
}