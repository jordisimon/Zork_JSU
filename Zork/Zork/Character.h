#pragma once

#include "Entity.h"

class Item;

class Character : public Entity
{
public:
	Character(const std::string& name, const std::string& description) :
		Entity(name, description)
	{}

	virtual ~Character() {}

	virtual Item* Talk(std::vector<Item*>& items) = 0;
};
