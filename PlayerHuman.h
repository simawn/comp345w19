#pragma once
#include "Player.h"
class PlayerHuman :
	public Player
{
public:
	PlayerHuman() : Player() {};
	PlayerHuman(std::string colour) : Player(colour) {};
	int auctionDecision(Marketplace* marketplace, int turn);
	int pass();
	int auction();
	int bidDecision(Cards* card, int currentBid, int turn);
	void buyResource();
	void buildCity();

	~PlayerHuman();
};

