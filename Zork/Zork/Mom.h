#pragma once

#include "Character.h"

class Mom : public Character
{
private:
	std::string emptyString;
	std::vector<Item*> m_neededItems;

	const std::string& GetMissingItem(std::vector<Item*> items) const;

public:
	Mom(const std::string& name, const std::string& description) :
		Character(name, description), emptyString { "" }
	{}

	virtual ~Mom() {}

	void AddNeeededItem(Item* item);
	
	virtual Item* Talk(std::vector<Item*>& items);
};
