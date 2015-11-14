#include "stdafx.h"
#include "CommandGoUp.h"
#include "Player.h"
#include "Room.h"

void CommandGoUp::Execute(const std::vector<std::string>& commands)
{
	m_player->Move(Room::Direction::Up);
}