#include "stdafx.h"
#include <sstream>
#include "Player.h"

#include <iostream>

using namespace std;

void Player::ParseCommand(const string& playerInput)
{
	istringstream command{ playerInput };
	while (command)
	{
		string sub;
		command >> sub;
		cout << "Substring: " << sub << endl;

	}
}
