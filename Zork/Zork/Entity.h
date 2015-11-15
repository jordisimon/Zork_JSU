#pragma once

#include <string>
#include <vector>

class Item;

class Entity
{
private:
	std::string m_name;
	std::string m_description;

protected:
	std::vector<Item*> m_items; //It can contain items

public:
	Entity(const std::string& name, const std::string& description)
		: m_name{ name }, m_description{ description }
	{}

	virtual ~Entity() {}

	const std::string& GetName() const
	{
		return m_name;
	}

	const std::string& GetDescription() const
	{
		return m_description;
	}

	virtual void Describe() const;

	void AddItem(Item* item);
	Item* GetItem(const std::string& itemName) const;
	Item* RemoveItem(const std::string& itemName);

};