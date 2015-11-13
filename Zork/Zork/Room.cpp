#include "stdafx.h"
#include <iostream>
#include "Room.h"
#include "Exit.h"
#include "Item.h"

using namespace std;

Room::~Room()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(Directions::Total); ++i)
	{
		if (m_exits[i] != nullptr)
			delete (m_exits[i]);
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

void Room::AddExit(Directions direction, Room * leadsTo, bool locked, Item * unlocksWith, const std::string & lockedMessage)
{
	m_exits[static_cast<unsigned int>(direction)] = new Exit(leadsTo, locked, unlocksWith, lockedMessage);
}

Room* Room::GetRoom(Directions direction) const
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
			m_items.erase(iter);
			return *iter;
		}
	}

	return nullptr;
}
