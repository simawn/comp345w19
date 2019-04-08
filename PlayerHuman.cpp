#include "PlayerHuman.h"



PlayerHuman::PlayerHuman()
{
}

PlayerHuman::PlayerHuman(std::string colour) : Player(colour)
{
}


PlayerHuman::~PlayerHuman()
{
}

void PlayerHuman::pass()
{
	std::cout << "Human Pass" << std::endl;
}

void PlayerHuman::auction()
{
}

void PlayerHuman::buyResource()
{
}

void PlayerHuman::buildCity()
{
}
