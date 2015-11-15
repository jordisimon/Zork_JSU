#include "stdafx.h"
#include "Dad.h"
#include "Item.h"

using namespace std;

Item* Dad::Talk(std::vector<Item*>& items)
{
	if (m_items.size() > 0)
	{
		cout << "Hi son! How are you doing tonight?" << endl;
		cout << "Take this, it can be useful at some point." << endl << endl;
		Item* item = m_items[0];
		RemoveItem(item->GetName());
		return item;
	}
	else
	{
		mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		uniform_int_distribution<int> uni(0, 3); // guaranteed unbiased

		int option = uni(rng);

		switch (option)
		{
		case 0:
			cout << "Go and have fun, son.";
			break;

		case 1:
			cout << "Are you still here?";
			break;

		case 2:
			cout << "How are you doing tonight?";
			break;

		case 3:
			cout << "Hey son. Did you play Jork?" << endl;
			cout << "It's a supercool game!";
			break;
		}
		cout << endl << endl;
		return nullptr;
	}
	
}
