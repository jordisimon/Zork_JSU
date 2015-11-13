#pragma once

#include "Entity.h"

class Character : public Entity
{
public:
	Character(const std::string& name, const std::string& description) :
		Entity(name, description)
	{

	}
};
