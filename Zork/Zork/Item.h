#pragma once

#include <vector>
#include "Entity.h"

class Item : public Entity
{
private:
	bool m_pickable; //Can it be picked from where it is?

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

	void AddTransformationItems(Item* transformerItem, Item* resultItem);
	Item* GetTransformedItem(Item* transformerItem);
};
