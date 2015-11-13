#include "stdafx.h"
#include <iostream>
#include "Room.h"
#include "Exit.h"

using namespace std;

Room::~Room()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(Directions::Total); ++i)
	{
		if (m_exits[i] != nullptr)
			delete (m_exits[i]);
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
