#pragma once
#include "../Player.h"
#include "../GameMap.h"
#include "../Deck.h"
#include "../GameSetupDriver.h"
#include "drivers/AuctionStepDriver.h"
#include "drivers/ResourceBuyingDriver.h"
#include "../BuildingStepDriver.h"
#include "drivers/BureaucracyStepDriver.h"

class GameInstance {
private:
	Player* playrArr;	//can double as player order
	GameMap map;
	//Deck deck;
	void InitializeGame();
	void GetPlayerOrderStep();
	void AuctionStep();
	void BuyResourceStep();
	void BuildingStep();
	void BureaucracyStep();
public:
	GameInstance();
};
