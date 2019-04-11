#pragma once
#include "PlayerBot.h"
#include <string>

class PlayerBotModerate : public PlayerBot {
public:
	/*The resource buying behaviour of Moderate bot. There's a 99% chance that it will buy a resource.
	Also, it will always buy the maximum amount of resource that is available to it*/
	int resourceDecision(std::vector<std::vector<Resource*>> resourceMarket);
	/*Saves the desired resource to buy*/
	std::string resourceType();
	/*Saves the grid to which the resource will be bought*/
	int resourcePrice();
	/*Saves the amount of resources to be bought*/
	int resourceAmount();

	/*Default ctor*/
	PlayerBotModerate() : Player() {};
	/*ctor taking colour
	@param colour The colour of the bot
	*/
	PlayerBotModerate(std::string colour) : Player(colour) {};
	/*dtor*/
	~PlayerBotModerate() {};
};

