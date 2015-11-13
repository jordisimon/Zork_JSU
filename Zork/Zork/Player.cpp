#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>

#include "Player.h"
#include "Item.h"



using namespace std;


void Player::Look(const vector<string>& commands)
{
	if (commands.size() > 1 && commands[1] == "me")
	{
		Describe();
	}
	else
	{
		m_currentRoom->Describe();
	}
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

void Player::Examine(const std::string& itemName) const
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

bool Player::ParseCommand(const string& playerInput)
{
	vector<string> commands;

	//move sentence to vector
	istringstream command{ playerInput };
	while (command)
	{
		string sub;
		command >> sub;
		if (!sub.empty())
		{
			commands.push_back(sub);
			//cout << "Substring: " << sub << endl;
		}
	}

	if (commands.size() > 0)
	{
		string word = commands[0];

		//Quit
		if (word == "q" || word == "Q" || word == "quit")
		{
			return true;
		}
		//Look
		else if (word == "l" || word == "L" || word == "look")
		{
			Look(commands);
		}
		//Move north
		else if (word == "n" || word == "N" || word == "north")
		{
			Move(Room::Directions::North);
		}
		//Move south
		else if (word == "s" || word == "S" || word == "south")
		{
			Move(Room::Directions::South);
		}
		//Move east
		else if (word == "e" || word == "E" || word == "east")
		{
			Move(Room::Directions::East);
		}
		//Move west
		else if (word == "w" || word == "W" || word == "west")
		{
			Move(Room::Directions::West);
		}
		//Move up
		else if (word == "u" || word == "U" || word == "up")
		{
			Move(Room::Directions::Up);
		}
		//Move down
		else if (word == "d" || word == "D" || word == "down")
		{
			Move(Room::Directions::Down);
		}
		//Examine
		else if (word == "examine")
		{
			if (commands.size() > 1)
			{
				Examine(commands[1]);
			}
			else
			{
				cout << "Examine what?" << endl << endl;
			}
		}
		//Pick
		else if (word == "pick" || word == "take")
		{

		}
		//Non valid command
		else
		{
			cout << "What the hell did you just say? Do you speak my language?" << endl << endl;
		}
	}

	return false;

}
