#pragma once
#include <array>
#include <vector>
#include "Entity.h"

class Exit;
class Item;

class Room : public Entity
{
public:
	enum class Directions
	{
		North = 0,
		East,
		South,
		West,
		Up,
		Down,
		Total
	};
private:
	std::array < Exit*, static_cast<size_t>(Directions::Total) > m_exits;
	std::vector <Item*> m_items;

public:
	Room(const std::string& name, const std::string& description) : 
		Entity(name, description)
	{
		for (unsigned int i = 0; i < static_cast<unsigned int>(Directions::Total); ++i)
		{
			m_exits[i] = nullptr;
		}
	}

	virtual ~Room();

	virtual void Describe() const;

	void AddExit(Directions direction, Room* leadsTo, bool locked, Item* unlocksWith, const std::string& lockedMessage);
	Room* GetRoom(Directions direction) const;

	void AddItem(Item* item);
	Item* GetItem(const std::string& itemName) const;
	Item* RemoveItem(const std::string& itemName);
};
