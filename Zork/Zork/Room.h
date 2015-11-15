#pragma once
#include <array>
#include <vector>
#include "Entity.h"

class Exit;
class Item;
class Character;

class Room : public Entity
{
public:
	enum class Direction
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
	std::array < Exit*, static_cast<size_t>(Direction::Total) > m_exits;
	std::vector<Character*> m_characters;

public:
	Room(const std::string& name, const std::string& description) : 
		Entity(name, description)
	{
		for (unsigned int i = 0; i < static_cast<unsigned int>(Direction::Total); ++i)
		{
			m_exits[i] = nullptr;
		}
	}

	virtual ~Room();

	static Direction GetDirectionFromText(const std::string& text);
	static const std::string GetTextFromDirection(Direction direction);

	virtual void Describe() const;

	void AddExit(Direction direction, Room* leadsTo, bool locked, Item* unlocksWith, const std::string& lockedMessage);
	Room* GetRoom(Direction direction) const;
	bool UnlockDirectionWith(Direction direction, Item* item);

	void AddCharacter(Character* character);
	Character* GetCharacter(const std::string& characterName) const;
};
