#include "stdafx.h"
#include "CommandGoDown.h"
#include "Player.h"
#include "Room.h"

void CommandGoDown::Execute(const std::vector<std::string>& commands)
{
	m_player->Move(Room::Direction::Down);
}