#include "PlayerBotAggressive.h"



PlayerBotAggressive::PlayerBotAggressive()
{
}

PlayerBotAggressive::PlayerBotAggressive(std::string colour) : Player(colour)
{
}


PlayerBotAggressive::~PlayerBotAggressive()
{
}

void PlayerBotAggressive::pass()
{
	std::cout << "Aggressive Pass" << std::endl;
}

void PlayerBotAggressive::auction()
{
}

void PlayerBotAggressive::buyResource()
{
}

void PlayerBotAggressive::buildCity()
{
}
