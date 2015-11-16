#include "stdafx.h"
#include "Entity.h"
#include "Item.h"

using namespace std;

void Entity::Describe() const
{
	cout << m_name << endl;
	cout << m_description << endl << endl;
}

void Entity::AddItem(Item* item)
{
	m_items.push_back(item);
}

Item* Entity::GetItem(const string& itemName) const
{
	string lcItemName = itemName;
	ToLowerCase(lcItemName);

	for (vector<Item*>::const_iterator iter = m_items.cbegin(); iter != m_items.cend(); ++iter)
	{
		if ((*iter)->GetLowerCaseName() == lcItemName)
		{
			return *iter;
		}
	}

	return nullptr;
}

Item* Entity::RemoveItem(const string& itemName)
{
	string lcItemName = itemName;
	ToLowerCase(lcItemName);

	for (vector<Item*>::iterator iter = m_items.begin(); iter != m_items.end(); ++iter)
	{
		if ((*iter)->GetLowerCaseName() == lcItemName)
		{
			Item* result = *iter;
			m_items.erase(iter);
			return result;
		}
	}

	return nullptr;
}

void Entity::RemoveItem(Item* item)
{
	for (vector<Item*>::iterator iter = m_items.begin(); iter != m_items.end(); ++iter)
	{
		if ((*iter) == item)
		{
			m_items.erase(iter);
			break;
		}
	}
}
