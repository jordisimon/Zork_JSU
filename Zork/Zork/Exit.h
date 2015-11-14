#pragma once

class Room;
class Item;

class Exit
{
private:
	Room* m_leadsTo;
	bool m_locked;
	Item* m_unlocksWith;
	std::string m_lockedMessage;

public:
	Exit(Room* leadsTo, bool locked, Item* unlocksWith, const std::string& lockedMessage) :
		m_leadsTo{ leadsTo }, m_locked{ locked }, m_unlocksWith{ unlocksWith }, m_lockedMessage{ lockedMessage }
	{}

	bool IsLocked() const { return m_locked; } 
	const std::string& GetLockedMessage() const { return m_lockedMessage; }
	Room* GetDestinationRoom() const { return m_leadsTo; }

	bool UnlockWith(Item* item);
};
