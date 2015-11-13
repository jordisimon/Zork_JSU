#include "stdafx.h"
#include <sstream>
#include <vector>
#include "Player.h"

#include <iostream>

using namespace std;

bool Player::ParseCommand(const string& playerInput)
{
	vector<string> commands;

	//move sentence to vector
	istringstream command{ playerInput };
	while (command)
	{
		string sub;
		command >> sub;
		if (!sub.empty())
		{
			commands.push_back(sub);
			//cout << "Substring: " << sub << endl;
		}
	}

	if (commands.size() > 0)
	{
		string word = commands[0];

		if (word == "q" || word == "Q" || word == "quit")
		{
			return true;
		}
	}

	return false;

}
