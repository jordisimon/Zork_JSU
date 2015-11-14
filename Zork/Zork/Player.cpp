#include "stdafx.h"
#include <sstream>
#include <vector>

#include "Player.h"
#include "Item.h"

using namespace std;

Item * Player::GetItem(const std::string & itemName, bool searchInventory, bool searchRoom) const
{
	if (searchInventory)
	{
		//first we search item in inventory
		for (auto& item : m_inventory)
		{
			if (item->GetName() == itemName)
			{
				return item;
			}
		}
	}

	//if not found, search item in room
	if (searchRoom)
	{
		Item* item = m_currentRoom->GetItem(itemName);
		if (item != nullptr)
		{
			return item;
		}
	}

	cout << "Mmm... I can not find " << itemName << " anywhere." << endl << endl;
	return nullptr;
}

void Player::Look() const
{	
	m_currentRoom->Describe();
}

void Player::Inventory() const
{
	cout << "Lets see what you have:" << endl;

	if (m_inventory.size() > 0)
	{
		for (auto& item : m_inventory)
		{
			cout << item->GetName() << endl;
		}
	} 
	else
	{
		cout << "Nothing!!!" << endl;
	}

	cout << endl;
}

void Player::Move(Room::Direction direction)
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
	Item* item = GetItem(itemName, true, true);

	if (item != nullptr)
	{
		item->Describe();
	}
}

void Player::Pick(const string& itemName)
{
	Item* item = GetItem(itemName, false, true);
	if (item != nullptr)
	{
		if (item->IsPickable())
		{
			m_inventory.push_back(item);
			m_currentRoom->RemoveItem(itemName);
			cout << item->GetName() << " taken." << endl << endl;
		}
		else
		{
			cout << "You can not take the " << itemName << endl << endl;
		}
	}
}

void Player::Pick(const string& itemName, const string& itemFromName)
{
	Item* containerItem = GetItem(itemFromName, true, true);
	if (containerItem != nullptr)
	{
		Item* item = containerItem->GetItem(itemName);
		if (item != nullptr)
		{
			if (item->IsPickable())
			{
				m_inventory.push_back(item);
				containerItem->RemoveItem(itemName);
				cout << item->GetName() << " taken." << endl << endl;
			}
			else
			{
				cout << "You can not take the " << itemName << " from " << itemFromName << "." << endl << endl;
			}
		}
		else
		{
			cout << "Mmm... I can not find " << itemName << " in " << itemFromName << "." << endl << endl;
		}
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

	cout << "Mmm... " << itemName <<" is not in your inventory." << endl << endl;
}

void Player::Unlock(const string& directionTxt, const string& itemName)
{
	//First get the proper direction
	Room::Direction direction = m_currentRoom->GetDirectionFromText(directionTxt);

	if (direction == Room::Direction::Total)
	{
		cout << "You should tell me which direction to unlock." << endl << endl;
	} 
	else
	{
		//Then we get the item 
		Item* item = GetItem(itemName, true, false);
		if (item != nullptr)
		{
			if (m_currentRoom->UnlockDirectionWith(direction, item))
			{
				for (vector<Item*>::iterator iter = m_inventory.begin(); iter != m_inventory.end(); ++iter)
				{
					if ((*iter)->GetName() == itemName)
					{
						m_inventory.erase(iter);
						break;
					}
				}
				cout << "Unlocked!" << endl << endl;
			}
			else
			{
				cout << "Can not unlock this direction with " << itemName << "." << endl << endl;
			}
		}
	}
}

void Player::Use(const string & toolItemName, const string & itemName)
{
	Item* tool = GetItem(toolItemName, true, false);
	if (tool != nullptr)
	{
		Item* item = GetItem(itemName, true, false);
		if (item != nullptr)
		{
			Item* result = item->GetTransformedItem(tool);
			//Check if item changed
			if (result != item)
			{
				for (vector<Item*>::iterator iter = m_inventory.begin(); iter != m_inventory.end(); ++iter)
				{
					if ((*iter)->GetName() == itemName)
					{
						m_inventory.erase(iter);
						break;
					}
				}
				m_inventory.push_back(result);
				cout << "Uooooohhh!!! You got a " << result->GetName() << "!" << endl << endl;
			}
			else
			{
				cout << "It has no effect." << endl << endl;
			}
		}
	}
}
