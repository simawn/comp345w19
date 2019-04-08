#include "PlayerBotEnvironmentalist.h"



PlayerBotEnvironmentalist::PlayerBotEnvironmentalist()
{
}

PlayerBotEnvironmentalist::PlayerBotEnvironmentalist(std::string colour) : Player(colour)
{
}


PlayerBotEnvironmentalist::~PlayerBotEnvironmentalist()
{
}

void PlayerBotEnvironmentalist::pass()
{
	std::cout << "Environmentalist Pass" << std::endl;
}

void PlayerBotEnvironmentalist::auction()
{
}

void PlayerBotEnvironmentalist::buyResource()
{
}

void PlayerBotEnvironmentalist::buildCity()
{
}
