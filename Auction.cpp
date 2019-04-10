#include "Auction.h"
#include "Cards.h"
#include "PowerPlant.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>	

Auction::Auction(std::vector<Player*> players, Marketplace* marketplace, int turn) {
	this->turn = turn;
	this->currentPlayers = this->auctioneers = this->bidders = this->nextBidders = players;
	this->marketplace = marketplace;
	this->updateCurrentMarket();
	this->startAuction();
}

void Auction::startAuction() {
	std::cout << "=== Auction starts ===" << std::endl;

	/*We guarantee that 1 auctioneer will be eventually removed from the list in this loop
	(by either not starting an auction or winning an auction) and will loop until nobody is an auctioneer.
	*/
	while(this->auctioneers.size() > 0) {
		
		//The current auctioneer is the first player in the list
		Player* auctioneer = this->auctioneers.front();

		//Card up for auction
		Cards* currentAuction = new PowerPlant();

		//Checks if choice is valid in the loop below
		bool valid = false; 
		//Checks if the current player do not wish to start an auction
		bool auctionPass = false; 

		//Selects a card for auction
		do {
			int chosen = -2;
			std::cout << "Player " << auctioneer->getPlayerColour() << ", choose a power plant for auction (Type -1 to pass): " << std::endl;
			this->displayCurrentMarketPowerPlants();
			this->marketplace->printFutureMarket();
//std::cin >> chosen;
			chosen = auctioneer->auctionDecision(this->marketplace, this->turn);
			//Pass
			if (chosen == -1) {
				if (this->turn == 1) {
					std::cout << "Cannot skip auction on the first turn" << std::endl;
					continue;
				}
				std::cout << "Player " << auctioneer->getPlayerColour() << " has passed on this auction." << std::endl;
				auctionPass = true;
				break;
			}
			//Valid choice.
			else if (chosen >= 0 && chosen < this->currentMarket.size()) {
				//Player is broke
				if (choiceMapping.find(chosen)->second->getCost() > auctioneer->getPlayersMoney()) {
					std::cout << "You do not have enough money to start this auction. You currently have: " << auctioneer->getPlayersMoney() << std::endl;
				}

				else {
					currentAuction = choiceMapping.find(chosen)->second;
					valid = true;
				}
			}
			//Invalid choice
			else {
				std::cout << "Choice is invalid. Try again." << std::endl;
			}
		} while (!valid);
		
		if (!auctionPass) {
			std::cout << "=== BIDDING STARTS ===" << std::endl;

			std::cout << "Currently bidding for: ";
			currentAuction->print();

			//Checks if someone has paid for the powerplant, otherwise, the bidding war keeps going. Keeps track of the loop below
			bool paid = false;

			//Keeps track of the card cost
			int cardCost = currentAuction->getCost();

			//Keeps track of the current bid. Initial bid must be >= to the PowerPlant cost
			int currentBid = cardCost;

			//This tracks if it is the first round of bids. It prevents the auctioneer from putting a card in auction then passing on their starting bid
			bool firstRoundOfBids = true;

			//Bidding starts
			do {
				

				//The set of next bidders. We need this since removing a bidder directly from the current array messes up the order.
				bidders = nextBidders;

				//Looping through potential bidders
				for (Player* bidder : this->bidders) {

					//The current bidder wishes to pass
					bool pass = false;

					//Checks if the input bid is valid
					bool validBid = false;

					//User inputs a bid. First condition will auto win when there are no more bidders in the current round, the condition after || is when there is 1 auctioneer left and they can choose anything without bid wars. We want them in here since they can choose to pay more than face value
					while((!validBid && this->nextBidders.size() != 1) || this->auctioneers.size() == 1) {
						//Keeps track of user bid input
						int bidAmount = -2;

						//Start of the bid. The auctioneer can bid the face value or greater than the PowerPlant cost
						if (auctioneer == bidder && firstRoundOfBids) {
							std::cout << "Player " << bidder->getPlayerColour() << ", choose a bid amount greater than or equal to " << currentBid << std::endl;
						}
						//The other bidders. They can only bid an amount greater than the current pid
						else {
							std::cout << "Player " << bidder->getPlayerColour() << ", choose a bid amount greater than " << currentBid << ". (Type -1 to pass)" << std::endl;
						}

//std::cin >> bidAmount;
						bidAmount = bidder->bidDecision(currentAuction, currentBid, auctioneer == bidder && firstRoundOfBids ? -1 : this->turn);

						//The player wishes to pass. A player can pass only if they are not the auctioneer and bidder during the first rounds of bids or it is currently not the first round of bids
						if (bidAmount == -1 && ((auctioneer != bidder && firstRoundOfBids) || !firstRoundOfBids) && this->auctioneers.size() != 1) {
							pass = validBid = true;
						}
						//The bid is not high enough
						else if (((auctioneer == bidder && firstRoundOfBids) && bidAmount < cardCost) || //Starting player does bid the correct amount (They can either bid the face value or greater)
								(((auctioneer != bidder && firstRoundOfBids) || !firstRoundOfBids) && bidAmount <= currentBid)) { //The other players do not bid the correct amount
							std::cout << "Invalid bid, try again" << std::endl;
						}
						//The player is broke
						else if (bidAmount > bidder->getPlayersMoney()) {
							std::cout << "Invalid bid, you do not have enough money to make this bid." << std::endl;
						}
						else {
							currentBid = bidAmount;
							validBid = true;
							std::cout << "Player " << bidder->getPlayerColour() << " bids " << currentBid << std::endl;

							//We need to kick the single auctioneer out of this loop when they selecta valid choice
							if (this->auctioneers.size() == 1) break;
						}
					}

					//Pass
					if (pass) {
						nextBidders.erase(std::remove(nextBidders.begin(), nextBidders.end(), bidder), nextBidders.end());
						std::cout << "Player " << bidder->getPlayerColour() << " passes on the bid" << std::endl;
						continue;
					}

					//Only a single bidder is left => They win the auction. Needs to be down here since they have to enter a bid amount
					if (this->nextBidders.size() == 1 && !pass) {
						std::cout << "Player " << bidder->getPlayerColour() << " has won the auction for " << currentBid << std::endl;

						bidder->buyPowerPlant((PowerPlant*)currentAuction, currentBid);
						paid = true;

						this->marketplace->remove(cardCost);

						//Keeps track of all PowerPlant winners: they cannot put anything in auction and can't participate in any
						this->bidWinners.push_back(bidder);

						//The winner of a power plant cannot be part of the auctioners again
						this->auctioneers.erase(std::remove(this->auctioneers.begin(), this->auctioneers.end(), bidder), this->auctioneers.end());

						//Updates the market
						this->updateCurrentMarket();
						break;
					}

					firstRoundOfBids = false;

				} //End of for (Player* bidder : this->bidders)

				//Loops back to the potential bidders until there is one bidder left, which triggers the 'paid' flag
			} while (!paid);
		} //end of if(!auctionPass)

		//The current auction is now done. Reset some variables for the next auction and round of bid
		
		//When the auctioneer decides to not start an auction, they cannot start any or participate in any
		if (auctionPass) {
			this->auctioneers.erase(std::remove(this->auctioneers.begin(), this->auctioneers.end(), auctioneer), this->auctioneers.end());

			//They did not win the auction but we put them there since the code below resets the list of potential bidders and this prevents them to be included.
			this->bidWinners.push_back(auctioneer);
		}
		
		//Resets the list of potential bidders
		this->bidders.clear();
		this->nextBidders.clear();

		//Build the list of potential bidder by removing the PowerPlant winners
		for (Player* player : this->currentPlayers) {
			//Checks if player if part of bidWinners, if not, add to bidders
			if (std::find(this->bidWinners.begin(), this->bidWinners.end(), player) == this->bidWinners.end()) {
				this->bidders.push_back(player);
			}
		}

		//Assigning new list to next bidders
		this->nextBidders = this->bidders;
	} //End of auctioneers while loop

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

void Auction::printPotentialAuctioneers() {
	std::cout << "Potential auctioneers: ";
	for (Player* auctioneer : this->auctioneers) {
		std::cout << auctioneer->getPlayerColour() << "; ";
	}
	std::cout << std::endl;
}
