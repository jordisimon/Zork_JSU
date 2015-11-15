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
