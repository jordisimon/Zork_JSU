#include "stdafx.h"
#include <sstream>
#include <vector>

#include "Player.h"
#include "Item.h"
#include "Character.h"

using namespace std;

Item* Player::GetItem(const string& itemName, bool searchInventory, bool searchRoom) const
{
	//first we search item in inventory
	if (searchInventory)
	{		
		Item* item = Entity::GetItem(itemName);
		if (item != nullptr)
		{
			return item;
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

void Player::Quit()
{
	m_quit = true;
}

void Player::Look() const
{	
	m_currentRoom->Describe();
}

void Player::Inventory() const
{
	cout << "Lets see what you have:" << endl;

	if (m_items.size() > 0)
	{
		for (auto& item : m_items)
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
			AddItem(item);
			m_currentRoom->RemoveItem(item);
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
				AddItem(item);
				containerItem->RemoveItem(item);
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

void Player::Drop(const string& itemName)
{
	Item* item = RemoveItem(itemName);

	if (item != nullptr)
	{
		m_currentRoom->AddItem(item);
		cout << item->GetName() << " dropped." << endl << endl;
	}
	else
	{
		cout << "Mmm... " << itemName << " is not in your inventory." << endl << endl;
	}
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
				RemoveItem(item);
				cout << "Unlocked!" << endl << endl;
			}
			else
			{
				cout << "Can not unlock this direction with " << itemName << "." << endl << endl;
			}
		}
	}
}

void Player::Use(const string& toolItemName, const string& itemName)
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
				RemoveItem(item);
				AddItem(result);
				cout << "Uooooohhh!!! You got a " << result->GetName() << "!" << endl << endl;
			}
			else
			{
				cout << "It has no effect." << endl << endl;
			}
		}
	}
}

void Player::Talk(const string& characterName)
{
	Character* character = m_currentRoom->GetCharacter(characterName);

	if (character != nullptr)
	{
		Item* item = character->Talk(m_items);
		if (item != nullptr)
		{
			cout << "You get " << item->GetName() << " from " << characterName << "!" << endl << endl;
			AddItem(item);
		}
	}
	else
	{
		cout << "There is no one called " << characterName << " here." << endl << endl;
	}
}
