#include "stdafx.h"
#include "CommandGoEast.h"
#include "Player.h"
#include "Room.h"

void CommandGoEast::Execute(const std::vector<std::string>& commands)
{
	m_player->Move(Room::Directions::East);
}