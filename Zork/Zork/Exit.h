#pragma once

#include "Entity.h"

class Room;

class Exit : public Entity
{
private:
	Room* leadsTo;
};
