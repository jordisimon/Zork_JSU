#pragma once

#include "Character.h"

class Room;

class Player : public Character
{
private:
	Room* m_currentRoom;

public:
	Player(const std::string& name, const std::string& description, Room* currentRoom) :
		Character(name, description), m_currentRoom{ currentRoom }
	{}

	bool ParseCommand(const std::string& playerInput);
};
