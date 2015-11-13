#pragma once

#include <vector>
#include "Entity.h"

class Item : public Entity
{
private:
	bool m_pickable; //Can it be picked from where it is?
	bool m_equipable;
	std::vector<Item*> m_items; //It can contain other items

public:
	Item(const std::string& name, const std::string& description, bool pickable, bool equipable):
		Entity(name, description), m_pickable {pickable}, m_equipable{equipable}
	{}

	virtual ~Item() {}
};
