#pragma once

#include <vector>
#include "Character.h"
#include "Room.h"

class Player : public Character
{
private:
	Room* m_currentRoom;

	void Look(const std::vector<std::string>& commands);
	void Move(Room::Directions direction);

public:
	Player(const std::string& name, const std::string& description, Room* currentRoom) :
		Character(name, description), m_currentRoom{ currentRoom }
	{}

	bool ParseCommand(const std::string& playerInput);
};
