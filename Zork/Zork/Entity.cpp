#include "stdafx.h"
#include "Entity.h"
#include "Item.h"

using namespace std;

void Entity::Describe() const
{
	cout << m_name << endl;
	cout << m_description << endl << endl;
}

void Entity::AddItem(Item * item)
{
	m_items.push_back(item);
}

Item* Entity::GetItem(const string & itemName) const
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

Item* Entity::RemoveItem(const string & itemName)
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
