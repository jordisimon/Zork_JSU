#pragma once

#include <vector>
#include "Character.h"
#include "Room.h"

class Player : public Character
{
private:
	Room* m_currentRoom;
	std::vector<Item*> m_inventory;

	

public:
	Player(const std::string& name, const std::string& description, Room* currentRoom) :
		Character(name, description), m_currentRoom{ currentRoom }
	{}

	void Look() const;
	void Move(Room::Directions direction);
	void Examine(const std::string& itemName) const;
	void Pick(const std::string& itemName);
	void Drop(const std::string& itemName);
};
