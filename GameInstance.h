#pragma once
#include "../Player.h"
#include "../GameMap.h"
#include "../Deck.h"
#include "../GameSetupDriver.h"
#include "../AuctionStepdriver.h"
#include "../BuyResourceStepDriver.h"
#include "../BuildingStepDriver.h"
#include "../BureaucracyStepDriver.h"

class GameInstance {
private:
	Player* playrArr;	//can double as player order
	GameMap map;
	Deck deck;
	void InitializeGame();
	void GetPlayerOrderStep();
	void AuctionStep();
	void BuyResourceStep();
	void BuildingStep();
	void BureaucracyStep();
public:
	GameInstance();
};