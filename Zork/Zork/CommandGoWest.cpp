#include "stdafx.h"
#include "CommandGoWest.h"
#include "Player.h"
#include "Room.h"

void CommandGoWest::Execute(const std::vector<std::string>& commands)
{
	m_player->Move(Room::Directions::West);
}