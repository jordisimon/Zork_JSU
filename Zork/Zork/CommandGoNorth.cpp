#include "stdafx.h"
#include "CommandGoNorth.h"
#include "Player.h"
#include "Room.h"

void CommandGoNorth::Execute(const std::vector<std::string>& commands)
{
	m_player->Move(Room::Direction::North);
}
