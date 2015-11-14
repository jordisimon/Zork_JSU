#include "stdafx.h"
#include "CommandGoSouth.h"
#include "Player.h"
#include "Room.h"

void CommandGoSouth::Execute(const std::vector<std::string>& commands)
{
	m_player->Move(Room::Direction::South);
}
