#pragma once

#include <vector>
#include "Entity.h"
#include "Room.h"

class Player : public Entity
{
private:
	bool m_quit;
	Room* m_currentRoom;

	Item* GetItem(const std::string& itemName, bool searchInventory, bool searchRoom) const;

public:
	Player(const std::string& name, const std::string& description, Room* currentRoom) :
		Entity(name, description), m_currentRoom{ currentRoom }, m_quit { false }
	{}

	virtual ~Player() {}

	bool GetPlayerQuit() const { return m_quit; }
	Room* GetCurrentRoom() const { return m_currentRoom; }

	void Quit();
	void Look() const;
	void Inventory() const;
	void Move(Room::Direction direction);
	void Examine(const std::string& itemName) const;
	void Pick(const std::string& itemName);
	void Pick(const std::string& itemName, const std::string& itemFromName);
	void Drop(const std::string& itemName);
	void Unlock(const std::string& directionTxt, const std::string& itemName);
	void Use(const std::string& toolItemName, const std::string& itemName);
	void Talk(const std::string& characterName);
};
