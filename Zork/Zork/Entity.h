#pragma once

#include <string>
#include <vector>
#include "Tools.h"

class Item;

class Entity
{
private:
	std::string m_name;
	std::string m_lowerCaseName; //for comparison purposes
	std::string m_description;

protected:
	std::vector<Item*> m_items; //It can contain items

public:
	Entity(const std::string& name, const std::string& description)
		: m_name{ name }, m_lowerCaseName{ name }, m_description { description }
	{

		ToLowerCase(m_lowerCaseName);
	}

	virtual ~Entity() {}

	const std::string& GetName() const
	{
		return m_name;
	}

	const std::string& GetLowerCaseName() const
	{
		return m_lowerCaseName;
	}

	const std::string& GetDescription() const
	{
		return m_description;
	}

	virtual void Describe() const;

	void AddItem(Item* item);
	Item* GetItem(const std::string& itemName) const;
	Item* RemoveItem(const std::string& itemName);
	void RemoveItem(Item* item);
};