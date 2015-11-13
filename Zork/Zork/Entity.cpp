#include "stdafx.h"
#include <iostream>
#include "Entity.h"

using namespace std;

void Entity::Describe() const
{
	cout << m_name << endl;
	cout << m_description << endl;
}
