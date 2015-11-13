#include "stdafx.h"
#include <sstream>
#include <vector>

#include "Player.h"
#include "Item.h"

using namespace std;

void Player::Look() const
{	
	m_currentRoom->Describe();
}

void Player::Move(Room::Directions direction)
{
	Room* nextRoom = m_currentRoom->GetRoom(direction);

	if (nextRoom != nullptr)
	{
		m_currentRoom = nextRoom;
		m_currentRoom->Describe();
	}
}

void Player::Examine(const string& itemName) const
{
	bool found = false;
	//first we search item in inventory
	for (auto& item : m_inventory)
	{
		if (item->GetName() == itemName)
		{
			cout << item->GetDescription() << endl << endl;
			found = true;
		}
	}
	//if not found, search item in room
	if (!found)
	{
		Item* item = m_currentRoom->GetItem(itemName);
		if (item != nullptr)
		{
			cout << item->GetDescription() << endl << endl;
			found = true;
		}
	}

	if (!found)
	{
		cout << "Mmm... I can not find any item with this name." << endl << endl;
	}
}

void Player::Pick(const string & itemName)
{
	Item* item = m_currentRoom->RemoveItem(itemName);
	if (item != nullptr)
	{
		m_inventory.push_back(item);
		cout << item->GetName() << " taken." << endl << endl;
	}
	else
	{
		cout << "Mmm... I can not find any item with this name." << endl << endl;
	}
}

void Player::Drop(const string & itemName)
{
	for (vector<Item*>::iterator iter = m_inventory.begin(); iter != m_inventory.end(); ++iter)
	{
		if ((*iter)->GetName() == itemName)
		{
			Item* item = (*iter);
			m_currentRoom->AddItem(item);
			m_inventory.erase(iter);
			cout << item->GetName() << " dropped." << endl << endl;
			return;
		}
	}

	cout << "Mmm... I can not find any item with this name." << endl << endl;
}
