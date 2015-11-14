#pragma once

#include <vector>
#include "Character.h"
#include "Room.h"

class Player : public Character
{
private:
	Room* m_currentRoom;
	std::vector<Item*> m_inventory;

	Item* GetItem(const std::string& itemName, bool searchInventory, bool searchRoom) const;

public:
	Player(const std::string& name, const std::string& description, Room* currentRoom) :
		Character(name, description), m_currentRoom{ currentRoom }
	{}

	void Look() const;
	void Inventory() const;
	void Move(Room::Direction direction);
	void Examine(const std::string& itemName) const;
	void Pick(const std::string& itemName);
	void Pick(const std::string& itemName, const std::string& itemFromName);
	void Drop(const std::string& itemName);
	void Unlock(const std::string& directionTxt, const std::string& itemName);
	void Use(const std::string& toolItemName, const std::string& itemName);
};
