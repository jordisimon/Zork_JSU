#include "stdafx.h"
#include <vector>
#include "Item.h"

using namespace std;

void Item::Describe() const
{
	Entity::Describe();

	if (m_items.size() > 0)
	{
		cout << "You also can see " << endl;
		for (auto& item : m_items)
		{
			cout << item->GetName() << endl;
		}
		cout << endl;
	}
}

void Item::AddItem(Item * item)
{
	m_items.push_back(item);
}

Item * Item::GetItem(const std::string & itemName) const
{
	for (vector<Item*>::const_iterator iter = m_items.cbegin(); iter != m_items.cend(); ++iter)
	{
		if ((*iter)->GetName() == itemName)
		{
			return *iter;
		}
	}

	return nullptr;
}

Item* Item::RemoveItem(const std::string & itemName)
{
	for (vector<Item*>::iterator iter = m_items.begin(); iter != m_items.end(); ++iter)
	{
		if ((*iter)->GetName() == itemName)
		{
			Item* result = *iter;
			m_items.erase(iter);
			return result;
		}
	}

	return nullptr;
}

void Item::AddTransformationItems(Item * transformerItem, Item * resultItem)
{
	m_transformerItem = transformerItem;
	m_resultItem = resultItem;
}

Item * Item::GetTransformedItem(Item * transformerItem)
{
	if (transformerItem == m_transformerItem)
	{
		return m_resultItem;
	}
	else
	{
		return this;
	}
}
