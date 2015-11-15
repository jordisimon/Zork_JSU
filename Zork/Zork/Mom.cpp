#include "stdafx.h"
#include "Mom.h"
#include "Item.h"

using namespace std; 

void Mom::AddNeeededItem(Item* item)
{
	m_neededItems.push_back(item);
}

const string& Mom::GetMissingItem(vector<Item*> items) const
{
	//for each item needed we search in provided items
	for (auto& neededItem : m_neededItems)
	{
		bool found = false;
		for (auto& item : items)
		{
			if (neededItem == item)
			{
				found = true;
				break;
			}
		}

		if (!found)
			return neededItem->GetName();
	}

	return emptyString;
}

Item* Mom::Talk(vector<Item*>& items)
{
	const string& neededItem = GetMissingItem(items);

	if (neededItem == "") //check for required items
	{
		if (m_items.size() > 0)
		{
			cout << "Ooooh. Look at you!! You look amazing!!!" << endl;
			cout << "Take this and go to get candies." << endl << endl;

			Item* item = m_items[0];
			RemoveItem(item->GetName());
			return item;
		}
		else
		{
			cout << "Are you still here? Your friends won't wait forever. Go and have fun!" << endl << endl;
		}
	}
	else
	{
		cout << "Oh honey, you are not ready yet. Go and find some stuff to disguise." << endl;
		cout << "Maybe you should get a " << neededItem << "." << endl << endl;
	}

	return nullptr;
}
