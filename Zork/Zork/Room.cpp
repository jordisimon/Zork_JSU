#include "stdafx.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"

using namespace std;

Room::~Room()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(Direction::Total); ++i)
	{
		if (m_exits[i] != nullptr)
			delete (m_exits[i]);
	}
}

Room::Direction Room::GetDirectionFromText(const std::string& text)
{
	if		(text == "n" || text == "N" || text == "north")
		return Direction::North;
	else if (text == "s" || text == "S" || text == "south")
		return Direction::South;
	else if (text == "e" || text == "E" || text == "east")
		return Direction::East;
	else if (text == "w" || text == "W" || text == "west")
		return Direction::West;
	else if (text == "u" || text == "U" || text == "up")
		return Direction::Up;
	else if (text == "d" || text == "D" || text == "down")
		return Direction::Down;
	else
		return Direction::Total;
}

const std::string Room::GetTextFromDirection(Direction direction)
{
	switch (direction)
	{
	case Direction::North:
		return "north";
		break;

	case Direction::South:
		return "south";
		break;

	case Direction::East:
		return "east";
		break;

	case Direction::West:
		return "west";
		break;

	case Direction::Up:
		return "up";
		break;

	case Direction::Down:
		return "down";
		break;

	default:
		return "unknown";
	}
}

void Room::Describe() const
{
	Entity::Describe();

	if (m_items.size() > 0)
	{
		cout << "You also can see " << endl;
		for (auto& item : m_items)
		{
			cout << item->GetName() << endl;
		}
		cout << endl;
	}
}

void Room::AddExit(Direction direction, Room * leadsTo, bool locked, Item * unlocksWith, const std::string & lockedMessage)
{
	m_exits[static_cast<unsigned int>(direction)] = new Exit(leadsTo, locked, unlocksWith, lockedMessage);
}

Room* Room::GetRoom(Direction direction) const
{
	Exit* exit = m_exits[static_cast<unsigned int>(direction)];

	if (exit == nullptr)
	{
		cout << "There is no exit in this direction." << endl << endl;
	} 
	else if (exit->IsLocked())
	{
		cout << exit->GetLockedMessage() << endl << endl;
	}
	else
	{
		return exit->GetDestinationRoom();
	}

	return nullptr;
}

void Room::AddItem(Item * item)
{
	m_items.push_back(item);
}

Item * Room::GetItem(const std::string & itemName) const
{
	for (vector<Item*>::const_iterator iter = m_items.cbegin(); iter != m_items.cend(); ++iter)
	{
		if ((*iter)->GetName() == itemName)
		{
			return *iter;
		}
	}

	return nullptr;
}

Item* Room::RemoveItem(const std::string & itemName)
{
	for (vector<Item*>::iterator iter = m_items.begin(); iter != m_items.end(); ++iter)
	{
		if ((*iter)->GetName() == itemName)
		{
			Item* result = *iter;
			m_items.erase(iter);
			return result;
		}
	}

	return nullptr;
}

bool Room::UnlockDirectionWith(Direction direction, Item * item)
{
	if (m_exits[static_cast<unsigned int>(direction)] != nullptr)
	{
		return m_exits[static_cast<unsigned int>(direction)]->UnlockWith(item);
	}
	else 
		return false;
}
