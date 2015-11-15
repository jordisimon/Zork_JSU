#pragma once

#include <random>
#include "Character.h"

class Dad : public Character
{
private:
	std::random_device rd;     // only used once to initialise (seed) engine

public:
	Dad(const std::string& name, const std::string& description) :
		Character(name, description)
	{}

	virtual ~Dad() {}

	virtual Item* Talk(std::vector<Item*>& items);
};
