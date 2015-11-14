#pragma once

#include <vector>
#include "Entity.h"

class Item : public Entity
{
private:
	bool m_pickable; //Can it be picked from where it is?
	std::vector<Item*> m_items; //It can contain other items

	//Used to transform this item into another one using a transformer item
	Item* m_transformerItem;
	Item* m_resultItem;

public:
	Item(const std::string& name, const std::string& description, bool pickable):
		Entity(name, description), m_pickable {pickable}
	{}

	virtual ~Item() {}

	bool IsPickable() const { return m_pickable; }

	virtual void Describe() const;

	void AddItem(Item* item);
	Item* GetItem(const std::string& itemName) const;
	Item* RemoveItem(const std::string& itemName);

	void AddTransformationItems(Item* transformerItem, Item* resultItem);
	Item* GetTransformedItem(Item* transformerItem);
};
