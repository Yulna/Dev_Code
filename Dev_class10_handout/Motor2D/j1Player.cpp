#include "j1Player.h"
#include "p2Log.h"

j1Player::j1Player()
{
	name.create("player");
}

j1Player::~j1Player()
{
}

bool j1Player::UpdateTicks()
{

	LOG("I'm the player and i'm updating");

	return true;
}
